# Battery Management System (BMS) Algorithm - UKF SOC/SOH Estimator

This repository contains the generated C code for a sophisticated battery State of Charge (SOC) and State of Health (SOH) estimation algorithm. The algorithm was designed and verified using MATLAB® and Simulink® and was converted to C code using Embedded Coder®.

The core of this project is an **Unscented Kalman Filter (UKF)** that implements an adaptive coulomb counting algorithm. It uses Open Circuit Voltage (OCV) measurements during rest periods to correct for state of charge (SOC) drift and dynamically tune the battery's capacity estimate for state of health (SOH).

---

## 🚀 Features

* **State of Charge (SOC) Estimation:** A UKF-based approach combining coulomb counting for dynamic tracking and OCV-based correction for long-term accuracy.  
* **State of Health (SOH) Estimation:** Implements an adaptive feedback control method to estimate capacity fade over the battery's life.  
* **Event-Driven Logic:** Uses a robust Stateflow state machine that ensures correction and SOH logic is executed exactly once per relaxation event.  
* **Embedded-Ready:** Generates clean, portable C code designed to be integrated into a microcontroller-based BMS.

---

## 📁 Generated C-Code Files

The following files are essential for the algorithm's operation and must be included in your embedded project.

| File Name | Description |
| :-- | :-- |
| **`BMS.c`** | **Core Algorithm Logic:** Contains the primary C functions, including `BMS_initialize()` and the main step function `BMS_step()`. |
| **`BMS.h`** | **Main Header File:** The public interface to the algorithm. Your `main.c` must `#include` this file to call the functions and access the I/O data structures. |
| **`BMS_data.c`** | **Parameters and Constants:** Contains the definitions of model parameters, most notably the large 2-D lookup table for OCV-SOC mapping. |
| **`BMS_types.h`** | **Model-Specific Types:** Defines data structures and types that are specific to the `BMS` model. |
| **`rtwtypes.h`** | **Simulink Standard Types:** Defines the standard data types used by all generated code (e.g., `real32_T`, `int8_T`). |
| **`rt_nonfinite.c`** | **Utility Functions:** Helper functions to safely handle special floating-point numbers like infinity and NaN. |
| **`rt_nonfinite.h`** | Header for the non-finite utility functions. |
| **`Example_use.c`** | **Usage Example:** An auto-generated `main` function that serves as a template. **Do not compile this file into your final project.** Use it as a reference. |

---

## 🛠️ How to Use the C-Code

Integrating the generated code into your microcontroller project involves the following steps.

### Step 1: Include Files in Your Project

Copy all the `.c` and `.h` files listed above into your embedded IDE's project folder and add them to the build source.

---

### Step 2: Include the Header in Your `main.c`

In your main application file (`main.c`), include the main header for the BMS algorithm.

```c
#include "BMS.h" // Main header for the generated algorithm
```

---

### Step 3: Define Data Structures

The model's inputs and outputs are accessed through global structures defined in BMS.h.
You will need to declare them in your main.c.

```c
// Declare the input, output, and other necessary model structures
// These are defined in BMS.h
extern RT_MODEL_BMS_T *const BMS_M;
extern ExtU_BMS_T BMS_U;  // Input structure
extern ExtY_BMS_T BMS_Y;  // Output structure
```
---

### Step 4: One-Time Initialization

In your main() function, after setting up your microcontroller hardware, call the model’s one-time initialization function.

```c
int main(void) {
    // 1. Initialize microcontroller hardware (ADC, Timers, etc.)
    HAL_Init();
    SystemClock_Config();
    ADC_Init();
    Timer_Init();

    // 2. Initialize the BMS algorithm's states
    BMS_initialize();

    // 3. Start the periodic timer that will call the step function
    // ...

    while (1) {
        // Main loop can handle lower-priority tasks
    }
}
```

---

### Step 5: Periodic Execution (Timer Interrupt)

The BMS_step() function must be called at a fixed rate that matches the sample time set in the original Simulink model (only 10 Hz or every 100 ms).
The best way to do this is with a hardware timer interrupt.

```c
// This is your periodic timer's Interrupt Service Routine (ISR)
void Timer_ISR(void) {

    // 1. Read Sensor Data from Hardware
    float current_A = read_current_from_ADC();
    float voltage_V = read_voltage_from_ADC();
    float temperature_K = read_temperature_from_sensor();

    // 2. Populate the Model's Input Structure
    // The names (e.g., 'Current', 'Voltage') must match the
    // Inport block names in your original Simulink model.
    BMS_U.Current = current_A;
    BMS_U.Voltage = voltage_V;
    BMS_U.Temperature = temperature_K;

    // 3. Execute one step of the BMS algorithm
    BMS_step();

    // 4. Read the Results from the Model's Output Structure
    float estimated_soc = BMS_Y.Est_SOC;
    float estimated_soh = BMS_Y.SOH;

    // 5. Use the results (e.g., update a display, send a CAN message, etc.)
    update_fuel_gauge(estimated_soc);
    log_soh_value(estimated_soh);
}
```
---

### Step 6: Compile and Deploy

Use your target’s toolchain (e.g., CrossCore Embedded Studio, Keil, IAR) to compile your entire project, including your main.c and all the provided BMS source files.
This will generate the final executable to be flashed onto your microcontroller.
