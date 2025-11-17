/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BMS.c
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

#include "BMS.h"
#include "rtwtypes.h"
#include "BMS_private.h"
#include <string.h>
#include <math.h>
#include <emmintrin.h>
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_BMS_T BMS_B;

/* Block states (default storage) */
DW_BMS_T BMS_DW;

/* External inputs (root inport signals with default storage) */
ExtU_BMS_T BMS_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_BMS_T BMS_Y;

/* Real-time model */
static RT_MODEL_BMS_T BMS_M_;
RT_MODEL_BMS_T *const BMS_M = &BMS_M_;

/* Forward declaration for local functions */
static real_T BMS_xnrm2_n(int32_T n, const real_T x[27], int32_T ix0);
static void BMS_xgemv(int32_T m, int32_T n, const real_T A[27], int32_T ia0,
                      const real_T x[27], int32_T ix0, real_T y[3]);
static void BMS_xgerc(int32_T m, int32_T n, real_T alpha1, int32_T ix0, const
                      real_T y[3], real_T A[27], int32_T ia0);
static void BMS_qr(const real_T A[27], real_T b_Q[27], real_T R[9]);
static void BMS_rotate(real_T x, real_T y, real_T *c, real_T *s, real_T *r);
static real_T BMS_xnrm2(int32_T n, const real_T x[7], int32_T ix0);
real_T look2_binlxpw(real_T u0, real_T u1, const real_T bp0[], const real_T bp1[],
                     const real_T table[], const uint32_T maxIndex[], uint32_T
                     stride)
{
  real_T fractions[2];
  real_T frac;
  real_T yL_0d0;
  real_T yL_0d1;
  uint32_T bpIndices[2];
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 2-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex[0U]]) {
    /* Binary Search */
    bpIdx = maxIndex[0U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[0U];
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex[0U] - 1U;
    frac = (u0 - bp0[maxIndex[0U] - 1U]) / (bp0[maxIndex[0U]] - bp0[maxIndex[0U]
      - 1U]);
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u1 <= bp1[0U]) {
    iLeft = 0U;
    frac = (u1 - bp1[0U]) / (bp1[1U] - bp1[0U]);
  } else if (u1 < bp1[maxIndex[1U]]) {
    /* Binary Search */
    bpIdx = maxIndex[1U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[1U];
    while (iRght - iLeft > 1U) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u1 - bp1[iLeft]) / (bp1[iLeft + 1U] - bp1[iLeft]);
  } else {
    iLeft = maxIndex[1U] - 1U;
    frac = (u1 - bp1[maxIndex[1U] - 1U]) / (bp1[maxIndex[1U]] - bp1[maxIndex[1U]
      - 1U]);
  }

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  bpIdx = iLeft * stride + bpIndices[0U];
  yL_0d0 = table[bpIdx];
  yL_0d0 += (table[bpIdx + 1U] - yL_0d0) * fractions[0U];
  bpIdx += stride;
  yL_0d1 = table[bpIdx];
  return (((table[bpIdx + 1U] - yL_0d1) * fractions[0U] + yL_0d1) - yL_0d0) *
    frac + yL_0d0;
}

real_T look2_pbinlcpw(real_T u0, real_T u1, const real_T bp0[], const real_T
                      bp1[], const real_T table[], uint32_T prevIndex[], const
                      uint32_T maxIndex[], uint32_T stride)
{
  real_T fractions[2];
  real_T frac;
  real_T yL_0d0;
  real_T yL_0d1;
  uint32_T bpIndices[2];
  uint32_T bpIdx;
  uint32_T found;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 2-D
     Search method: 'binary'
     Use previous index: 'on'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    bpIdx = 0U;
    frac = 0.0;
  } else if (u0 < bp0[maxIndex[0U]]) {
    /* Binary Search using Previous Index */
    bpIdx = prevIndex[0U];
    iLeft = 0U;
    iRght = maxIndex[0U];
    found = 0U;
    while (found == 0U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx - 1U;
        bpIdx = ((bpIdx + iLeft) - 1U) >> 1U;
      } else if (u0 < bp0[bpIdx + 1U]) {
        found = 1U;
      } else {
        iLeft = bpIdx + 1U;
        bpIdx = ((bpIdx + iRght) + 1U) >> 1U;
      }
    }

    frac = (u0 - bp0[bpIdx]) / (bp0[bpIdx + 1U] - bp0[bpIdx]);
  } else {
    bpIdx = maxIndex[0U] - 1U;
    frac = 1.0;
  }

  prevIndex[0U] = bpIdx;
  fractions[0U] = frac;
  bpIndices[0U] = bpIdx;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u1 <= bp1[0U]) {
    bpIdx = 0U;
    frac = 0.0;
  } else if (u1 < bp1[maxIndex[1U]]) {
    /* Binary Search using Previous Index */
    bpIdx = prevIndex[1U];
    iLeft = 0U;
    iRght = maxIndex[1U];
    found = 0U;
    while (found == 0U) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx - 1U;
        bpIdx = ((bpIdx + iLeft) - 1U) >> 1U;
      } else if (u1 < bp1[bpIdx + 1U]) {
        found = 1U;
      } else {
        iLeft = bpIdx + 1U;
        bpIdx = ((bpIdx + iRght) + 1U) >> 1U;
      }
    }

    frac = (u1 - bp1[bpIdx]) / (bp1[bpIdx + 1U] - bp1[bpIdx]);
  } else {
    bpIdx = maxIndex[1U] - 1U;
    frac = 1.0;
  }

  prevIndex[1U] = bpIdx;

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  iLeft = bpIdx * stride + bpIndices[0U];
  yL_0d0 = table[iLeft];
  yL_0d0 += (table[iLeft + 1U] - yL_0d0) * fractions[0U];
  iLeft += stride;
  yL_0d1 = table[iLeft];
  return (((table[iLeft + 1U] - yL_0d1) * fractions[0U] + yL_0d1) - yL_0d0) *
    frac + yL_0d0;
}

int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator)
{
  return (((numerator < 0) != (denominator < 0)) && (numerator % denominator !=
           0) ? -1 : 0) + numerator / denominator;
}

/* Function for MATLAB Function: '<S18>/updatePx' */
static real_T BMS_xnrm2_n(int32_T n, const real_T x[27], int32_T ix0)
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  int32_T k;
  int32_T kend;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      scale = 3.3121686421112381E-170;
      kend = ix0 + n;
      for (k = ix0; k < kend; k++) {
        absxk = fabs(x[k - 1]);
        if (absxk > scale) {
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T a;
  real_T b;
  real_T y;
  a = fabs(u0);
  b = fabs(u1);
  if (a < b) {
    a /= b;
    y = sqrt(a * a + 1.0) * b;
  } else if (a > b) {
    b /= a;
    y = sqrt(b * b + 1.0) * a;
  } else if (rtIsNaN(b)) {
    y = (rtNaN);
  } else {
    y = a * 1.4142135623730951;
  }

  return y;
}

/* Function for MATLAB Function: '<S18>/updatePx' */
static void BMS_xgemv(int32_T m, int32_T n, const real_T A[27], int32_T ia0,
                      const real_T x[27], int32_T ix0, real_T y[3])
{
  real_T c;
  int32_T b;
  int32_T b_iy;
  int32_T d;
  int32_T ia;
  if ((m != 0) && (n != 0)) {
    if (n - 1 >= 0) {
      memset(&y[0], 0, (uint32_T)n * sizeof(real_T));
    }

    b = (n - 1) * 9 + ia0;
    for (b_iy = ia0; b_iy <= b; b_iy += 9) {
      c = 0.0;
      d = b_iy + m;
      for (ia = b_iy; ia < d; ia++) {
        c += x[((ix0 + ia) - b_iy) - 1] * A[ia - 1];
      }

      ia = div_nde_s32_floor(b_iy - ia0, 9);
      y[ia] += c;
    }
  }
}

/* Function for MATLAB Function: '<S18>/updatePx' */
static void BMS_xgerc(int32_T m, int32_T n, real_T alpha1, int32_T ix0, const
                      real_T y[3], real_T A[27], int32_T ia0)
{
  real_T temp;
  int32_T b;
  int32_T ijA;
  int32_T j;
  int32_T jA;
  if (!(alpha1 == 0.0)) {
    jA = ia0;
    for (j = 0; j < n; j++) {
      temp = y[j];
      if (temp != 0.0) {
        temp *= alpha1;
        b = m + jA;
        for (ijA = jA; ijA < b; ijA++) {
          A[ijA - 1] += A[((ix0 + ijA) - jA) - 1] * temp;
        }
      }

      jA += 9;
    }
  }
}

/* Function for MATLAB Function: '<S18>/updatePx' */
static void BMS_qr(const real_T A[27], real_T b_Q[27], real_T R[9])
{
  __m128d tmp;
  real_T b_A[27];
  real_T tau[3];
  real_T work[3];
  real_T atmp;
  real_T b_A_0;
  real_T xnorm;
  int32_T b_coltop;
  int32_T b_lastv;
  int32_T c_k;
  int32_T c_lastc;
  int32_T d_i;
  int32_T d_k;
  int32_T exitg1;
  int32_T ii;
  int32_T knt;
  boolean_T exitg2;
  memcpy(&b_A[0], &A[0], 27U * sizeof(real_T));
  work[0] = 0.0;
  work[1] = 0.0;
  work[2] = 0.0;
  for (d_i = 0; d_i < 3; d_i++) {
    ii = d_i * 9 + d_i;
    atmp = b_A[ii];
    b_coltop = ii + 2;
    tau[d_i] = 0.0;
    xnorm = BMS_xnrm2_n(8 - d_i, b_A, ii + 2);
    if (xnorm != 0.0) {
      b_A_0 = b_A[ii];
      xnorm = rt_hypotd_snf(b_A_0, xnorm);
      if (b_A_0 >= 0.0) {
        xnorm = -xnorm;
      }

      if (fabs(xnorm) < 1.0020841800044864E-292) {
        knt = 0;
        d_k = (ii - d_i) + 9;
        do {
          knt++;
          b_lastv = (((((d_k - ii) - 1) / 2) << 1) + ii) + 2;
          c_lastc = b_lastv - 2;
          for (c_k = b_coltop; c_k <= c_lastc; c_k += 2) {
            tmp = _mm_loadu_pd(&b_A[c_k - 1]);
            _mm_storeu_pd(&b_A[c_k - 1], _mm_mul_pd(tmp, _mm_set1_pd
              (9.9792015476736E+291)));
          }

          for (c_k = b_lastv; c_k <= d_k; c_k++) {
            b_A[c_k - 1] *= 9.9792015476736E+291;
          }

          xnorm *= 9.9792015476736E+291;
          atmp *= 9.9792015476736E+291;
        } while ((fabs(xnorm) < 1.0020841800044864E-292) && (knt < 20));

        xnorm = rt_hypotd_snf(atmp, BMS_xnrm2_n(8 - d_i, b_A, ii + 2));
        if (atmp >= 0.0) {
          xnorm = -xnorm;
        }

        tau[d_i] = (xnorm - atmp) / xnorm;
        atmp = 1.0 / (atmp - xnorm);
        c_lastc = b_lastv - 2;
        for (c_k = b_coltop; c_k <= c_lastc; c_k += 2) {
          tmp = _mm_loadu_pd(&b_A[c_k - 1]);
          _mm_storeu_pd(&b_A[c_k - 1], _mm_mul_pd(tmp, _mm_set1_pd(atmp)));
        }

        for (c_k = b_lastv; c_k <= d_k; c_k++) {
          b_A[c_k - 1] *= atmp;
        }

        for (b_lastv = 0; b_lastv < knt; b_lastv++) {
          xnorm *= 1.0020841800044864E-292;
        }

        atmp = xnorm;
      } else {
        tau[d_i] = (xnorm - b_A_0) / xnorm;
        atmp = 1.0 / (b_A_0 - xnorm);
        knt = (ii - d_i) + 9;
        b_lastv = (((((knt - ii) - 1) / 2) << 1) + ii) + 2;
        c_lastc = b_lastv - 2;
        for (d_k = b_coltop; d_k <= c_lastc; d_k += 2) {
          tmp = _mm_loadu_pd(&b_A[d_k - 1]);
          _mm_storeu_pd(&b_A[d_k - 1], _mm_mul_pd(tmp, _mm_set1_pd(atmp)));
        }

        for (d_k = b_lastv; d_k <= knt; d_k++) {
          b_A[d_k - 1] *= atmp;
        }

        atmp = xnorm;
      }
    }

    b_A[ii] = atmp;
    if (d_i + 1 < 3) {
      b_A[ii] = 1.0;
      if (tau[d_i] != 0.0) {
        b_lastv = 9 - d_i;
        c_lastc = (ii - d_i) + 8;
        while ((b_lastv > 0) && (b_A[c_lastc] == 0.0)) {
          b_lastv--;
          c_lastc--;
        }

        c_lastc = 2 - d_i;
        exitg2 = false;
        while ((!exitg2) && (c_lastc > 0)) {
          b_coltop = ((c_lastc - 1) * 9 + ii) + 9;
          knt = b_coltop;
          do {
            exitg1 = 0;
            if (knt + 1 <= b_coltop + b_lastv) {
              if (b_A[knt] != 0.0) {
                exitg1 = 1;
              } else {
                knt++;
              }
            } else {
              c_lastc--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        b_lastv = 0;
        c_lastc = 0;
      }

      if (b_lastv > 0) {
        BMS_xgemv(b_lastv, c_lastc, b_A, ii + 10, b_A, ii + 1, work);
        BMS_xgerc(b_lastv, c_lastc, -tau[d_i], ii + 1, work, b_A, ii + 10);
      }

      b_A[ii] = atmp;
    }
  }

  for (d_i = 0; d_i < 3; d_i++) {
    for (ii = 0; ii <= d_i; ii++) {
      R[ii + 3 * d_i] = b_A[9 * d_i + ii];
    }

    for (ii = d_i + 2; ii < 4; ii++) {
      R[(ii + 3 * d_i) - 1] = 0.0;
    }

    work[d_i] = 0.0;
  }

  for (d_i = 2; d_i >= 0; d_i--) {
    ii = d_i * 9 + d_i;
    if (d_i + 1 < 3) {
      b_A[ii] = 1.0;
      if (tau[d_i] != 0.0) {
        b_lastv = 9 - d_i;
        c_lastc = (ii - d_i) + 8;
        while ((b_lastv > 0) && (b_A[c_lastc] == 0.0)) {
          b_lastv--;
          c_lastc--;
        }

        c_lastc = 2 - d_i;
        exitg2 = false;
        while ((!exitg2) && (c_lastc > 0)) {
          b_coltop = ((c_lastc - 1) * 9 + ii) + 9;
          knt = b_coltop;
          do {
            exitg1 = 0;
            if (knt + 1 <= b_coltop + b_lastv) {
              if (b_A[knt] != 0.0) {
                exitg1 = 1;
              } else {
                knt++;
              }
            } else {
              c_lastc--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        b_lastv = 0;
        c_lastc = 0;
      }

      if (b_lastv > 0) {
        BMS_xgemv(b_lastv, c_lastc, b_A, ii + 10, b_A, ii + 1, work);
        BMS_xgerc(b_lastv, c_lastc, -tau[d_i], ii + 1, work, b_A, ii + 10);
      }
    }

    b_coltop = (ii - d_i) + 9;
    b_lastv = (((((b_coltop - ii) - 1) / 2) << 1) + ii) + 2;
    c_lastc = b_lastv - 2;
    for (knt = ii + 2; knt <= c_lastc; knt += 2) {
      tmp = _mm_loadu_pd(&b_A[knt - 1]);
      _mm_storeu_pd(&b_A[knt - 1], _mm_mul_pd(tmp, _mm_set1_pd(-tau[d_i])));
    }

    for (knt = b_lastv; knt <= b_coltop; knt++) {
      b_A[knt - 1] *= -tau[d_i];
    }

    b_A[ii] = 1.0 - tau[d_i];
    for (b_lastv = 0; b_lastv < d_i; b_lastv++) {
      b_A[(ii - b_lastv) - 1] = 0.0;
    }
  }

  for (d_i = 0; d_i < 9; d_i++) {
    b_Q[d_i] = b_A[d_i];
    b_Q[d_i + 9] = b_A[d_i + 9];
    b_Q[d_i + 18] = b_A[d_i + 18];
  }
}

/* Function for MATLAB Function: '<S18>/updatePy' */
static void BMS_rotate(real_T x, real_T y, real_T *c, real_T *s, real_T *r)
{
  real_T absx;
  real_T absy;
  real_T rho;
  real_T xx;
  real_T yy;
  absx = fabs(x);
  absy = fabs(y);
  if (absy == 0.0) {
    *c = 1.0;
    *s = 0.0;
    *r = x;
  } else if (absx == 0.0) {
    *c = 0.0;
    *s = 1.0;
    *r = y;
  } else {
    absy += absx;
    xx = x / absy;
    yy = y / absy;
    absx = fabs(xx);
    rho = rt_hypotd_snf(absx, fabs(yy));
    *c = absx / rho;
    xx /= absx;
    *s = xx * yy / rho;
    *r = rho * absy * xx;
  }
}

/* Function for MATLAB Function: '<S18>/updatePy' */
static real_T BMS_xnrm2(int32_T n, const real_T x[7], int32_T ix0)
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  int32_T k;
  int32_T kend;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      scale = 3.3121686421112381E-170;
      kend = ix0 + n;
      for (k = ix0; k < kend; k++) {
        absxk = fabs(x[k - 1]);
        if (absxk > scale) {
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

/* System initialize for atomic system: '<Root>/BMS Algorithm' */
void BMS_BMSAlgorithm_Init(B_BMSAlgorithm_BMS_T *localB, DW_BMSAlgorithm_BMS_T
  *localDW)
{
  int32_T ForEach_itr_l;

  /* SystemInitialize for Iterator SubSystem: '<S1>/SOC Estimator (Adaptive Kalman Filter)' */
  /* InitializeConditions for Delay: '<S17>/Delay' */
  localDW->CoreSubsys[0].icLoad = true;

  /* InitializeConditions for UnitDelay: '<S15>/Unit Delay - P' */
  memcpy(&localDW->CoreSubsys[0].UnitDelayP_DSTATE[0],
         &BMS_ConstP.UnitDelayP_InitialCondition[0], 9U * sizeof(real_T));

  /* SystemInitialize for Iterator SubSystem: '<S18>/State function' */
  for (ForEach_itr_l = 0; ForEach_itr_l < 7; ForEach_itr_l++) {
    /* Start for Probe: '<S30>/Probe' */
    localB->CoreSubsys[0].CoreSubsys[ForEach_itr_l].Probe[0] = 0.1;
    localB->CoreSubsys[0].CoreSubsys[ForEach_itr_l].Probe[1] = 0.0;
  }

  /* End of SystemInitialize for SubSystem: '<S18>/State function' */
  /* End of SystemInitialize for SubSystem: '<S1>/SOC Estimator (Adaptive Kalman Filter)' */
}

/* Output and update for atomic system: '<Root>/BMS Algorithm' */
void BMS_BMSAlgorithm(real_T rtu_Current_A, real_T rtu_Voltage_V, real_T
                      rtu_Temperature_K, real_T rtu_Initial_SOC_pct, real_T
                      rtu_Initial_R0_ohm, real_T *rty_Est_SOC_pct, real_T
                      *rty_Est_SOH_pct, real_T *rty_Est_R0_ohm,
                      B_BMSAlgorithm_BMS_T *localB, DW_BMSAlgorithm_BMS_T
                      *localDW)
{
  __m128d tmp_1;
  real_T b[49];
  real_T a__1[27];
  real_T residual_1[27];
  real_T residual[21];
  real_T rtb_ImpAsg_InsertedFor_Wm_ixk1_[21];
  real_T rtb_Gain_j[9];
  real_T rtb_MathFunction[9];
  real_T residual_0[7];
  real_T rtb_ImpAsg_InsertedFor_y_at_inp[7];
  real_T rtb_Y1[7];
  real_T b_c[3];
  real_T rtb_Add[3];
  real_T rtb_Kk1_e[3];
  real_T rtb_Product5[3];
  real_T s[3];
  real_T x[3];
  real_T tmp[2];
  real_T tmp_0[2];
  real_T absxk;
  real_T rtb_C1;
  real_T rtb_X1_0;
  real_T rtb_uDLookupTableR0EOL;
  real_T scale;
  real_T t;
  int32_T Assignment2_tmp;
  int32_T i;
  int32_T iAcol;
  int32_T knt;
  boolean_T errorCondition;

  /* Outputs for Iterator SubSystem: '<S1>/SOC Estimator (Adaptive Kalman Filter)' incorporates:
   *  ForEach: '<S2>/For Each'
   */
  /* Delay: '<S17>/Delay' incorporates:
   *  Constant: '<S17>/Constant1'
   *  ForEachSliceSelector generated from: '<S2>/InitialSOC'
   *  Reshape: '<S17>/Reshape'
   */
  if (localDW->CoreSubsys[0].icLoad) {
    localDW->CoreSubsys[0].Delay_DSTATE[0] = rtu_Initial_SOC_pct;
    localDW->CoreSubsys[0].Delay_DSTATE[1] = 0.0;
    localDW->CoreSubsys[0].Delay_DSTATE[2] = rtu_Initial_R0_ohm;
  }

  /* Product: '<S19>/Matrix Multiply' incorporates:
   *  Delay: '<S17>/Delay'
   *  Math: '<S18>/Math Function'
   */
  for (knt = 0; knt < 3; knt++) {
    rtb_MathFunction[3 * knt] = localDW->CoreSubsys[0].Delay_DSTATE[0];
    rtb_MathFunction[3 * knt + 1] = localDW->CoreSubsys[0].Delay_DSTATE[1];
    rtb_MathFunction[3 * knt + 2] = localDW->CoreSubsys[0].Delay_DSTATE[2];
  }

  /* End of Product: '<S19>/Matrix Multiply' */

  /* Gain: '<S19>/Gain' incorporates:
   *  UnitDelay: '<S15>/Unit Delay - P'
   */
  for (i = 0; i < 9; i++) {
    rtb_Gain_j[i] = 1.7320508075688772 * localDW->CoreSubsys[0].
      UnitDelayP_DSTATE[i];
  }

  /* End of Gain: '<S19>/Gain' */

  /* Assignment: '<S19>/Assignment2' incorporates:
   *  Assignment: '<S19>/Assignment'
   */
  memset(&localB->CoreSubsys[0].Assignment2[0], 0, 21U * sizeof(real_T));
  for (knt = 0; knt < 3; knt++) {
    /* Assignment: '<S19>/Assignment' incorporates:
     *  Assignment: '<S19>/Assignment2'
     *  Delay: '<S17>/Delay'
     */
    localB->CoreSubsys[0].Assignment2[knt] = localDW->CoreSubsys[0]
      .Delay_DSTATE[knt];

    /* Sum: '<S19>/Sum' incorporates:
     *  Gain: '<S19>/Gain'
     *  Math: '<S18>/Math Function'
     */
    rtb_uDLookupTableR0EOL = rtb_MathFunction[3 * knt];
    rtb_C1 = rtb_Gain_j[3 * knt];

    /* Assignment: '<S19>/Assignment1' incorporates:
     *  Assignment: '<S19>/Assignment2'
     *  Sum: '<S19>/Sum'
     */
    i = (knt + 1) * 3;
    localB->CoreSubsys[0].Assignment2[i] = rtb_uDLookupTableR0EOL + rtb_C1;

    /* Assignment: '<S19>/Assignment2' incorporates:
     *  Sum: '<S19>/Sum1'
     */
    Assignment2_tmp = (knt + 4) * 3;
    localB->CoreSubsys[0].Assignment2[Assignment2_tmp] = rtb_uDLookupTableR0EOL
      - rtb_C1;

    /* Sum: '<S19>/Sum' incorporates:
     *  Gain: '<S19>/Gain'
     *  Math: '<S18>/Math Function'
     */
    iAcol = 3 * knt + 1;
    rtb_uDLookupTableR0EOL = rtb_MathFunction[iAcol];
    rtb_C1 = rtb_Gain_j[iAcol];

    /* Assignment: '<S19>/Assignment1' incorporates:
     *  Assignment: '<S19>/Assignment2'
     *  Sum: '<S19>/Sum'
     */
    localB->CoreSubsys[0].Assignment2[i + 1] = rtb_uDLookupTableR0EOL + rtb_C1;

    /* Assignment: '<S19>/Assignment2' incorporates:
     *  Sum: '<S19>/Sum1'
     */
    localB->CoreSubsys[0].Assignment2[Assignment2_tmp + 1] =
      rtb_uDLookupTableR0EOL - rtb_C1;

    /* Sum: '<S19>/Sum' incorporates:
     *  Gain: '<S19>/Gain'
     *  Math: '<S18>/Math Function'
     */
    iAcol = 3 * knt + 2;
    rtb_uDLookupTableR0EOL = rtb_MathFunction[iAcol];
    rtb_C1 = rtb_Gain_j[iAcol];

    /* Assignment: '<S19>/Assignment1' incorporates:
     *  Assignment: '<S19>/Assignment2'
     *  Sum: '<S19>/Sum'
     */
    localB->CoreSubsys[0].Assignment2[i + 2] = rtb_uDLookupTableR0EOL + rtb_C1;

    /* Assignment: '<S19>/Assignment2' incorporates:
     *  Sum: '<S19>/Sum1'
     */
    localB->CoreSubsys[0].Assignment2[Assignment2_tmp + 2] =
      rtb_uDLookupTableR0EOL - rtb_C1;
  }

  /* Outputs for Iterator SubSystem: '<S18>/State function' incorporates:
   *  ForEach: '<S24>/For Each'
   */
  for (knt = 0; knt < 7; knt++) {
    /* ForEachSliceSelector generated from: '<S24>/X' incorporates:
     *  Assignment: '<S19>/Assignment2'
     *  Lookup_n-D: '<S30>/C1'
     *  Lookup_n-D: '<S30>/R1'
     */
    scale = localB->CoreSubsys[0].Assignment2[3 * knt];

    /* Lookup_n-D: '<S30>/R1' incorporates:
     *  ForEachSliceSelector generated from: '<S24>/X'
     */
    rtb_uDLookupTableR0EOL = look2_pbinlcpw(scale, rtu_Temperature_K,
      BMS_ConstP.R1_bp01Data, BMS_ConstP.R1_bp02Data, BMS_ConstP.R1_tableData,
      localDW->CoreSubsys[0].CoreSubsys[knt].m_bpIndex, BMS_ConstP.pooled5, 101U);

    /* Lookup_n-D: '<S30>/C1' incorporates:
     *  ForEachSliceSelector generated from: '<S2>/CellTemperature'
     */
    rtb_C1 = look2_pbinlcpw(scale, rtu_Temperature_K, BMS_ConstP.C1_bp01Data,
      BMS_ConstP.C1_bp02Data, BMS_ConstP.C1_tableData, localDW->CoreSubsys[0].
      CoreSubsys[knt].m_bpIndex_a, BMS_ConstP.pooled5, 101U);

    /* Selector: '<S24>/Selector' incorporates:
     *  Constant: '<S24>/Constant'
     */
    t = BMS_ConstP.pooled2[knt];

    /* Sum: '<S30>/Add' incorporates:
     *  Gain: '<S2>/Gain'
     *  Gain: '<S30>/Gain'
     *  Product: '<S30>/Product'
     */
    scale += (real32_T)(-1.916779564983044E-6 * -rtu_Current_A *
                        localB->CoreSubsys[0].CoreSubsys[knt].Probe[0]);

    /* ForEachSliceAssignment generated from: '<S24>/Wm_i*xk1_i' incorporates:
     *  Product: '<S24>/Product'
     *  Sum: '<S30>/Add'
     */
    rtb_ImpAsg_InsertedFor_Wm_ixk1_[3 * knt] = t * scale;

    /* ForEachSliceAssignment generated from: '<S24>/xk1' incorporates:
     *  Sum: '<S30>/Add'
     */
    localB->CoreSubsys[0].ImpAsg_InsertedFor_xk1_at_inpor[3 * knt] = scale;

    /* Sum: '<S30>/Add' incorporates:
     *  Assignment: '<S19>/Assignment2'
     *  ForEachSliceSelector generated from: '<S24>/X'
     *  Gain: '<S2>/Gain'
     *  Product: '<S30>/Divide1'
     *  Product: '<S30>/Divide2'
     *  Product: '<S30>/Product'
     *  Product: '<S30>/Product1'
     *  Sum: '<S30>/Add1'
     */
    i = 3 * knt + 1;
    scale = localB->CoreSubsys[0].Assignment2[i];
    scale += (real32_T)((-rtu_Current_A / rtb_C1 - scale /
                         (rtb_uDLookupTableR0EOL * rtb_C1)) * localB->
                        CoreSubsys[0].CoreSubsys[knt].Probe[0]);

    /* ForEachSliceAssignment generated from: '<S24>/Wm_i*xk1_i' incorporates:
     *  Product: '<S24>/Product'
     *  Sum: '<S30>/Add'
     */
    rtb_ImpAsg_InsertedFor_Wm_ixk1_[i] = t * scale;

    /* ForEachSliceAssignment generated from: '<S24>/xk1' incorporates:
     *  Sum: '<S30>/Add'
     */
    localB->CoreSubsys[0].ImpAsg_InsertedFor_xk1_at_inpor[i] = scale;

    /* ForEachSliceSelector generated from: '<S24>/X' incorporates:
     *  Sum: '<S30>/Add'
     */
    i = 3 * knt + 2;

    /* Sum: '<S30>/Add' incorporates:
     *  Assignment: '<S19>/Assignment2'
     *  Constant: '<S30>/Constant1'
     *  ForEachSliceSelector generated from: '<S24>/X'
     *  Product: '<S30>/Product'
     */
    scale = 0.0 * localB->CoreSubsys[0].CoreSubsys[knt].Probe[0] +
      localB->CoreSubsys[0].Assignment2[i];

    /* ForEachSliceAssignment generated from: '<S24>/Wm_i*xk1_i' incorporates:
     *  Product: '<S24>/Product'
     *  Sum: '<S30>/Add'
     */
    rtb_ImpAsg_InsertedFor_Wm_ixk1_[i] = t * scale;

    /* ForEachSliceAssignment generated from: '<S24>/xk1' incorporates:
     *  Sum: '<S30>/Add'
     */
    localB->CoreSubsys[0].ImpAsg_InsertedFor_xk1_at_inpor[i] = scale;
  }

  /* End of Outputs for SubSystem: '<S18>/State function' */

  /* Sum: '<S18>/Sum of Elements' incorporates:
   *  ForEachSliceAssignment generated from: '<S24>/Wm_i*xk1_i'
   *  MATLAB Function: '<S18>/updatePx'
   */
  for (knt = 0; knt < 3; knt++) {
    t = -0.0;
    for (i = 0; i < 7; i++) {
      t += rtb_ImpAsg_InsertedFor_Wm_ixk1_[i * 3 + knt];
    }

    rtb_Add[knt] = t;
  }

  scale = rtb_Add[0];
  rtb_uDLookupTableR0EOL = rtb_Add[1];
  t = rtb_Add[2];

  /* MATLAB Function: '<S18>/updatePx' incorporates:
   *  ForEachSliceAssignment generated from: '<S24>/xk1'
   *  Sum: '<S18>/Sum of Elements'
   */
  for (i = 0; i < 7; i++) {
    rtb_ImpAsg_InsertedFor_Wm_ixk1_[3 * i] = localB->CoreSubsys[0].
      ImpAsg_InsertedFor_xk1_at_inpor[3 * i] - scale;
    knt = 3 * i + 1;
    rtb_ImpAsg_InsertedFor_Wm_ixk1_[knt] = localB->CoreSubsys[0].
      ImpAsg_InsertedFor_xk1_at_inpor[knt] - rtb_uDLookupTableR0EOL;
    knt = 3 * i + 2;
    rtb_ImpAsg_InsertedFor_Wm_ixk1_[knt] = localB->CoreSubsys[0].
      ImpAsg_InsertedFor_xk1_at_inpor[knt] - t;
    rtb_Y1[i] = sqrt(fabs(BMS_ConstP.pooled1[i]));
  }

  memset(&b[0], 0, 49U * sizeof(real_T));
  for (knt = 0; knt < 7; knt++) {
    b[knt + 7 * knt] = rtb_Y1[knt];
    residual[3 * knt] = 0.0;
    residual[3 * knt + 1] = 0.0;
    residual[3 * knt + 2] = 0.0;
  }

  for (knt = 0; knt < 7; knt++) {
    rtb_C1 = residual[3 * knt];
    Assignment2_tmp = 3 * knt + 1;
    rtb_uDLookupTableR0EOL = residual[Assignment2_tmp];
    iAcol = 3 * knt + 2;
    scale = residual[iAcol];
    for (i = 0; i < 7; i++) {
      t = b[7 * knt + i];
      tmp_1 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd
        (&rtb_ImpAsg_InsertedFor_Wm_ixk1_[3 * i]), _mm_set1_pd(t)), _mm_set_pd
                         (rtb_uDLookupTableR0EOL, rtb_C1));
      _mm_storeu_pd(&tmp_0[0], tmp_1);
      rtb_C1 = tmp_0[0];
      rtb_uDLookupTableR0EOL = tmp_0[1];
      scale += rtb_ImpAsg_InsertedFor_Wm_ixk1_[3 * i + 2] * t;
    }

    residual[iAcol] = scale;
    residual[Assignment2_tmp] = rtb_uDLookupTableR0EOL;
    residual[3 * knt] = rtb_C1;
  }

  for (knt = 0; knt < 3; knt++) {
    for (i = 0; i < 6; i++) {
      residual_1[i + 9 * knt] = residual[(i + 1) * 3 + knt];
    }

    residual_1[9 * knt + 6] = BMS_ConstP.updatePx_Q[knt];
    residual_1[9 * knt + 7] = BMS_ConstP.updatePx_Q[knt + 3];
    residual_1[9 * knt + 8] = BMS_ConstP.updatePx_Q[knt + 6];
  }

  BMS_qr(residual_1, a__1, rtb_Gain_j);
  for (knt = 0; knt < 3; knt++) {
    if ((2 - knt) - 1 >= 0) {
      memset(&rtb_Gain_j[(knt << 2) + 1], 0, (uint32_T)(2 - knt) * sizeof(real_T));
    }

    b_c[knt] = 0.0;
    s[knt] = 0.0;
  }

  BMS_rotate(rtb_Gain_j[0], residual[0], &b_c[0], &s[0], &rtb_Gain_j[0]);
  for (i = 0; i < 2; i++) {
    t = residual[i + 1];
    for (knt = 0; knt <= i; knt++) {
      scale = s[knt];
      rtb_uDLookupTableR0EOL = scale * t;
      absxk = b_c[knt];
      iAcol = (i + 1) * 3 + knt;
      rtb_C1 = rtb_Gain_j[iAcol];
      t = absxk * t - scale * rtb_C1;
      rtb_Gain_j[iAcol] = absxk * rtb_C1 + rtb_uDLookupTableR0EOL;
    }

    BMS_rotate(rtb_Gain_j[(i + 3 * (i + 1)) + 1], t, &b_c[i + 1], &s[i + 1],
               &rtb_Gain_j[(i + 3 * (i + 1)) + 1]);
  }

  /* Outputs for Iterator SubSystem: '<S18>/Measurement function' incorporates:
   *  ForEach: '<S23>/For Each'
   */
  for (i = 0; i < 7; i++) {
    /* Lookup_n-D: '<S28>/OCV Table' incorporates:
     *  ForEachSliceAssignment generated from: '<S24>/xk1'
     *  ForEachSliceSelector generated from: '<S23>/X'
     */
    rtb_uDLookupTableR0EOL = look2_pbinlcpw(localB->CoreSubsys[0].
      ImpAsg_InsertedFor_xk1_at_inpor[3 * i], rtu_Temperature_K,
      BMS_ConstP.OCVTable_bp01Data, BMS_ConstP.OCVTable_bp02Data,
      BMS_ConstP.OCVTable_tableData, localDW->CoreSubsys[0].CoreSubsys_i[i].
      m_bpIndex, BMS_ConstP.pooled5, 101U);

    /* Sum: '<S28>/Add2' incorporates:
     *  ForEachSliceAssignment generated from: '<S24>/xk1'
     *  ForEachSliceSelector generated from: '<S23>/X'
     *  Gain: '<S2>/Gain'
     *  Product: '<S28>/Product2'
     */
    rtb_uDLookupTableR0EOL = (rtb_uDLookupTableR0EOL - localB->CoreSubsys[0].
      ImpAsg_InsertedFor_xk1_at_inpor[3 * i + 2] * -rtu_Current_A) -
      localB->CoreSubsys[0].ImpAsg_InsertedFor_xk1_at_inpor[3 * i + 1];

    /* ForEachSliceAssignment generated from: '<S23>/Wm_i*y_i' incorporates:
     *  Constant: '<S23>/Constant'
     *  Product: '<S23>/Product'
     *  Selector: '<S23>/Selector'
     */
    rtb_Y1[i] = BMS_ConstP.pooled2[i] * rtb_uDLookupTableR0EOL;

    /* ForEachSliceAssignment generated from: '<S23>/y' */
    rtb_ImpAsg_InsertedFor_y_at_inp[i] = rtb_uDLookupTableR0EOL;
  }

  /* End of Outputs for SubSystem: '<S18>/Measurement function' */

  /* Sum: '<S18>/Sum of Elements1' incorporates:
   *  ForEachSliceAssignment generated from: '<S23>/Wm_i*y_i'
   */
  rtb_uDLookupTableR0EOL = -0.0;
  for (knt = 0; knt < 7; knt++) {
    rtb_uDLookupTableR0EOL += rtb_Y1[knt];
  }

  /* MATLAB Function: '<S18>/updatePy' incorporates:
   *  ForEachSliceAssignment generated from: '<S23>/y'
   *  MATLAB Function: '<S18>/updatePx'
   *  Sum: '<S18>/Sum of Elements1'
   */
  for (i = 0; i <= 4; i += 2) {
    tmp_1 = _mm_loadu_pd(&rtb_ImpAsg_InsertedFor_y_at_inp[i]);
    _mm_storeu_pd(&rtb_Y1[i], _mm_sub_pd(tmp_1, _mm_set1_pd
      (rtb_uDLookupTableR0EOL)));
    tmp[0] = fabs(BMS_ConstP.pooled1[i]);
    tmp[1] = fabs(BMS_ConstP.pooled1[i + 1]);
    tmp_1 = _mm_loadu_pd(&tmp[0]);
    _mm_storeu_pd(&residual_0[i], _mm_sqrt_pd(tmp_1));
  }

  for (i = 6; i < 7; i++) {
    rtb_Y1[i] = rtb_ImpAsg_InsertedFor_y_at_inp[i] - rtb_uDLookupTableR0EOL;
    residual_0[i] = sqrt(fabs(BMS_ConstP.pooled1[i]));
  }

  memset(&b[0], 0, 49U * sizeof(real_T));
  for (knt = 0; knt < 7; knt++) {
    b[knt + 7 * knt] = residual_0[knt];
    residual_0[knt] = 0.0;
  }

  for (knt = 0; knt < 7; knt++) {
    rtb_C1 = residual_0[knt];
    for (i = 0; i < 7; i++) {
      rtb_C1 += b[7 * knt + i] * rtb_Y1[i];
    }

    residual_0[knt] = rtb_C1;
  }

  for (knt = 0; knt < 6; knt++) {
    rtb_ImpAsg_InsertedFor_y_at_inp[knt] = residual_0[knt + 1];
  }

  rtb_ImpAsg_InsertedFor_y_at_inp[6] = 0.05;
  t = rtb_ImpAsg_InsertedFor_y_at_inp[0];
  rtb_C1 = BMS_xnrm2(6, rtb_ImpAsg_InsertedFor_y_at_inp, 2);
  if (rtb_C1 != 0.0) {
    rtb_C1 = rt_hypotd_snf(rtb_ImpAsg_InsertedFor_y_at_inp[0], rtb_C1);
    if (rtb_ImpAsg_InsertedFor_y_at_inp[0] >= 0.0) {
      rtb_C1 = -rtb_C1;
    }

    if (fabs(rtb_C1) < 1.0020841800044864E-292) {
      knt = 0;
      do {
        knt++;
        for (i = 0; i <= 4; i += 2) {
          tmp_1 = _mm_loadu_pd(&rtb_ImpAsg_InsertedFor_y_at_inp[i + 1]);
          _mm_storeu_pd(&rtb_ImpAsg_InsertedFor_y_at_inp[i + 1], _mm_mul_pd
                        (tmp_1, _mm_set1_pd(9.9792015476736E+291)));
        }

        rtb_C1 *= 9.9792015476736E+291;
        t *= 9.9792015476736E+291;
      } while ((fabs(rtb_C1) < 1.0020841800044864E-292) && (knt < 20));

      rtb_C1 = rt_hypotd_snf(t, BMS_xnrm2(6, rtb_ImpAsg_InsertedFor_y_at_inp, 2));
      if (t >= 0.0) {
        rtb_C1 = -rtb_C1;
      }

      for (i = 0; i < knt; i++) {
        rtb_C1 *= 1.0020841800044864E-292;
      }

      t = rtb_C1;
    } else {
      t = rtb_C1;
    }
  }

  BMS_rotate(t, residual_0[0], &scale, &absxk, &rtb_C1);
  for (i = 0; i < 7; i++) {
    /* Math: '<S18>/Math Function' */
    rtb_MathFunction[i] = rtb_Y1[i];

    /* Product: '<S18>/Product5' incorporates:
     *  Constant: '<S18>/Constant'
     */
    scale = 0.0;
    absxk = 0.0;
    rtb_X1_0 = 0.0;
    for (knt = 0; knt < 7; knt++) {
      t = BMS_ConstP.Constant_Value[7 * i + knt];
      tmp_1 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd
        (&rtb_ImpAsg_InsertedFor_Wm_ixk1_[3 * knt]), _mm_set1_pd(t)), _mm_set_pd
                         (absxk, scale));
      _mm_storeu_pd(&tmp_0[0], tmp_1);
      scale = tmp_0[0];
      absxk = tmp_0[1];
      rtb_X1_0 += rtb_ImpAsg_InsertedFor_Wm_ixk1_[3 * knt + 2] * t;
    }

    residual[3 * i + 2] = rtb_X1_0;
    residual[3 * i + 1] = absxk;
    residual[3 * i] = scale;

    /* End of Product: '<S18>/Product5' */
  }

  for (i = 0; i < 3; i++) {
    /* Product: '<S16>/Product1' incorporates:
     *  MATLAB Function: '<S18>/updatePy'
     *  Product: '<S16>/Product6'
     *  Product: '<S18>/Product1'
     */
    t = 0.0;
    for (knt = 0; knt < 7; knt++) {
      t += residual[3 * knt + i] * rtb_MathFunction[knt];
    }

    t = t / rtb_C1 / rtb_C1;
    rtb_Kk1_e[i] = t;

    /* End of Product: '<S16>/Product1' */

    /* Product: '<S16>/Product5' incorporates:
     *  MATLAB Function: '<S18>/updatePy'
     *  Product: '<S16>/Product1'
     */
    rtb_Product5[i] = t * rtb_C1;
  }

  /* MATLAB Function: '<S16>/updatePk' incorporates:
   *  Product: '<S16>/Product5'
   */
  for (i = 0; i < 1; i++) {
    for (knt = 0; knt < 3; knt++) {
      if ((2 - knt) - 1 >= 0) {
        memset(&rtb_Gain_j[(knt << 2) + 1], 0, (uint32_T)(2 - knt) * sizeof
               (real_T));
      }
    }

    errorCondition = (rtb_Gain_j[0] == 0.0);
    if (!errorCondition) {
      errorCondition = (rtb_Gain_j[4] == 0.0);
    }

    if (!errorCondition) {
      errorCondition = (rtb_Gain_j[8] == 0.0);
    }

    if (!errorCondition) {
      x[0] = rtb_Product5[0];
      x[1] = rtb_Product5[1];
      x[2] = rtb_Product5[2];
      rtb_C1 = 0.0;
      scale = 3.3121686421112381E-170;
      for (knt = 0; knt < 3; knt++) {
        iAcol = 3 * knt;
        t = x[knt];
        for (Assignment2_tmp = 0; Assignment2_tmp < knt; Assignment2_tmp++) {
          t -= rtb_Gain_j[Assignment2_tmp + iAcol] * x[Assignment2_tmp];
        }

        t /= rtb_Gain_j[knt + iAcol];
        x[knt] = t;
        absxk = fabs(t);
        if (absxk > scale) {
          t = scale / absxk;
          rtb_C1 = rtb_C1 * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          rtb_C1 += t * t;
        }
      }

      rtb_C1 = scale * sqrt(rtb_C1);
      if (!(rtb_C1 >= 1.0)) {
        rtb_C1 = sqrt(1.0 - rtb_C1 * rtb_C1);
        scale = fabs(x[2]);
        if (scale == 0.0) {
          b_c[2] = 1.0;
          s[2] = 0.0;
        } else {
          t = rtb_C1 + scale;
          rtb_C1 /= t;
          scale = x[2] / t;
          absxk = rt_hypotd_snf(rtb_C1, fabs(scale));
          b_c[2] = rtb_C1 / absxk;
          rtb_C1 /= rtb_C1;
          s[2] = rtb_C1 * scale / absxk;
          rtb_C1 *= absxk * t;
        }

        x[2] = 0.0;
        scale = fabs(x[1]);
        if (scale == 0.0) {
          b_c[1] = 1.0;
          s[1] = 0.0;
        } else if (rtb_C1 == 0.0) {
          b_c[1] = 0.0;
          s[1] = 1.0;
          rtb_C1 = x[1];
        } else {
          t = rtb_C1 + scale;
          rtb_C1 /= t;
          scale = x[1] / t;
          absxk = rt_hypotd_snf(rtb_C1, fabs(scale));
          b_c[1] = rtb_C1 / absxk;
          rtb_C1 /= rtb_C1;
          s[1] = rtb_C1 * scale / absxk;
          rtb_C1 *= absxk * t;
        }

        x[1] = 0.0;
        t = fabs(rtb_C1);
        scale = fabs(x[0]);
        if (scale == 0.0) {
          b_c[0] = 1.0;
          s[0] = 0.0;
        } else if (t == 0.0) {
          b_c[0] = 0.0;
          s[0] = 1.0;
        } else {
          t += scale;
          rtb_C1 /= t;
          scale = x[0] / t;
          t = fabs(rtb_C1);
          absxk = rt_hypotd_snf(t, fabs(scale));
          b_c[0] = t / absxk;
          s[0] = rtb_C1 / t * scale / absxk;
        }

        x[0] = 0.0;
        for (Assignment2_tmp = 0; Assignment2_tmp < 3; Assignment2_tmp++) {
          for (knt = Assignment2_tmp + 1; knt >= 1; knt--) {
            scale = s[knt - 1];
            iAcol = (3 * Assignment2_tmp + knt) - 1;
            rtb_C1 = rtb_Gain_j[iAcol];
            absxk = b_c[knt - 1];
            t = x[Assignment2_tmp];
            rtb_Gain_j[iAcol] = absxk * rtb_C1 - scale * t;
            x[Assignment2_tmp] = absxk * t + scale * rtb_C1;
          }
        }
      }
    }
  }

  /* End of MATLAB Function: '<S16>/updatePk' */

  /* Sum: '<S15>/Sum' incorporates:
   *  ForEachSliceSelector generated from: '<S2>/CellVoltage'
   *  Sum: '<S18>/Sum of Elements1'
   */
  rtb_uDLookupTableR0EOL = rtu_Voltage_V - rtb_uDLookupTableR0EOL;

  /* Update for Delay: '<S17>/Delay' */
  localDW->CoreSubsys[0].icLoad = false;

  /* Sum: '<S16>/Sum' incorporates:
   *  Product: '<S16>/Product1'
   *  Product: '<S16>/Product3'
   *  Sum: '<S18>/Sum of Elements'
   */
  t = rtb_Kk1_e[0] * rtb_uDLookupTableR0EOL + rtb_Add[0];
  rtb_Kk1_e[0] = t;

  /* Update for Delay: '<S17>/Delay' incorporates:
   *  Product: '<S16>/Product1'
   *  Product: '<S16>/Product3'
   *  Sum: '<S16>/Sum'
   *  Sum: '<S18>/Sum of Elements'
   * */
  localDW->CoreSubsys[0].Delay_DSTATE[0] = t;
  localDW->CoreSubsys[0].Delay_DSTATE[1] = rtb_Kk1_e[1] * rtb_uDLookupTableR0EOL
    + rtb_Add[1];

  /* Sum: '<S16>/Sum' incorporates:
   *  Product: '<S16>/Product1'
   *  Product: '<S16>/Product3'
   *  Sum: '<S18>/Sum of Elements'
   */
  t = rtb_Kk1_e[2] * rtb_uDLookupTableR0EOL + rtb_Add[2];

  /* Update for Delay: '<S17>/Delay' incorporates:
   *  Sum: '<S16>/Sum'
   */
  localDW->CoreSubsys[0].Delay_DSTATE[2] = t;

  /* Update for UnitDelay: '<S15>/Unit Delay - P' */
  memcpy(&localDW->CoreSubsys[0].UnitDelayP_DSTATE[0], &rtb_Gain_j[0], 9U *
         sizeof(real_T));

  /* ForEachSliceAssignment generated from: '<S2>/SOC' */
  *rty_Est_SOC_pct = rtb_Kk1_e[0];

  /* ForEachSliceAssignment generated from: '<S2>/R0' incorporates:
   *  Sum: '<S16>/Sum'
   */
  *rty_Est_R0_ohm = t;

  /* End of Outputs for SubSystem: '<S1>/SOC Estimator (Adaptive Kalman Filter)' */

  /* Outputs for Iterator SubSystem: '<S1>/SOH Estimator' incorporates:
   *  ForEach: '<S3>/For Each'
   */
  /* Lookup_n-D: '<S3>/2-D Lookup Table R0 EOL' incorporates:
   *  ForEachSliceSelector generated from: '<S3>/Temperature'
   */
  rtb_uDLookupTableR0EOL = look2_binlxpw(*rty_Est_SOC_pct, rtu_Temperature_K,
    BMS_ConstP.uDLookupTableR0EOL_bp01Data,
    BMS_ConstP.uDLookupTableR0EOL_bp02Data,
    BMS_ConstP.uDLookupTableR0EOL_tableData, BMS_ConstP.pooled5, 101U);

  /* Product: '<S3>/Product3' incorporates:
   *  ForEachSliceSelector generated from: '<S3>/Temperature'
   *  Lookup_n-D: '<S3>/2-D Lookup Table R0 new'
   *  Sum: '<S3>/Sum1'
   *  Sum: '<S3>/Sum3'
   */
  rtb_uDLookupTableR0EOL = (rtb_uDLookupTableR0EOL - *rty_Est_R0_ohm) /
    (rtb_uDLookupTableR0EOL - look2_binlxpw(*rty_Est_SOC_pct, rtu_Temperature_K,
      BMS_ConstP.uDLookupTableR0new_bp01Data,
      BMS_ConstP.uDLookupTableR0new_bp02Data,
      BMS_ConstP.uDLookupTableR0new_tableData, BMS_ConstP.pooled5, 101U));

  /* Saturate: '<S3>/Saturation' */
  if (rtb_uDLookupTableR0EOL > 1.0) {
    /* ForEachSliceAssignment generated from: '<S3>/SOH' */
    *rty_Est_SOH_pct = 1.0;
  } else if (rtb_uDLookupTableR0EOL < 0.0) {
    /* ForEachSliceAssignment generated from: '<S3>/SOH' */
    *rty_Est_SOH_pct = 0.0;
  } else {
    /* ForEachSliceAssignment generated from: '<S3>/SOH' */
    *rty_Est_SOH_pct = rtb_uDLookupTableR0EOL;
  }

  /* End of Saturate: '<S3>/Saturation' */
  /* End of Outputs for SubSystem: '<S1>/SOH Estimator' */
}

/* Model step function */
void BMS_step(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/BMS Algorithm' */

  /* Inport: '<Root>/Current_A' incorporates:
   *  Inport: '<Root>/Initial_R0_ohm'
   *  Inport: '<Root>/Initial_SOC_pct'
   *  Inport: '<Root>/Temperature_K'
   *  Inport: '<Root>/Voltage_V'
   *  Outport: '<Root>/Est_R0_ohm'
   *  Outport: '<Root>/Est_SOC_pct'
   *  Outport: '<Root>/Est_SOH_pct'
   */
  BMS_BMSAlgorithm(BMS_U.Current_A, BMS_U.Voltage_V, BMS_U.Temperature_K,
                   BMS_U.Initial_SOC_pct, BMS_U.Initial_R0_ohm,
                   &BMS_Y.Est_SOC_pct, &BMS_Y.Est_SOH_pct, &BMS_Y.Est_R0_ohm,
                   &BMS_B.BMSAlgorithm, &BMS_DW.BMSAlgorithm);

  /* End of Outputs for SubSystem: '<Root>/BMS Algorithm' */
}

/* Model initialize function */
void BMS_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* SystemInitialize for Atomic SubSystem: '<Root>/BMS Algorithm' */
  BMS_BMSAlgorithm_Init(&BMS_B.BMSAlgorithm, &BMS_DW.BMSAlgorithm);

  /* End of SystemInitialize for SubSystem: '<Root>/BMS Algorithm' */
}

/* Model terminate function */
void BMS_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
