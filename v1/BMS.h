/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BMS.h
 *
 * Code generated for Simulink model 'BMS'.
 *
 * Model version                  : 16.8
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Tue Oct  7 20:50:14 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef BMS_h_
#define BMS_h_
#ifndef BMS_COMMON_INCLUDES_
#define BMS_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* BMS_COMMON_INCLUDES_ */

#include "BMS_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals for system '<S18>/State function' */
typedef struct {
  real_T Probe[2];                     /* '<S30>/Probe' */
} B_CoreSubsys_BMS_f_T;

/* Block states (default storage) for system '<S18>/State function' */
typedef struct {
  uint32_T m_bpIndex[2];               /* '<S30>/R1' */
  uint32_T m_bpIndex_a[2];             /* '<S30>/C1' */
} DW_CoreSubsys_BMS_o_T;

/* Block states (default storage) for system '<S18>/Measurement function' */
typedef struct {
  uint32_T m_bpIndex[2];               /* '<S28>/OCV Table' */
} DW_CoreSubsys_BMS_oa_T;

/* Block signals for system '<S1>/SOC Estimator (Adaptive Kalman Filter)' */
typedef struct {
  real_T Assignment2[21];              /* '<S19>/Assignment2' */
  real_T ImpAsg_InsertedFor_xk1_at_inpor[21];/* '<S24>/State function' */
  B_CoreSubsys_BMS_f_T CoreSubsys[7];  /* '<S18>/State function' */
} B_CoreSubsys_BMS_T;

/* Block states (default storage) for system '<S1>/SOC Estimator (Adaptive Kalman Filter)' */
typedef struct {
  real_T Delay_DSTATE[3];              /* '<S17>/Delay' */
  real_T UnitDelayP_DSTATE[9];         /* '<S15>/Unit Delay - P' */
  boolean_T icLoad;                    /* '<S17>/Delay' */
  DW_CoreSubsys_BMS_oa_T CoreSubsys_i[7];/* '<S18>/Measurement function' */
  DW_CoreSubsys_BMS_o_T CoreSubsys[7]; /* '<S18>/State function' */
} DW_CoreSubsys_BMS_T;

/* Block signals for system '<Root>/BMS Algorithm' */
typedef struct {
  B_CoreSubsys_BMS_T CoreSubsys[1];
                             /* '<S1>/SOC Estimator (Adaptive Kalman Filter)' */
} B_BMSAlgorithm_BMS_T;

/* Block states (default storage) for system '<Root>/BMS Algorithm' */
typedef struct {
  DW_CoreSubsys_BMS_T CoreSubsys[1];
                             /* '<S1>/SOC Estimator (Adaptive Kalman Filter)' */
} DW_BMSAlgorithm_BMS_T;

/* Block signals (default storage) */
typedef struct {
  B_BMSAlgorithm_BMS_T BMSAlgorithm;   /* '<Root>/BMS Algorithm' */
} B_BMS_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  DW_BMSAlgorithm_BMS_T BMSAlgorithm;  /* '<Root>/BMS Algorithm' */
} DW_BMS_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: Wc)
   * Referenced by:
   *   '<S18>/updatePx'
   *   '<S18>/updatePy'
   */
  real_T pooled1[7];

  /* Expression: Q
   * Referenced by: '<S18>/updatePx'
   */
  real_T updatePx_Q[9];

  /* Pooled Parameter (Expression: Wm)
   * Referenced by:
   *   '<S23>/Constant'
   *   '<S24>/Constant'
   */
  real_T pooled2[7];

  /* Expression: R1_mat
   * Referenced by: '<S30>/R1'
   */
  real_T R1_tableData[707];

  /* Expression: SOC_vec
   * Referenced by: '<S30>/R1'
   */
  real_T R1_bp01Data[101];

  /* Expression: T_vec
   * Referenced by: '<S30>/R1'
   */
  real_T R1_bp02Data[7];

  /* Expression: C1_mat
   * Referenced by: '<S30>/C1'
   */
  real_T C1_tableData[707];

  /* Expression: SOC_vec
   * Referenced by: '<S30>/C1'
   */
  real_T C1_bp01Data[101];

  /* Expression: T_vec
   * Referenced by: '<S30>/C1'
   */
  real_T C1_bp02Data[7];

  /* Expression: V0_mat
   * Referenced by: '<S28>/OCV Table'
   */
  real_T OCVTable_tableData[707];

  /* Expression: SOC_vec
   * Referenced by: '<S28>/OCV Table'
   */
  real_T OCVTable_bp01Data[101];

  /* Expression: T_vec
   * Referenced by: '<S28>/OCV Table'
   */
  real_T OCVTable_bp02Data[7];

  /* Expression: diag(Wc)
   * Referenced by: '<S18>/Constant'
   */
  real_T Constant_Value[49];

  /* Expression: chol(P0,'lower')
   * Referenced by: '<S15>/Unit Delay - P'
   */
  real_T UnitDelayP_InitialCondition[9];

  /* Expression: R0_EOL_mat
   * Referenced by: '<S3>/2-D Lookup Table R0 EOL'
   */
  real_T uDLookupTableR0EOL_tableData[707];

  /* Expression: SOC_vec
   * Referenced by: '<S3>/2-D Lookup Table R0 EOL'
   */
  real_T uDLookupTableR0EOL_bp01Data[101];

  /* Expression: T_vec
   * Referenced by: '<S3>/2-D Lookup Table R0 EOL'
   */
  real_T uDLookupTableR0EOL_bp02Data[7];

  /* Expression: R0_new_mat
   * Referenced by: '<S3>/2-D Lookup Table R0 new'
   */
  real_T uDLookupTableR0new_tableData[707];

  /* Expression: SOC_vec
   * Referenced by: '<S3>/2-D Lookup Table R0 new'
   */
  real_T uDLookupTableR0new_bp01Data[101];

  /* Expression: T_vec
   * Referenced by: '<S3>/2-D Lookup Table R0 new'
   */
  real_T uDLookupTableR0new_bp02Data[7];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S3>/2-D Lookup Table R0 EOL'
   *   '<S3>/2-D Lookup Table R0 new'
   *   '<S28>/OCV Table'
   *   '<S30>/C1'
   *   '<S30>/R1'
   */
  uint32_T pooled5[2];
} ConstP_BMS_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Current_A;                    /* '<Root>/Current_A' */
  real_T Voltage_V;                    /* '<Root>/Voltage_V' */
  real_T Temperature_K;                /* '<Root>/Temperature_K' */
  real_T Initial_SOC_pct;              /* '<Root>/Initial_SOC_pct' */
  real_T Initial_R0_ohm;               /* '<Root>/Initial_R0_ohm' */
} ExtU_BMS_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Est_SOC_pct;                  /* '<Root>/Est_SOC_pct' */
  real_T Est_SOH_pct;                  /* '<Root>/Est_SOH_pct' */
  real_T Est_R0_ohm;                   /* '<Root>/Est_R0_ohm' */
} ExtY_BMS_T;

/* Real-time Model Data Structure */
struct tag_RTM_BMS_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_BMS_T BMS_B;

/* Block states (default storage) */
extern DW_BMS_T BMS_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_BMS_T BMS_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_BMS_T BMS_Y;

/* Constant parameters (default storage) */
extern const ConstP_BMS_T BMS_ConstP;

/* Model entry point functions */
extern void BMS_initialize(void);
extern void BMS_step(void);
extern void BMS_terminate(void);

/* Real-time Model object */
extern RT_MODEL_BMS_T *const BMS_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S21>/Data Type Duplicate' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate' : Unused code path elimination
 * Block '<S27>/Data Type Duplicate' : Unused code path elimination
 * Block '<S29>/Data Type Duplicate' : Unused code path elimination
 * Block '<S31>/Data Type Duplicate' : Unused code path elimination
 * Block '<S32>/Data Type Duplicate' : Unused code path elimination
 * Block '<S33>/Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/Conversion' : Eliminate redundant data type conversion
 * Block '<S22>/Conversion' : Eliminate redundant data type conversion
 * Block '<S27>/Conversion' : Eliminate redundant data type conversion
 * Block '<S29>/Conversion' : Eliminate redundant data type conversion
 * Block '<S31>/Conversion' : Eliminate redundant data type conversion
 * Block '<S15>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S15>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S15>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<S15>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<S15>/Rate Transition4' : Eliminated since input and output rates are identical
 * Block '<S15>/Reshape' : Reshape block reduction
 * Block '<S32>/Conversion' : Eliminate redundant data type conversion
 * Block '<S33>/Conversion' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('BatterySOHEstimation_KalmanFilter/BMS Algorithm')    - opens subsystem BatterySOHEstimation_KalmanFilter/BMS Algorithm
 * hilite_system('BatterySOHEstimation_KalmanFilter/BMS Algorithm/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'BatterySOHEstimation_KalmanFilter'
 * '<S1>'   : 'BatterySOHEstimation_KalmanFilter/BMS Algorithm'
 * '<S2>'   : 'BatterySOHEstimation_KalmanFilter/BMS Algorithm/SOC Estimator (Adaptive Kalman Filter)'
 * '<S3>'   : 'BatterySOHEstimation_KalmanFilter/BMS Algorithm/SOH Estimator'
 * '<S4>'   : 'BatterySOHEstimation_KalmanFilter/BMS Algorithm/SOC Estimator (Adaptive Kalman Filter)/Data type'
 * '<S5>'   : 'BatterySOHEstimation_KalmanFilter/BMS Algorithm/SOC Estimator (Adaptive Kalman Filter)/Data type1'
 * '<S6>'   : 'BatterySOHEstimation_KalmanFilter/BMS Algorithm/SOC Estimator (Adaptive Kalman Filter)/Data type2'
 * '<S7>'   : 'BatterySOHEstimation_KalmanFilter/BMS Algorithm/SOC Estimator (Adaptive Kalman Filter)/Data type3'
 * '<S8>'   : 'BatterySOHEstimation_KalmanFilter/BMS Algorithm/SOC Estimator (Adaptive Kalman Filter)/Data type4'
 * '<S9>'   : 'BatterySOHEstimation_KalmanFilter/BMS Algorithm/SOC Estimator (Adaptive Kalman Filter)/Kalman Filter'
 * '<S10>'  : 'BatterySOHEstimation_KalmanFilter/BMS Algorithm/SOC Estimator (Adaptive Kalman Filter)/Data type/Inherit DT'
 * '<S11>'  : 'BatterySOHEstimation_KalmanFilter/BMS Algorithm/SOC Estimator (Adaptive Kalman Filter)/Data type1/Inherit DT'
 * '<S12>'  : 'BatterySOHEstimation_KalmanFilter/BMS Algorithm/SOC Estimator (Adaptive Kalman Filter)/Data type2/Inherit DT'
 * '<S13>'  : 'BatterySOHEstimation_KalmanFilter/BMS Algorithm/SOC Estimator (Adaptive Kalman Filter)/Data type3/Inherit DT'
 * '<S14>'  : 'BatterySOHEstimation_KalmanFilter/BMS Algorithm/SOC Estimator (Adaptive Kalman Filter)/Data type4/Inherit DT'
 * '<S15>'  : 'BatterySOHEstimation_KalmanFilter/BMS Algorithm/SOC Estimator (Adaptive Kalman Filter)/Kalman Filter/UKF'
 * '<S16>'  : 'BatterySOHEstimation_KalmanFilter/BMS Algorithm/SOC Estimator (Adaptive Kalman Filter)/Kalman Filter/UKF/Correction'
 * '<S17>'  : 'BatterySOHEstimation_KalmanFilter/BMS Algorithm/SOC Estimator (Adaptive Kalman Filter)/Kalman Filter/UKF/Delay - X'
 * '<S18>'  : 'BatterySOHEstimation_KalmanFilter/BMS Algorithm/SOC Estimator (Adaptive Kalman Filter)/Kalman Filter/UKF/Prediction'
 * '<S19>'  : 'BatterySOHEstimation_KalmanFilter/BMS Algorithm/SOC Estimator (Adaptive Kalman Filter)/Kalman Filter/UKF/Sigma points'
 * '<S20>'  : 'BatterySOHEstimation_KalmanFilter/BMS Algorithm/SOC Estimator (Adaptive Kalman Filter)/Kalman Filter/UKF/Correction/updatePk'
 * '<S21>'  : 'BatterySOHEstimation_KalmanFilter/BMS Algorithm/SOC Estimator (Adaptive Kalman Filter)/Kalman Filter/UKF/Delay - X/Data Type Conversion Inherited'
 * '<S22>'  : 'BatterySOHEstimation_KalmanFilter/BMS Algorithm/SOC Estimator (Adaptive Kalman Filter)/Kalman Filter/UKF/Prediction/Data Type Conversion Inherited'
 * '<S23>'  : 'BatterySOHEstimation_KalmanFilter/BMS Algorithm/SOC Estimator (Adaptive Kalman Filter)/Kalman Filter/UKF/Prediction/Measurement function'
 * '<S24>'  : 'BatterySOHEstimation_KalmanFilter/BMS Algorithm/SOC Estimator (Adaptive Kalman Filter)/Kalman Filter/UKF/Prediction/State function'
 * '<S25>'  : 'BatterySOHEstimation_KalmanFilter/BMS Algorithm/SOC Estimator (Adaptive Kalman Filter)/Kalman Filter/UKF/Prediction/updatePx'
 * '<S26>'  : 'BatterySOHEstimation_KalmanFilter/BMS Algorithm/SOC Estimator (Adaptive Kalman Filter)/Kalman Filter/UKF/Prediction/updatePy'
 * '<S27>'  : 'BatterySOHEstimation_KalmanFilter/BMS Algorithm/SOC Estimator (Adaptive Kalman Filter)/Kalman Filter/UKF/Prediction/Measurement function/Data Type Conversion Inherited'
 * '<S28>'  : 'BatterySOHEstimation_KalmanFilter/BMS Algorithm/SOC Estimator (Adaptive Kalman Filter)/Kalman Filter/UKF/Prediction/Measurement function/Measurement function'
 * '<S29>'  : 'BatterySOHEstimation_KalmanFilter/BMS Algorithm/SOC Estimator (Adaptive Kalman Filter)/Kalman Filter/UKF/Prediction/State function/Data Type Conversion Inherited'
 * '<S30>'  : 'BatterySOHEstimation_KalmanFilter/BMS Algorithm/SOC Estimator (Adaptive Kalman Filter)/Kalman Filter/UKF/Prediction/State function/State function'
 * '<S31>'  : 'BatterySOHEstimation_KalmanFilter/BMS Algorithm/SOC Estimator (Adaptive Kalman Filter)/Kalman Filter/UKF/Prediction/State function/State function/Data Type Conversion Inherited'
 * '<S32>'  : 'BatterySOHEstimation_KalmanFilter/BMS Algorithm/SOC Estimator (Adaptive Kalman Filter)/Kalman Filter/UKF/Sigma points/Data Type Conversion Inherited'
 * '<S33>'  : 'BatterySOHEstimation_KalmanFilter/BMS Algorithm/SOC Estimator (Adaptive Kalman Filter)/Kalman Filter/UKF/Sigma points/Data Type Conversion Inherited1'
 * '<S34>'  : 'BatterySOHEstimation_KalmanFilter/BMS Algorithm/SOH Estimator/Data type'
 * '<S35>'  : 'BatterySOHEstimation_KalmanFilter/BMS Algorithm/SOH Estimator/Data type1'
 * '<S36>'  : 'BatterySOHEstimation_KalmanFilter/BMS Algorithm/SOH Estimator/Data type2'
 * '<S37>'  : 'BatterySOHEstimation_KalmanFilter/BMS Algorithm/SOH Estimator/Data type/Inherit DT'
 * '<S38>'  : 'BatterySOHEstimation_KalmanFilter/BMS Algorithm/SOH Estimator/Data type1/Inherit DT'
 * '<S39>'  : 'BatterySOHEstimation_KalmanFilter/BMS Algorithm/SOH Estimator/Data type2/Inherit DT'
 */
#endif                                 /* BMS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
