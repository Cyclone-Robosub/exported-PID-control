//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: PID_Controller.cpp
//
// Code generated for Simulink model 'PID_Controller'.
//
// Model version                  : 4.7
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Wed Aug 13 14:57:12 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "PID_Controller.h"
#include <cmath>
#include <cstring>
#include "PID_Controller_private.h"
#include "rtwtypes.h"
#include "cmath"

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (std::isnan(u0) || std::isnan(u1)) {
    y = (rtNaN);
  } else {
    real_T tmp;
    real_T tmp_0;
    tmp = std::abs(u0);
    tmp_0 = std::abs(u1);
    if (std::isinf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = std::sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > std::floor(u1))) {
      y = (rtNaN);
    } else {
      y = std::pow(u0, u1);
    }
  }

  return y;
}

// Model step function
void PID_Controller::step()
{
  real_T tmp;
  real_T tmp_0;
  real_T u0;
  int32_T i;
  int32_T itmp;
  int32_T p2;
  int32_T p3;
  int8_T tmp_1;
  int8_T tmp_2;

  // Outputs for Atomic SubSystem: '<Root>/Controller2'
  // Sum: '<S1>/Sum' incorporates:
  //   Inport: '<Root>/states'
  //   Inport: '<Root>/waypoint'

  for (i = 0; i < 6; i++) {
    PID_Controller_B.Sum[i] = PID_Controller_U.waypoint[i] -
      PID_Controller_U.states[i];
  }

  // MATLAB Function: '<S1>/MATLAB Function' incorporates:
  //   Inport: '<Root>/DFC_error'
  //   Inport: '<Root>/controller_mode'
  //   Inport: '<Root>/states'
  //   Inport: '<Root>/waypoint'
  //   Sum: '<S1>/Sum'

  PID_Controller_B.absx11 = std::cos(PID_Controller_U.states[5]);
  PID_Controller_B.absx21 = std::sin(PID_Controller_U.states[5]);
  PID_Controller_B.ct_idx_0 = std::cos(PID_Controller_U.states[4]);
  PID_Controller_B.FilterCoefficient_n = std::sin(PID_Controller_U.states[4]);
  PID_Controller_B.absx31 = std::cos(PID_Controller_U.states[3]);
  PID_Controller_B.FilterCoefficient_c = std::sin(PID_Controller_U.states[3]);
  PID_Controller_B.DCMbe[0] = PID_Controller_B.absx11 *
    PID_Controller_B.ct_idx_0;
  PID_Controller_B.corrected_error = PID_Controller_B.FilterCoefficient_n *
    PID_Controller_B.FilterCoefficient_c;
  PID_Controller_B.DCMbe[3] = PID_Controller_B.corrected_error *
    PID_Controller_B.absx11 - PID_Controller_B.absx21 * PID_Controller_B.absx31;
  PID_Controller_B.FilterCoefficient_e = PID_Controller_B.FilterCoefficient_n *
    PID_Controller_B.absx31;
  PID_Controller_B.DCMbe[6] = PID_Controller_B.FilterCoefficient_e *
    PID_Controller_B.absx11 + PID_Controller_B.absx21 *
    PID_Controller_B.FilterCoefficient_c;
  PID_Controller_B.DCMbe[1] = PID_Controller_B.absx21 *
    PID_Controller_B.ct_idx_0;
  PID_Controller_B.DCMbe[4] = PID_Controller_B.corrected_error *
    PID_Controller_B.absx21 + PID_Controller_B.absx11 * PID_Controller_B.absx31;
  PID_Controller_B.DCMbe[7] = PID_Controller_B.FilterCoefficient_e *
    PID_Controller_B.absx21 - PID_Controller_B.absx11 *
    PID_Controller_B.FilterCoefficient_c;
  PID_Controller_B.DCMbe[2] = -PID_Controller_B.FilterCoefficient_n;
  PID_Controller_B.DCMbe[5] = PID_Controller_B.ct_idx_0 *
    PID_Controller_B.FilterCoefficient_c;
  PID_Controller_B.DCMbe[8] = PID_Controller_B.ct_idx_0 *
    PID_Controller_B.absx31;
  std::memcpy(&PID_Controller_B.x[0], &PID_Controller_B.DCMbe[0], 9U * sizeof
              (real_T));
  i = 0;
  p2 = 3;
  p3 = 6;
  PID_Controller_B.absx11 = std::abs(PID_Controller_B.DCMbe[0]);
  PID_Controller_B.absx21 = std::abs(PID_Controller_B.DCMbe[1]);
  PID_Controller_B.absx31 = std::abs(-PID_Controller_B.FilterCoefficient_n);
  if ((PID_Controller_B.absx21 > PID_Controller_B.absx11) &&
      (PID_Controller_B.absx21 > PID_Controller_B.absx31)) {
    i = 3;
    p2 = 0;
    PID_Controller_B.x[0] = PID_Controller_B.DCMbe[1];
    PID_Controller_B.x[1] = PID_Controller_B.DCMbe[0];
    PID_Controller_B.x[3] = PID_Controller_B.DCMbe[4];
    PID_Controller_B.x[4] = PID_Controller_B.DCMbe[3];
    PID_Controller_B.x[6] = PID_Controller_B.DCMbe[7];
    PID_Controller_B.x[7] = PID_Controller_B.DCMbe[6];
  } else if (PID_Controller_B.absx31 > PID_Controller_B.absx11) {
    i = 6;
    p3 = 0;
    PID_Controller_B.x[0] = -PID_Controller_B.FilterCoefficient_n;
    PID_Controller_B.x[2] = PID_Controller_B.DCMbe[0];
    PID_Controller_B.x[3] = PID_Controller_B.DCMbe[5];
    PID_Controller_B.x[5] = PID_Controller_B.DCMbe[3];
    PID_Controller_B.x[6] = PID_Controller_B.DCMbe[8];
    PID_Controller_B.x[8] = PID_Controller_B.DCMbe[6];
  }

  PID_Controller_B.x[1] /= PID_Controller_B.x[0];
  PID_Controller_B.x[2] /= PID_Controller_B.x[0];
  PID_Controller_B.x[4] -= PID_Controller_B.x[1] * PID_Controller_B.x[3];
  PID_Controller_B.x[5] -= PID_Controller_B.x[2] * PID_Controller_B.x[3];
  PID_Controller_B.x[7] -= PID_Controller_B.x[1] * PID_Controller_B.x[6];
  PID_Controller_B.x[8] -= PID_Controller_B.x[2] * PID_Controller_B.x[6];
  if (std::abs(PID_Controller_B.x[5]) > std::abs(PID_Controller_B.x[4])) {
    itmp = p2;
    p2 = p3;
    p3 = itmp;
    PID_Controller_B.absx11 = PID_Controller_B.x[1];
    PID_Controller_B.x[1] = PID_Controller_B.x[2];
    PID_Controller_B.x[2] = PID_Controller_B.absx11;
    PID_Controller_B.absx11 = PID_Controller_B.x[4];
    PID_Controller_B.x[4] = PID_Controller_B.x[5];
    PID_Controller_B.x[5] = PID_Controller_B.absx11;
    PID_Controller_B.absx11 = PID_Controller_B.x[7];
    PID_Controller_B.x[7] = PID_Controller_B.x[8];
    PID_Controller_B.x[8] = PID_Controller_B.absx11;
  }

  PID_Controller_B.x[5] /= PID_Controller_B.x[4];
  PID_Controller_B.x[8] -= PID_Controller_B.x[5] * PID_Controller_B.x[7];
  PID_Controller_B.absx11 = (PID_Controller_B.x[1] * PID_Controller_B.x[5] -
    PID_Controller_B.x[2]) / PID_Controller_B.x[8];
  PID_Controller_B.absx21 = -(PID_Controller_B.x[7] * PID_Controller_B.absx11 +
    PID_Controller_B.x[1]) / PID_Controller_B.x[4];
  PID_Controller_B.DCMeb[i] = ((1.0 - PID_Controller_B.x[3] *
    PID_Controller_B.absx21) - PID_Controller_B.x[6] * PID_Controller_B.absx11) /
    PID_Controller_B.x[0];
  PID_Controller_B.DCMeb[i + 1] = PID_Controller_B.absx21;
  PID_Controller_B.DCMeb[i + 2] = PID_Controller_B.absx11;
  PID_Controller_B.absx11 = -PID_Controller_B.x[5] / PID_Controller_B.x[8];
  PID_Controller_B.absx21 = (1.0 - PID_Controller_B.x[7] *
    PID_Controller_B.absx11) / PID_Controller_B.x[4];
  PID_Controller_B.DCMeb[p2] = -(PID_Controller_B.x[3] * PID_Controller_B.absx21
    + PID_Controller_B.x[6] * PID_Controller_B.absx11) / PID_Controller_B.x[0];
  PID_Controller_B.DCMeb[p2 + 1] = PID_Controller_B.absx21;
  PID_Controller_B.DCMeb[p2 + 2] = PID_Controller_B.absx11;
  PID_Controller_B.absx11 = 1.0 / PID_Controller_B.x[8];
  PID_Controller_B.absx21 = -PID_Controller_B.x[7] * PID_Controller_B.absx11 /
    PID_Controller_B.x[4];
  PID_Controller_B.DCMeb[p3] = -(PID_Controller_B.x[3] * PID_Controller_B.absx21
    + PID_Controller_B.x[6] * PID_Controller_B.absx11) / PID_Controller_B.x[0];
  PID_Controller_B.DCMeb[p3 + 1] = PID_Controller_B.absx21;
  PID_Controller_B.DCMeb[p3 + 2] = PID_Controller_B.absx11;
  if (PID_Controller_U.controller_mode == 1.0) {
    PID_Controller_B.y = PID_Controller_U.DFC_error[0];
    tmp_0 = PID_Controller_U.DFC_error[1];
    for (p2 = 0; p2 < 3; p2++) {
      PID_Controller_B.DCMeb_c[p2] = (PID_Controller_B.DCMeb[p2 + 3] * tmp_0 +
        PID_Controller_B.DCMeb[p2] * PID_Controller_B.y) +
        PID_Controller_B.DCMeb[p2 + 6] * 0.0;
    }

    PID_Controller_B.Sum[0] = PID_Controller_B.DCMeb_c[0];
    PID_Controller_B.Sum[1] = PID_Controller_B.DCMeb_c[1];
    PID_Controller_B.Sum[2] = PID_Controller_U.waypoint[2] -
      PID_Controller_U.states[2];
    PID_Controller_B.Sum[3] = PID_Controller_U.waypoint[3] -
      PID_Controller_U.states[3];
    PID_Controller_B.Sum[4] = PID_Controller_U.waypoint[4] -
      PID_Controller_U.states[4];
    PID_Controller_B.Sum[5] = PID_Controller_U.waypoint[5] -
      PID_Controller_U.states[5];
  }

  // End of MATLAB Function: '<S1>/MATLAB Function'

  // Gain: '<S104>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S96>/Filter'
  //   Gain: '<S94>/Derivative Gain'
  //   Sum: '<S96>/SumD'

  PID_Controller_B.FilterCoefficient_n = (2.504 * PID_Controller_B.Sum[3] -
    PID_Controller_DW.Filter_DSTATE_d) * 54.54;

  // Sum: '<S110>/Sum' incorporates:
  //   DiscreteIntegrator: '<S101>/Integrator'
  //   Gain: '<S106>/Proportional Gain'

  PID_Controller_B.absx31 = (4.773 * PID_Controller_B.Sum[3] +
    PID_Controller_DW.Integrator_DSTATE_j) +
    PID_Controller_B.FilterCoefficient_n;

  // Gain: '<S158>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S150>/Filter'
  //   Gain: '<S148>/Derivative Gain'
  //   Sum: '<S150>/SumD'

  PID_Controller_B.FilterCoefficient_c = (3.625 * PID_Controller_B.Sum[4] -
    PID_Controller_DW.Filter_DSTATE_n) * 54.54;

  // Sum: '<S164>/Sum' incorporates:
  //   DiscreteIntegrator: '<S155>/Integrator'
  //   Gain: '<S160>/Proportional Gain'

  PID_Controller_B.DeadZone_l = (6.912 * PID_Controller_B.Sum[4] +
    PID_Controller_DW.Integrator_DSTATE_l) +
    PID_Controller_B.FilterCoefficient_c;

  // MATLAB Function: '<S2>/Yaw Overshoot Corrector'
  if (PID_Controller_B.Sum[5] > 3.1415926535897931) {
    PID_Controller_B.corrected_error = PID_Controller_B.Sum[5] -
      6.2831853071795862;
  } else if (PID_Controller_B.Sum[5] < -3.1415926535897931) {
    PID_Controller_B.corrected_error = PID_Controller_B.Sum[5] +
      6.2831853071795862;
  } else {
    PID_Controller_B.corrected_error = PID_Controller_B.Sum[5];
  }

  // End of MATLAB Function: '<S2>/Yaw Overshoot Corrector'

  // Gain: '<S210>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S202>/Filter'
  //   Gain: '<S200>/Derivative Gain'
  //   Sum: '<S202>/SumD'

  PID_Controller_B.FilterCoefficient_e = (2.957 *
    PID_Controller_B.corrected_error - PID_Controller_DW.Filter_DSTATE_nq) *
    114.828;

  // Gain: '<S50>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S42>/Filter'
  //   Gain: '<S40>/Derivative Gain'
  //   Sum: '<S42>/SumD'

  PID_Controller_B.absx21 = (30.798 * PID_Controller_B.Sum[0] -
    PID_Controller_DW.Filter_DSTATE[0]) * 17.247;

  // End of Outputs for SubSystem: '<Root>/Controller2'
  PID_Controller_B.st_idx_0 = PID_Controller_B.absx21;

  // Outputs for Atomic SubSystem: '<Root>/Controller2'
  // Sum: '<S56>/Sum' incorporates:
  //   DiscreteIntegrator: '<S47>/Integrator'
  //   Gain: '<S40>/Derivative Gain'
  //   Gain: '<S50>/Filter Coefficient'
  //   Gain: '<S52>/Proportional Gain'

  PID_Controller_B.absx11 = (18.5 * PID_Controller_B.Sum[0] +
    PID_Controller_DW.Integrator_DSTATE[0]) + PID_Controller_B.absx21;

  // End of Outputs for SubSystem: '<Root>/Controller2'
  PID_Controller_B.ct_idx_0 = PID_Controller_B.absx11;

  // Outputs for Atomic SubSystem: '<Root>/Controller2'
  // Saturate: '<S54>/Saturation'
  if (PID_Controller_B.absx11 > 24.0) {
    PID_Controller_B.y = 24.0;
  } else if (PID_Controller_B.absx11 < -24.0) {
    PID_Controller_B.y = -24.0;
  } else {
    PID_Controller_B.y = PID_Controller_B.absx11;
  }

  // Gain: '<S50>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S42>/Filter'
  //   Gain: '<S40>/Derivative Gain'
  //   Sum: '<S42>/SumD'

  PID_Controller_B.absx21 = (30.798 * PID_Controller_B.Sum[1] -
    PID_Controller_DW.Filter_DSTATE[1]) * 17.247;

  // End of Outputs for SubSystem: '<Root>/Controller2'
  PID_Controller_B.st_idx_1 = PID_Controller_B.absx21;

  // Outputs for Atomic SubSystem: '<Root>/Controller2'
  // Sum: '<S56>/Sum' incorporates:
  //   DiscreteIntegrator: '<S47>/Integrator'
  //   Gain: '<S40>/Derivative Gain'
  //   Gain: '<S50>/Filter Coefficient'
  //   Gain: '<S52>/Proportional Gain'

  PID_Controller_B.absx11 = (18.5 * PID_Controller_B.Sum[1] +
    PID_Controller_DW.Integrator_DSTATE[1]) + PID_Controller_B.absx21;

  // End of Outputs for SubSystem: '<Root>/Controller2'
  PID_Controller_B.ct_idx_1 = PID_Controller_B.absx11;

  // Outputs for Atomic SubSystem: '<Root>/Controller2'
  // Saturate: '<S54>/Saturation'
  if (PID_Controller_B.absx11 > 24.0) {
    tmp_0 = 24.0;
  } else if (PID_Controller_B.absx11 < -24.0) {
    tmp_0 = -24.0;
  } else {
    tmp_0 = PID_Controller_B.absx11;
  }

  // Gain: '<S50>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S42>/Filter'
  //   Gain: '<S40>/Derivative Gain'
  //   Sum: '<S42>/SumD'

  PID_Controller_B.absx21 = (30.798 * PID_Controller_B.Sum[2] -
    PID_Controller_DW.Filter_DSTATE[2]) * 17.247;

  // Sum: '<S56>/Sum' incorporates:
  //   DiscreteIntegrator: '<S47>/Integrator'
  //   Gain: '<S40>/Derivative Gain'
  //   Gain: '<S50>/Filter Coefficient'
  //   Gain: '<S52>/Proportional Gain'

  PID_Controller_B.absx11 = (18.5 * PID_Controller_B.Sum[2] +
    PID_Controller_DW.Integrator_DSTATE[2]) + PID_Controller_B.absx21;

  // Saturate: '<S54>/Saturation'
  if (PID_Controller_B.absx11 > 24.0) {
    tmp = 24.0;
  } else if (PID_Controller_B.absx11 < -24.0) {
    tmp = -24.0;
  } else {
    tmp = PID_Controller_B.absx11;
  }

  // Sum: '<S216>/Sum' incorporates:
  //   DiscreteIntegrator: '<S207>/Integrator'
  //   Gain: '<S212>/Proportional Gain'

  u0 = (6.782 * PID_Controller_B.corrected_error +
        PID_Controller_DW.Integrator_DSTATE_h) +
    PID_Controller_B.FilterCoefficient_e;
  for (p2 = 0; p2 < 3; p2++) {
    // Product: '<S1>/Maps forces to pwms' incorporates:
    //   Product: '<S2>/Matrix Multiply'

    PID_Controller_B.rtb_DCMbe_m[p2] = (PID_Controller_B.DCMbe[p2 + 3] * tmp_0 +
      PID_Controller_B.DCMbe[p2] * PID_Controller_B.y) +
      PID_Controller_B.DCMbe[p2 + 6] * tmp;
  }

  // Saturate: '<S108>/Saturation'
  if (PID_Controller_B.absx31 > 5.0) {
    // Product: '<S1>/Maps forces to pwms'
    PID_Controller_B.rtb_DCMbe_m[3] = 5.0;
  } else if (PID_Controller_B.absx31 < -5.0) {
    // Product: '<S1>/Maps forces to pwms'
    PID_Controller_B.rtb_DCMbe_m[3] = -5.0;
  } else {
    // Product: '<S1>/Maps forces to pwms'
    PID_Controller_B.rtb_DCMbe_m[3] = PID_Controller_B.absx31;
  }

  // End of Saturate: '<S108>/Saturation'

  // Saturate: '<S162>/Saturation'
  if (PID_Controller_B.DeadZone_l > 5.0) {
    // Product: '<S1>/Maps forces to pwms'
    PID_Controller_B.rtb_DCMbe_m[4] = 5.0;
  } else if (PID_Controller_B.DeadZone_l < -5.0) {
    // Product: '<S1>/Maps forces to pwms'
    PID_Controller_B.rtb_DCMbe_m[4] = -5.0;
  } else {
    // Product: '<S1>/Maps forces to pwms'
    PID_Controller_B.rtb_DCMbe_m[4] = PID_Controller_B.DeadZone_l;
  }

  // End of Saturate: '<S162>/Saturation'

  // Saturate: '<S214>/Saturation'
  if (u0 > 5.0) {
    // Product: '<S1>/Maps forces to pwms'
    PID_Controller_B.rtb_DCMbe_m[5] = 5.0;
  } else if (u0 < -5.0) {
    // Product: '<S1>/Maps forces to pwms'
    PID_Controller_B.rtb_DCMbe_m[5] = -5.0;
  } else {
    // Product: '<S1>/Maps forces to pwms'
    PID_Controller_B.rtb_DCMbe_m[5] = u0;
  }

  // End of Saturate: '<S214>/Saturation'
  for (i = 0; i < 8; i++) {
    // Product: '<S1>/Maps forces to pwms' incorporates:
    //   Constant: '<S1>/Constant'

    PID_Controller_B.y = 0.0;
    for (p2 = 0; p2 < 6; p2++) {
      PID_Controller_B.y += PID_Controller_ConstP.Constant_Value[(p2 << 3) + i] *
        PID_Controller_B.rtb_DCMbe_m[p2];
    }

    // MATLAB Function: '<S1>/Thruster Forces to PWM' incorporates:
    //   Product: '<S1>/Maps forces to pwms'

    if (PID_Controller_B.y > 0.0) {
      PID_Controller_B.y = std::round(((PID_Controller_B.y * PID_Controller_B.y *
        -0.229204832763592 + 0.00231011300235566 * rt_powd_snf
        (PID_Controller_B.y, 3.0)) + 13.7272237851422 * PID_Controller_B.y) +
        1536.34500151024);
    } else if (PID_Controller_B.y < 0.0) {
      PID_Controller_B.y = std::round(((PID_Controller_B.y * PID_Controller_B.y *
        0.360062809963915 + 0.00475737746846442 * rt_powd_snf(PID_Controller_B.y,
        3.0)) + 17.2034080439155 * PID_Controller_B.y) + 1463.91061014397);
    } else {
      PID_Controller_B.y = 1500.0;
    }

    if (PID_Controller_B.y > 1900.0) {
      PID_Controller_B.y = 1900.0;
    }

    if (PID_Controller_B.y < 1100.0) {
      PID_Controller_B.y = 1100.0;
    }

    // MATLAB Function: '<S1>/PWM Clamping' incorporates:
    //   MATLAB Function: '<S1>/Thruster Forces to PWM'

    if (PID_Controller_B.y > 1792.0) {
      PID_Controller_Y.PWM[i] = 1792.0;
    } else if (PID_Controller_B.y < 1212.0) {
      PID_Controller_Y.PWM[i] = 1212.0;
    } else {
      PID_Controller_Y.PWM[i] = PID_Controller_B.y;
    }

    // End of MATLAB Function: '<S1>/PWM Clamping'
  }

  // DeadZone: '<S147>/DeadZone'
  if (PID_Controller_B.DeadZone_l > 5.0) {
    PID_Controller_B.DeadZone_l -= 5.0;
  } else if (PID_Controller_B.DeadZone_l >= -5.0) {
    PID_Controller_B.DeadZone_l = 0.0;
  } else {
    PID_Controller_B.DeadZone_l -= -5.0;
  }

  // End of DeadZone: '<S147>/DeadZone'

  // Gain: '<S152>/Integral Gain'
  PID_Controller_B.y = 3.236 * PID_Controller_B.Sum[4];

  // Switch: '<S145>/Switch1' incorporates:
  //   Constant: '<S145>/Clamping_zero'
  //   Constant: '<S145>/Constant'
  //   Constant: '<S145>/Constant2'
  //   RelationalOperator: '<S145>/fix for DT propagation issue'

  if (PID_Controller_B.DeadZone_l > 0.0) {
    tmp_1 = 1;
  } else {
    tmp_1 = -1;
  }

  // Switch: '<S145>/Switch2' incorporates:
  //   Constant: '<S145>/Clamping_zero'
  //   Constant: '<S145>/Constant3'
  //   Constant: '<S145>/Constant4'
  //   RelationalOperator: '<S145>/fix for DT propagation issue1'

  if (PID_Controller_B.y > 0.0) {
    tmp_2 = 1;
  } else {
    tmp_2 = -1;
  }

  // Switch: '<S145>/Switch' incorporates:
  //   Constant: '<S145>/Clamping_zero'
  //   Constant: '<S145>/Constant1'
  //   Logic: '<S145>/AND3'
  //   RelationalOperator: '<S145>/Equal1'
  //   RelationalOperator: '<S145>/Relational Operator'
  //   Switch: '<S145>/Switch1'
  //   Switch: '<S145>/Switch2'

  if ((PID_Controller_B.DeadZone_l != 0.0) && (tmp_1 == tmp_2)) {
    PID_Controller_B.DeadZone_l = 0.0;
  } else {
    PID_Controller_B.DeadZone_l = PID_Controller_B.y;
  }

  // End of Switch: '<S145>/Switch'

  // DeadZone: '<S93>/DeadZone'
  if (PID_Controller_B.absx31 > 5.0) {
    PID_Controller_B.absx31 -= 5.0;
  } else if (PID_Controller_B.absx31 >= -5.0) {
    PID_Controller_B.absx31 = 0.0;
  } else {
    PID_Controller_B.absx31 -= -5.0;
  }

  // End of DeadZone: '<S93>/DeadZone'

  // Gain: '<S98>/Integral Gain'
  PID_Controller_B.y = 2.325 * PID_Controller_B.Sum[3];

  // DeadZone: '<S39>/DeadZone'
  if (PID_Controller_B.ct_idx_0 > 24.0) {
    PID_Controller_B.ct_idx_0 -= 24.0;
  } else if (PID_Controller_B.ct_idx_0 >= -24.0) {
    PID_Controller_B.ct_idx_0 = 0.0;
  } else {
    PID_Controller_B.ct_idx_0 -= -24.0;
  }

  // Gain: '<S44>/Integral Gain'
  tmp_0 = 2.749 * PID_Controller_B.Sum[0];

  // Switch: '<S37>/Switch1' incorporates:
  //   Constant: '<S37>/Clamping_zero'
  //   Constant: '<S37>/Constant'
  //   Constant: '<S37>/Constant2'
  //   DeadZone: '<S39>/DeadZone'
  //   RelationalOperator: '<S37>/fix for DT propagation issue'

  if (PID_Controller_B.ct_idx_0 > 0.0) {
    tmp_1 = 1;
  } else {
    tmp_1 = -1;
  }

  // Switch: '<S37>/Switch2' incorporates:
  //   Constant: '<S37>/Clamping_zero'
  //   Constant: '<S37>/Constant3'
  //   Constant: '<S37>/Constant4'
  //   Gain: '<S44>/Integral Gain'
  //   RelationalOperator: '<S37>/fix for DT propagation issue1'

  if (tmp_0 > 0.0) {
    tmp_2 = 1;
  } else {
    tmp_2 = -1;
  }

  // Switch: '<S37>/Switch' incorporates:
  //   Constant: '<S37>/Clamping_zero'
  //   Constant: '<S37>/Constant1'
  //   DeadZone: '<S39>/DeadZone'
  //   Logic: '<S37>/AND3'
  //   RelationalOperator: '<S37>/Equal1'
  //   RelationalOperator: '<S37>/Relational Operator'
  //   Switch: '<S37>/Switch1'
  //   Switch: '<S37>/Switch2'

  if ((PID_Controller_B.ct_idx_0 != 0.0) && (tmp_1 == tmp_2)) {
    tmp_0 = 0.0;
  }

  // Update for DiscreteIntegrator: '<S47>/Integrator' incorporates:
  //   Switch: '<S37>/Switch'

  PID_Controller_DW.Integrator_DSTATE[0] += 0.01 * tmp_0;

  // Update for DiscreteIntegrator: '<S42>/Filter' incorporates:
  //   Gain: '<S50>/Filter Coefficient'

  PID_Controller_DW.Filter_DSTATE[0] += 0.01 * PID_Controller_B.st_idx_0;

  // DeadZone: '<S39>/DeadZone'
  if (PID_Controller_B.ct_idx_1 > 24.0) {
    PID_Controller_B.ct_idx_0 = PID_Controller_B.ct_idx_1 - 24.0;
  } else if (PID_Controller_B.ct_idx_1 >= -24.0) {
    PID_Controller_B.ct_idx_0 = 0.0;
  } else {
    PID_Controller_B.ct_idx_0 = PID_Controller_B.ct_idx_1 - -24.0;
  }

  // Gain: '<S44>/Integral Gain'
  tmp_0 = 2.749 * PID_Controller_B.Sum[1];

  // Switch: '<S37>/Switch1' incorporates:
  //   Constant: '<S37>/Clamping_zero'
  //   Constant: '<S37>/Constant'
  //   Constant: '<S37>/Constant2'
  //   DeadZone: '<S39>/DeadZone'
  //   RelationalOperator: '<S37>/fix for DT propagation issue'

  if (PID_Controller_B.ct_idx_0 > 0.0) {
    tmp_1 = 1;
  } else {
    tmp_1 = -1;
  }

  // Switch: '<S37>/Switch2' incorporates:
  //   Constant: '<S37>/Clamping_zero'
  //   Constant: '<S37>/Constant3'
  //   Constant: '<S37>/Constant4'
  //   Gain: '<S44>/Integral Gain'
  //   RelationalOperator: '<S37>/fix for DT propagation issue1'

  if (tmp_0 > 0.0) {
    tmp_2 = 1;
  } else {
    tmp_2 = -1;
  }

  // Switch: '<S37>/Switch' incorporates:
  //   Constant: '<S37>/Clamping_zero'
  //   Constant: '<S37>/Constant1'
  //   DeadZone: '<S39>/DeadZone'
  //   Logic: '<S37>/AND3'
  //   RelationalOperator: '<S37>/Equal1'
  //   RelationalOperator: '<S37>/Relational Operator'
  //   Switch: '<S37>/Switch1'
  //   Switch: '<S37>/Switch2'

  if ((PID_Controller_B.ct_idx_0 != 0.0) && (tmp_1 == tmp_2)) {
    tmp_0 = 0.0;
  }

  // Update for DiscreteIntegrator: '<S47>/Integrator' incorporates:
  //   Switch: '<S37>/Switch'

  PID_Controller_DW.Integrator_DSTATE[1] += 0.01 * tmp_0;

  // Update for DiscreteIntegrator: '<S42>/Filter' incorporates:
  //   Gain: '<S50>/Filter Coefficient'

  PID_Controller_DW.Filter_DSTATE[1] += 0.01 * PID_Controller_B.st_idx_1;

  // DeadZone: '<S39>/DeadZone'
  if (PID_Controller_B.absx11 > 24.0) {
    PID_Controller_B.ct_idx_0 = PID_Controller_B.absx11 - 24.0;
  } else if (PID_Controller_B.absx11 >= -24.0) {
    PID_Controller_B.ct_idx_0 = 0.0;
  } else {
    PID_Controller_B.ct_idx_0 = PID_Controller_B.absx11 - -24.0;
  }

  // Gain: '<S44>/Integral Gain'
  tmp_0 = 2.749 * PID_Controller_B.Sum[2];

  // Switch: '<S37>/Switch1' incorporates:
  //   Constant: '<S37>/Clamping_zero'
  //   Constant: '<S37>/Constant'
  //   Constant: '<S37>/Constant2'
  //   DeadZone: '<S39>/DeadZone'
  //   RelationalOperator: '<S37>/fix for DT propagation issue'

  if (PID_Controller_B.ct_idx_0 > 0.0) {
    tmp_1 = 1;
  } else {
    tmp_1 = -1;
  }

  // Switch: '<S37>/Switch2' incorporates:
  //   Constant: '<S37>/Clamping_zero'
  //   Constant: '<S37>/Constant3'
  //   Constant: '<S37>/Constant4'
  //   Gain: '<S44>/Integral Gain'
  //   RelationalOperator: '<S37>/fix for DT propagation issue1'

  if (tmp_0 > 0.0) {
    tmp_2 = 1;
  } else {
    tmp_2 = -1;
  }

  // Switch: '<S37>/Switch' incorporates:
  //   Constant: '<S37>/Clamping_zero'
  //   Constant: '<S37>/Constant1'
  //   DeadZone: '<S39>/DeadZone'
  //   Logic: '<S37>/AND3'
  //   RelationalOperator: '<S37>/Equal1'
  //   RelationalOperator: '<S37>/Relational Operator'
  //   Switch: '<S37>/Switch1'
  //   Switch: '<S37>/Switch2'

  if ((PID_Controller_B.ct_idx_0 != 0.0) && (tmp_1 == tmp_2)) {
    tmp_0 = 0.0;
  }

  // Update for DiscreteIntegrator: '<S47>/Integrator' incorporates:
  //   Switch: '<S37>/Switch'

  PID_Controller_DW.Integrator_DSTATE[2] += 0.01 * tmp_0;

  // Update for DiscreteIntegrator: '<S42>/Filter'
  PID_Controller_DW.Filter_DSTATE[2] += 0.01 * PID_Controller_B.absx21;

  // Switch: '<S91>/Switch1' incorporates:
  //   Constant: '<S91>/Clamping_zero'
  //   Constant: '<S91>/Constant'
  //   Constant: '<S91>/Constant2'
  //   RelationalOperator: '<S91>/fix for DT propagation issue'

  if (PID_Controller_B.absx31 > 0.0) {
    tmp_1 = 1;
  } else {
    tmp_1 = -1;
  }

  // Switch: '<S91>/Switch2' incorporates:
  //   Constant: '<S91>/Clamping_zero'
  //   Constant: '<S91>/Constant3'
  //   Constant: '<S91>/Constant4'
  //   RelationalOperator: '<S91>/fix for DT propagation issue1'

  if (PID_Controller_B.y > 0.0) {
    tmp_2 = 1;
  } else {
    tmp_2 = -1;
  }

  // Switch: '<S91>/Switch' incorporates:
  //   Constant: '<S91>/Clamping_zero'
  //   Constant: '<S91>/Constant1'
  //   Logic: '<S91>/AND3'
  //   RelationalOperator: '<S91>/Equal1'
  //   RelationalOperator: '<S91>/Relational Operator'
  //   Switch: '<S91>/Switch1'
  //   Switch: '<S91>/Switch2'

  if ((PID_Controller_B.absx31 != 0.0) && (tmp_1 == tmp_2)) {
    PID_Controller_B.y = 0.0;
  }

  // Update for DiscreteIntegrator: '<S101>/Integrator' incorporates:
  //   Switch: '<S91>/Switch'

  PID_Controller_DW.Integrator_DSTATE_j += 0.01 * PID_Controller_B.y;

  // Update for DiscreteIntegrator: '<S96>/Filter'
  PID_Controller_DW.Filter_DSTATE_d += 0.01 *
    PID_Controller_B.FilterCoefficient_n;

  // Update for DiscreteIntegrator: '<S155>/Integrator'
  PID_Controller_DW.Integrator_DSTATE_l += 0.01 * PID_Controller_B.DeadZone_l;

  // Update for DiscreteIntegrator: '<S150>/Filter'
  PID_Controller_DW.Filter_DSTATE_n += 0.01 *
    PID_Controller_B.FilterCoefficient_c;

  // Update for DiscreteIntegrator: '<S207>/Integrator' incorporates:
  //   Gain: '<S204>/Integral Gain'

  PID_Controller_DW.Integrator_DSTATE_h += 2.479 *
    PID_Controller_B.corrected_error * 0.01;

  // Update for DiscreteIntegrator: '<S202>/Filter'
  PID_Controller_DW.Filter_DSTATE_nq += 0.01 *
    PID_Controller_B.FilterCoefficient_e;

  // End of Outputs for SubSystem: '<Root>/Controller2'
}

// Model initialize function
void PID_Controller::initialize()
{
  // (no initialization code required)
}

// Model terminate function
void PID_Controller::terminate()
{
  // (no terminate code required)
}

const char_T* PID_Controller::RT_MODEL_PID_Controller_T::getErrorStatus() const
{
  return (errorStatus);
}

void PID_Controller::RT_MODEL_PID_Controller_T::setErrorStatus(const char_T*
  const volatile aErrorStatus)
{
  (errorStatus = aErrorStatus);
}

// Constructor
PID_Controller::PID_Controller() :
  PID_Controller_U(),
  PID_Controller_Y(),
  PID_Controller_B(),
  PID_Controller_DW(),
  PID_Controller_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
PID_Controller::~PID_Controller() = default;

// Real-Time Model get method
PID_Controller::RT_MODEL_PID_Controller_T * PID_Controller::getRTM()
{
  return (&PID_Controller_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
