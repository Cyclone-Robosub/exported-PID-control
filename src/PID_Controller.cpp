//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: PID_Controller.cpp
//
// Code generated for Simulink model 'PID_Controller'.
//
// Model version                  : 4.6
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Tue Aug 12 22:18:40 2025
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
  real_T u0;
  real_T u0_0;
  real_T u0_1;
  int32_T i;
  int32_T itmp;
  int32_T p2;
  int32_T p3;
  int8_T tmp;
  int8_T tmp_0;

  // Outputs for Atomic SubSystem: '<Root>/Controller1'
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

  PID_Controller_B.absx21 = std::cos(PID_Controller_U.states[5]);
  PID_Controller_B.absx11 = std::sin(PID_Controller_U.states[5]);
  PID_Controller_B.absx31 = std::cos(PID_Controller_U.states[4]);
  PID_Controller_B.t2 = std::sin(PID_Controller_U.states[4]);
  PID_Controller_B.corrected_error = std::cos(PID_Controller_U.states[3]);
  PID_Controller_B.FilterCoefficient_fo = std::sin(PID_Controller_U.states[3]);
  PID_Controller_B.DCMbe[0] = PID_Controller_B.absx21 * PID_Controller_B.absx31;
  PID_Controller_B.st_idx_0 = PID_Controller_B.t2 *
    PID_Controller_B.FilterCoefficient_fo;
  PID_Controller_B.DCMbe[3] = PID_Controller_B.st_idx_0 *
    PID_Controller_B.absx21 - PID_Controller_B.absx11 *
    PID_Controller_B.corrected_error;
  PID_Controller_B.st_idx_1 = PID_Controller_B.t2 *
    PID_Controller_B.corrected_error;
  PID_Controller_B.DCMbe[6] = PID_Controller_B.st_idx_1 *
    PID_Controller_B.absx21 + PID_Controller_B.absx11 *
    PID_Controller_B.FilterCoefficient_fo;
  PID_Controller_B.DCMbe[1] = PID_Controller_B.absx11 * PID_Controller_B.absx31;
  PID_Controller_B.DCMbe[4] = PID_Controller_B.st_idx_0 *
    PID_Controller_B.absx11 + PID_Controller_B.absx21 *
    PID_Controller_B.corrected_error;
  PID_Controller_B.DCMbe[7] = PID_Controller_B.st_idx_1 *
    PID_Controller_B.absx11 - PID_Controller_B.absx21 *
    PID_Controller_B.FilterCoefficient_fo;
  PID_Controller_B.DCMbe[2] = -PID_Controller_B.t2;
  PID_Controller_B.DCMbe[5] = PID_Controller_B.absx31 *
    PID_Controller_B.FilterCoefficient_fo;
  PID_Controller_B.DCMbe[8] = PID_Controller_B.absx31 *
    PID_Controller_B.corrected_error;
  std::memcpy(&PID_Controller_B.x[0], &PID_Controller_B.DCMbe[0], 9U * sizeof
              (real_T));
  i = 0;
  p2 = 3;
  p3 = 6;
  PID_Controller_B.absx11 = std::abs(PID_Controller_B.DCMbe[0]);
  PID_Controller_B.absx21 = std::abs(PID_Controller_B.DCMbe[1]);
  PID_Controller_B.absx31 = std::abs(-PID_Controller_B.t2);
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
    PID_Controller_B.x[0] = -PID_Controller_B.t2;
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
  PID_Controller_B.t2 = -(PID_Controller_B.x[7] * PID_Controller_B.absx11 +
    PID_Controller_B.x[1]) / PID_Controller_B.x[4];
  PID_Controller_B.DCMeb[i] = ((1.0 - PID_Controller_B.x[3] *
    PID_Controller_B.t2) - PID_Controller_B.x[6] * PID_Controller_B.absx11) /
    PID_Controller_B.x[0];
  PID_Controller_B.DCMeb[i + 1] = PID_Controller_B.t2;
  PID_Controller_B.DCMeb[i + 2] = PID_Controller_B.absx11;
  PID_Controller_B.absx11 = -PID_Controller_B.x[5] / PID_Controller_B.x[8];
  PID_Controller_B.t2 = (1.0 - PID_Controller_B.x[7] * PID_Controller_B.absx11) /
    PID_Controller_B.x[4];
  PID_Controller_B.DCMeb[p2] = -(PID_Controller_B.x[3] * PID_Controller_B.t2 +
    PID_Controller_B.x[6] * PID_Controller_B.absx11) / PID_Controller_B.x[0];
  PID_Controller_B.DCMeb[p2 + 1] = PID_Controller_B.t2;
  PID_Controller_B.DCMeb[p2 + 2] = PID_Controller_B.absx11;
  PID_Controller_B.absx11 = 1.0 / PID_Controller_B.x[8];
  PID_Controller_B.t2 = -PID_Controller_B.x[7] * PID_Controller_B.absx11 /
    PID_Controller_B.x[4];
  PID_Controller_B.DCMeb[p3] = -(PID_Controller_B.x[3] * PID_Controller_B.t2 +
    PID_Controller_B.x[6] * PID_Controller_B.absx11) / PID_Controller_B.x[0];
  PID_Controller_B.DCMeb[p3 + 1] = PID_Controller_B.t2;
  PID_Controller_B.DCMeb[p3 + 2] = PID_Controller_B.absx11;
  if (PID_Controller_U.controller_mode == 1.0) {
    PID_Controller_B.absx11 = PID_Controller_U.DFC_error[0];
    PID_Controller_B.t2 = PID_Controller_U.DFC_error[1];
    for (p2 = 0; p2 < 3; p2++) {
      PID_Controller_B.DCMeb_c[p2] = (PID_Controller_B.DCMeb[p2 + 3] *
        PID_Controller_B.t2 + PID_Controller_B.DCMeb[p2] *
        PID_Controller_B.absx11) + PID_Controller_B.DCMeb[p2 + 6] * 0.0;
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

  // Gain: '<S49>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S41>/Filter'
  //   Gain: '<S39>/Derivative Gain'
  //   Sum: '<S41>/SumD'

  PID_Controller_B.t2 = (2.504 * PID_Controller_B.Sum[3] -
    PID_Controller_DW.Filter_DSTATE_e) * 54.54;

  // Sum: '<S55>/Sum' incorporates:
  //   DiscreteIntegrator: '<S46>/Integrator'
  //   Gain: '<S51>/Proportional Gain'

  PID_Controller_B.absx21 = (4.773 * PID_Controller_B.Sum[3] +
    PID_Controller_DW.Integrator_DSTATE_m) + PID_Controller_B.t2;

  // Gain: '<S103>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S95>/Filter'
  //   Gain: '<S93>/Derivative Gain'
  //   Sum: '<S95>/SumD'

  PID_Controller_B.absx31 = (3.625 * PID_Controller_B.Sum[4] -
    PID_Controller_DW.Filter_DSTATE_en) * 54.54;

  // Sum: '<S109>/Sum' incorporates:
  //   DiscreteIntegrator: '<S100>/Integrator'
  //   Gain: '<S105>/Proportional Gain'

  PID_Controller_B.DeadZone_f = (6.912 * PID_Controller_B.Sum[4] +
    PID_Controller_DW.Integrator_DSTATE_f) + PID_Controller_B.absx31;

  // MATLAB Function: '<S2>/Yaw Overshoot Corrector'
  if (PID_Controller_B.Sum[5] > 1.5707963267948966) {
    PID_Controller_B.corrected_error = PID_Controller_B.Sum[5] -
      6.2831853071795862;
  } else if (PID_Controller_B.Sum[5] < -1.5707963267948966) {
    PID_Controller_B.corrected_error = PID_Controller_B.Sum[5] +
      6.2831853071795862;
  } else {
    PID_Controller_B.corrected_error = PID_Controller_B.Sum[5];
  }

  // End of MATLAB Function: '<S2>/Yaw Overshoot Corrector'

  // Gain: '<S155>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S147>/Filter'
  //   Gain: '<S145>/Derivative Gain'
  //   Sum: '<S147>/SumD'

  PID_Controller_B.FilterCoefficient_fo = (2.957 *
    PID_Controller_B.corrected_error - PID_Controller_DW.Filter_DSTATE_n) *
    114.828;

  // Gain: '<S207>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S199>/Filter'
  //   Gain: '<S197>/Derivative Gain'
  //   Sum: '<S199>/SumD'

  PID_Controller_B.absx11 = (30.7980856287723 * PID_Controller_B.Sum[0] -
    PID_Controller_DW.Filter_DSTATE[0]) * 17.2469682941307;

  // End of Outputs for SubSystem: '<Root>/Controller1'
  PID_Controller_B.st_idx_0 = PID_Controller_B.absx11;

  // Outputs for Atomic SubSystem: '<Root>/Controller1'
  // Saturate: '<S211>/Saturation' incorporates:
  //   DiscreteIntegrator: '<S204>/Integrator'
  //   Gain: '<S197>/Derivative Gain'
  //   Gain: '<S207>/Filter Coefficient'
  //   Gain: '<S209>/Proportional Gain'
  //   Sum: '<S213>/Sum'

  PID_Controller_B.y = (18.567926327114 * PID_Controller_B.Sum[0] +
                        PID_Controller_DW.Integrator_DSTATE[0]) +
    PID_Controller_B.absx11;
  if (PID_Controller_B.y > 120.0) {
    PID_Controller_B.y = 120.0;
  } else if (PID_Controller_B.y < -120.0) {
    PID_Controller_B.y = -120.0;
  }

  // Gain: '<S207>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S199>/Filter'
  //   Gain: '<S197>/Derivative Gain'
  //   Sum: '<S199>/SumD'

  PID_Controller_B.absx11 = (30.7980856287723 * PID_Controller_B.Sum[1] -
    PID_Controller_DW.Filter_DSTATE[1]) * 17.2469682941307;

  // End of Outputs for SubSystem: '<Root>/Controller1'
  PID_Controller_B.st_idx_1 = PID_Controller_B.absx11;

  // Outputs for Atomic SubSystem: '<Root>/Controller1'
  // Saturate: '<S211>/Saturation' incorporates:
  //   DiscreteIntegrator: '<S204>/Integrator'
  //   Gain: '<S197>/Derivative Gain'
  //   Gain: '<S207>/Filter Coefficient'
  //   Gain: '<S209>/Proportional Gain'
  //   Sum: '<S213>/Sum'

  u0 = (18.567926327114 * PID_Controller_B.Sum[1] +
        PID_Controller_DW.Integrator_DSTATE[1]) + PID_Controller_B.absx11;
  if (u0 > 120.0) {
    u0 = 120.0;
  } else if (u0 < -120.0) {
    u0 = -120.0;
  }

  // Gain: '<S207>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S199>/Filter'
  //   Gain: '<S197>/Derivative Gain'
  //   Sum: '<S199>/SumD'

  PID_Controller_B.absx11 = (30.7980856287723 * PID_Controller_B.Sum[2] -
    PID_Controller_DW.Filter_DSTATE[2]) * 17.2469682941307;

  // Saturate: '<S211>/Saturation' incorporates:
  //   DiscreteIntegrator: '<S204>/Integrator'
  //   Gain: '<S197>/Derivative Gain'
  //   Gain: '<S207>/Filter Coefficient'
  //   Gain: '<S209>/Proportional Gain'
  //   Sum: '<S213>/Sum'

  u0_0 = (18.567926327114 * PID_Controller_B.Sum[2] +
          PID_Controller_DW.Integrator_DSTATE[2]) + PID_Controller_B.absx11;
  if (u0_0 > 120.0) {
    u0_0 = 120.0;
  } else if (u0_0 < -120.0) {
    u0_0 = -120.0;
  }

  // Sum: '<S161>/Sum' incorporates:
  //   DiscreteIntegrator: '<S152>/Integrator'
  //   Gain: '<S157>/Proportional Gain'

  u0_1 = (6.782 * PID_Controller_B.corrected_error +
          PID_Controller_DW.Integrator_DSTATE_k) +
    PID_Controller_B.FilterCoefficient_fo;
  for (p2 = 0; p2 < 3; p2++) {
    // Product: '<S1>/Maps forces to pwms' incorporates:
    //   Product: '<S2>/Matrix Multiply'

    PID_Controller_B.rtb_DCMbe_m[p2] = (PID_Controller_B.DCMbe[p2 + 3] * u0 +
      PID_Controller_B.DCMbe[p2] * PID_Controller_B.y) +
      PID_Controller_B.DCMbe[p2 + 6] * u0_0;
  }

  // Saturate: '<S53>/Saturation'
  if (PID_Controller_B.absx21 > 5.0) {
    // Product: '<S1>/Maps forces to pwms'
    PID_Controller_B.rtb_DCMbe_m[3] = 5.0;
  } else if (PID_Controller_B.absx21 < -5.0) {
    // Product: '<S1>/Maps forces to pwms'
    PID_Controller_B.rtb_DCMbe_m[3] = -5.0;
  } else {
    // Product: '<S1>/Maps forces to pwms'
    PID_Controller_B.rtb_DCMbe_m[3] = PID_Controller_B.absx21;
  }

  // End of Saturate: '<S53>/Saturation'

  // Saturate: '<S107>/Saturation'
  if (PID_Controller_B.DeadZone_f > 5.0) {
    // Product: '<S1>/Maps forces to pwms'
    PID_Controller_B.rtb_DCMbe_m[4] = 5.0;
  } else if (PID_Controller_B.DeadZone_f < -5.0) {
    // Product: '<S1>/Maps forces to pwms'
    PID_Controller_B.rtb_DCMbe_m[4] = -5.0;
  } else {
    // Product: '<S1>/Maps forces to pwms'
    PID_Controller_B.rtb_DCMbe_m[4] = PID_Controller_B.DeadZone_f;
  }

  // End of Saturate: '<S107>/Saturation'

  // Saturate: '<S159>/Saturation'
  if (u0_1 > 5.0) {
    // Product: '<S1>/Maps forces to pwms'
    PID_Controller_B.rtb_DCMbe_m[5] = 5.0;
  } else if (u0_1 < -5.0) {
    // Product: '<S1>/Maps forces to pwms'
    PID_Controller_B.rtb_DCMbe_m[5] = -5.0;
  } else {
    // Product: '<S1>/Maps forces to pwms'
    PID_Controller_B.rtb_DCMbe_m[5] = u0_1;
  }

  // End of Saturate: '<S159>/Saturation'
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

    PID_Controller_Y.PWM[i] = PID_Controller_B.y;

    // End of MATLAB Function: '<S1>/Thruster Forces to PWM'
  }

  // DeadZone: '<S92>/DeadZone'
  if (PID_Controller_B.DeadZone_f > 5.0) {
    PID_Controller_B.DeadZone_f -= 5.0;
  } else if (PID_Controller_B.DeadZone_f >= -5.0) {
    PID_Controller_B.DeadZone_f = 0.0;
  } else {
    PID_Controller_B.DeadZone_f -= -5.0;
  }

  // End of DeadZone: '<S92>/DeadZone'

  // Gain: '<S97>/Integral Gain'
  PID_Controller_B.y = 3.236 * PID_Controller_B.Sum[4];

  // Switch: '<S90>/Switch1' incorporates:
  //   Constant: '<S90>/Clamping_zero'
  //   Constant: '<S90>/Constant'
  //   Constant: '<S90>/Constant2'
  //   RelationalOperator: '<S90>/fix for DT propagation issue'

  if (PID_Controller_B.DeadZone_f > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  // Switch: '<S90>/Switch2' incorporates:
  //   Constant: '<S90>/Clamping_zero'
  //   Constant: '<S90>/Constant3'
  //   Constant: '<S90>/Constant4'
  //   RelationalOperator: '<S90>/fix for DT propagation issue1'

  if (PID_Controller_B.y > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  // Switch: '<S90>/Switch' incorporates:
  //   Constant: '<S90>/Clamping_zero'
  //   Constant: '<S90>/Constant1'
  //   Logic: '<S90>/AND3'
  //   RelationalOperator: '<S90>/Equal1'
  //   RelationalOperator: '<S90>/Relational Operator'
  //   Switch: '<S90>/Switch1'
  //   Switch: '<S90>/Switch2'

  if ((PID_Controller_B.DeadZone_f != 0.0) && (tmp == tmp_0)) {
    PID_Controller_B.DeadZone_f = 0.0;
  } else {
    PID_Controller_B.DeadZone_f = PID_Controller_B.y;
  }

  // End of Switch: '<S90>/Switch'

  // DeadZone: '<S38>/DeadZone'
  if (PID_Controller_B.absx21 > 5.0) {
    PID_Controller_B.absx21 -= 5.0;
  } else if (PID_Controller_B.absx21 >= -5.0) {
    PID_Controller_B.absx21 = 0.0;
  } else {
    PID_Controller_B.absx21 -= -5.0;
  }

  // End of DeadZone: '<S38>/DeadZone'

  // Gain: '<S43>/Integral Gain'
  PID_Controller_B.y = 2.325 * PID_Controller_B.Sum[3];

  // Update for DiscreteIntegrator: '<S204>/Integrator' incorporates:
  //   Gain: '<S201>/Integral Gain'

  PID_Controller_DW.Integrator_DSTATE[0] += 2.74882046275699 *
    PID_Controller_B.Sum[0] * 0.01;

  // Update for DiscreteIntegrator: '<S199>/Filter' incorporates:
  //   Gain: '<S207>/Filter Coefficient'

  PID_Controller_DW.Filter_DSTATE[0] += 0.01 * PID_Controller_B.st_idx_0;

  // Update for DiscreteIntegrator: '<S204>/Integrator' incorporates:
  //   Gain: '<S201>/Integral Gain'

  PID_Controller_DW.Integrator_DSTATE[1] += 2.74882046275699 *
    PID_Controller_B.Sum[1] * 0.01;

  // Update for DiscreteIntegrator: '<S199>/Filter' incorporates:
  //   Gain: '<S207>/Filter Coefficient'

  PID_Controller_DW.Filter_DSTATE[1] += 0.01 * PID_Controller_B.st_idx_1;

  // Update for DiscreteIntegrator: '<S204>/Integrator' incorporates:
  //   Gain: '<S201>/Integral Gain'

  PID_Controller_DW.Integrator_DSTATE[2] += 2.74882046275699 *
    PID_Controller_B.Sum[2] * 0.01;

  // Update for DiscreteIntegrator: '<S199>/Filter'
  PID_Controller_DW.Filter_DSTATE[2] += 0.01 * PID_Controller_B.absx11;

  // Switch: '<S36>/Switch1' incorporates:
  //   Constant: '<S36>/Clamping_zero'
  //   Constant: '<S36>/Constant'
  //   Constant: '<S36>/Constant2'
  //   RelationalOperator: '<S36>/fix for DT propagation issue'

  if (PID_Controller_B.absx21 > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  // Switch: '<S36>/Switch2' incorporates:
  //   Constant: '<S36>/Clamping_zero'
  //   Constant: '<S36>/Constant3'
  //   Constant: '<S36>/Constant4'
  //   RelationalOperator: '<S36>/fix for DT propagation issue1'

  if (PID_Controller_B.y > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  // Switch: '<S36>/Switch' incorporates:
  //   Constant: '<S36>/Clamping_zero'
  //   Constant: '<S36>/Constant1'
  //   Logic: '<S36>/AND3'
  //   RelationalOperator: '<S36>/Equal1'
  //   RelationalOperator: '<S36>/Relational Operator'
  //   Switch: '<S36>/Switch1'
  //   Switch: '<S36>/Switch2'

  if ((PID_Controller_B.absx21 != 0.0) && (tmp == tmp_0)) {
    PID_Controller_B.y = 0.0;
  }

  // Update for DiscreteIntegrator: '<S46>/Integrator' incorporates:
  //   Switch: '<S36>/Switch'

  PID_Controller_DW.Integrator_DSTATE_m += 0.01 * PID_Controller_B.y;

  // Update for DiscreteIntegrator: '<S41>/Filter'
  PID_Controller_DW.Filter_DSTATE_e += 0.01 * PID_Controller_B.t2;

  // Update for DiscreteIntegrator: '<S100>/Integrator'
  PID_Controller_DW.Integrator_DSTATE_f += 0.01 * PID_Controller_B.DeadZone_f;

  // Update for DiscreteIntegrator: '<S95>/Filter'
  PID_Controller_DW.Filter_DSTATE_en += 0.01 * PID_Controller_B.absx31;

  // Update for DiscreteIntegrator: '<S152>/Integrator' incorporates:
  //   Gain: '<S149>/Integral Gain'

  PID_Controller_DW.Integrator_DSTATE_k += 2.479 *
    PID_Controller_B.corrected_error * 0.01;

  // Update for DiscreteIntegrator: '<S147>/Filter'
  PID_Controller_DW.Filter_DSTATE_n += 0.01 *
    PID_Controller_B.FilterCoefficient_fo;

  // End of Outputs for SubSystem: '<Root>/Controller1'
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
