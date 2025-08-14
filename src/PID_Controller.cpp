//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: PID_Controller.cpp
//
// Code generated for Simulink model 'PID_Controller'.
//
// Model version                  : 4.8
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Wed Aug 13 21:12:11 2025
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
  real_T rtb_NProdOut_h3;
  real_T tmp;
  real_T tmp_0;
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
  PID_Controller_B.absx31 = std::cos(PID_Controller_U.states[4]);
  PID_Controller_B.t1 = std::sin(PID_Controller_U.states[4]);
  PID_Controller_B.NProdOut_g = std::cos(PID_Controller_U.states[3]);
  PID_Controller_B.NProdOut_i = std::sin(PID_Controller_U.states[3]);
  PID_Controller_B.DCMbe[0] = PID_Controller_B.absx11 * PID_Controller_B.absx31;
  rtb_NProdOut_h3 = PID_Controller_B.t1 * PID_Controller_B.NProdOut_i;
  PID_Controller_B.DCMbe[3] = rtb_NProdOut_h3 * PID_Controller_B.absx11 -
    PID_Controller_B.absx21 * PID_Controller_B.NProdOut_g;
  PID_Controller_B.DeadZone_f = PID_Controller_B.t1 *
    PID_Controller_B.NProdOut_g;
  PID_Controller_B.DCMbe[6] = PID_Controller_B.DeadZone_f *
    PID_Controller_B.absx11 + PID_Controller_B.absx21 *
    PID_Controller_B.NProdOut_i;
  PID_Controller_B.DCMbe[1] = PID_Controller_B.absx21 * PID_Controller_B.absx31;
  PID_Controller_B.DCMbe[4] = rtb_NProdOut_h3 * PID_Controller_B.absx21 +
    PID_Controller_B.absx11 * PID_Controller_B.NProdOut_g;
  PID_Controller_B.DCMbe[7] = PID_Controller_B.DeadZone_f *
    PID_Controller_B.absx21 - PID_Controller_B.absx11 *
    PID_Controller_B.NProdOut_i;
  PID_Controller_B.DCMbe[2] = -PID_Controller_B.t1;
  PID_Controller_B.DCMbe[5] = PID_Controller_B.absx31 *
    PID_Controller_B.NProdOut_i;
  PID_Controller_B.DCMbe[8] = PID_Controller_B.absx31 *
    PID_Controller_B.NProdOut_g;
  std::memcpy(&PID_Controller_B.x[0], &PID_Controller_B.DCMbe[0], 9U * sizeof
              (real_T));
  i = 0;
  p2 = 3;
  p3 = 6;
  PID_Controller_B.absx11 = std::abs(PID_Controller_B.DCMbe[0]);
  PID_Controller_B.absx21 = std::abs(PID_Controller_B.DCMbe[1]);
  PID_Controller_B.absx31 = std::abs(-PID_Controller_B.t1);
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
    PID_Controller_B.x[0] = -PID_Controller_B.t1;
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
    PID_Controller_B.t1 = PID_Controller_B.x[1];
    PID_Controller_B.x[1] = PID_Controller_B.x[2];
    PID_Controller_B.x[2] = PID_Controller_B.t1;
    PID_Controller_B.t1 = PID_Controller_B.x[4];
    PID_Controller_B.x[4] = PID_Controller_B.x[5];
    PID_Controller_B.x[5] = PID_Controller_B.t1;
    PID_Controller_B.t1 = PID_Controller_B.x[7];
    PID_Controller_B.x[7] = PID_Controller_B.x[8];
    PID_Controller_B.x[8] = PID_Controller_B.t1;
  }

  PID_Controller_B.x[5] /= PID_Controller_B.x[4];
  PID_Controller_B.x[8] -= PID_Controller_B.x[5] * PID_Controller_B.x[7];
  PID_Controller_B.t1 = (PID_Controller_B.x[1] * PID_Controller_B.x[5] -
    PID_Controller_B.x[2]) / PID_Controller_B.x[8];
  PID_Controller_B.absx11 = -(PID_Controller_B.x[7] * PID_Controller_B.t1 +
    PID_Controller_B.x[1]) / PID_Controller_B.x[4];
  PID_Controller_B.DCMeb[i] = ((1.0 - PID_Controller_B.x[3] *
    PID_Controller_B.absx11) - PID_Controller_B.x[6] * PID_Controller_B.t1) /
    PID_Controller_B.x[0];
  PID_Controller_B.DCMeb[i + 1] = PID_Controller_B.absx11;
  PID_Controller_B.DCMeb[i + 2] = PID_Controller_B.t1;
  PID_Controller_B.t1 = -PID_Controller_B.x[5] / PID_Controller_B.x[8];
  PID_Controller_B.absx11 = (1.0 - PID_Controller_B.x[7] * PID_Controller_B.t1) /
    PID_Controller_B.x[4];
  PID_Controller_B.DCMeb[p2] = -(PID_Controller_B.x[3] * PID_Controller_B.absx11
    + PID_Controller_B.x[6] * PID_Controller_B.t1) / PID_Controller_B.x[0];
  PID_Controller_B.DCMeb[p2 + 1] = PID_Controller_B.absx11;
  PID_Controller_B.DCMeb[p2 + 2] = PID_Controller_B.t1;
  PID_Controller_B.t1 = 1.0 / PID_Controller_B.x[8];
  PID_Controller_B.absx11 = -PID_Controller_B.x[7] * PID_Controller_B.t1 /
    PID_Controller_B.x[4];
  PID_Controller_B.DCMeb[p3] = -(PID_Controller_B.x[3] * PID_Controller_B.absx11
    + PID_Controller_B.x[6] * PID_Controller_B.t1) / PID_Controller_B.x[0];
  PID_Controller_B.DCMeb[p3 + 1] = PID_Controller_B.absx11;
  PID_Controller_B.DCMeb[p3 + 2] = PID_Controller_B.t1;
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

  // Product: '<S268>/NProd Out' incorporates:
  //   DiscreteIntegrator: '<S260>/Filter'
  //   Inport: '<Root>/PIDN_X'
  //   Product: '<S258>/DProd Out'
  //   Sum: '<S260>/SumD'

  PID_Controller_B.t1 = (PID_Controller_B.Sum[0] * PID_Controller_U.PIDN_X[2] -
    PID_Controller_DW.Filter_DSTATE) * PID_Controller_U.PIDN_X[3];

  // Sum: '<S274>/Sum' incorporates:
  //   DiscreteIntegrator: '<S265>/Integrator'
  //   Inport: '<Root>/PIDN_X'
  //   Product: '<S270>/PProd Out'

  PID_Controller_B.absx11 = (PID_Controller_B.Sum[0] * PID_Controller_U.PIDN_X[0]
    + PID_Controller_DW.Integrator_DSTATE) + PID_Controller_B.t1;

  // Product: '<S322>/NProd Out' incorporates:
  //   DiscreteIntegrator: '<S314>/Filter'
  //   Inport: '<Root>/PIDN_Y'
  //   Product: '<S312>/DProd Out'
  //   Sum: '<S314>/SumD'

  PID_Controller_B.absx21 = (PID_Controller_B.Sum[1] * PID_Controller_U.PIDN_Y[2]
    - PID_Controller_DW.Filter_DSTATE_m) * PID_Controller_U.PIDN_Y[3];

  // Sum: '<S328>/Sum' incorporates:
  //   DiscreteIntegrator: '<S319>/Integrator'
  //   Inport: '<Root>/PIDN_Y'
  //   Product: '<S324>/PProd Out'

  PID_Controller_B.DeadZone_f = (PID_Controller_U.PIDN_Y[0] *
    PID_Controller_B.Sum[1] + PID_Controller_DW.Integrator_DSTATE_a) +
    PID_Controller_B.absx21;

  // Product: '<S214>/NProd Out' incorporates:
  //   DiscreteIntegrator: '<S206>/Filter'
  //   Inport: '<Root>/PIDN_Z'
  //   Product: '<S204>/DProd Out'
  //   Sum: '<S206>/SumD'

  PID_Controller_B.absx31 = (PID_Controller_B.Sum[2] * PID_Controller_U.PIDN_Z[2]
    - PID_Controller_DW.Filter_DSTATE_a) * PID_Controller_U.PIDN_Z[3];

  // Sum: '<S220>/Sum' incorporates:
  //   DiscreteIntegrator: '<S211>/Integrator'
  //   Inport: '<Root>/PIDN_Z'
  //   Product: '<S216>/PProd Out'

  PID_Controller_B.DeadZone_k = (PID_Controller_U.PIDN_Z[0] *
    PID_Controller_B.Sum[2] + PID_Controller_DW.Integrator_DSTATE_h) +
    PID_Controller_B.absx31;

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

  // Product: '<S52>/NProd Out' incorporates:
  //   DiscreteIntegrator: '<S44>/Filter'
  //   Inport: '<Root>/PIDN_yaw'
  //   Product: '<S42>/DProd Out'
  //   Sum: '<S44>/SumD'

  PID_Controller_B.NProdOut_g = (PID_Controller_B.corrected_error *
    PID_Controller_U.PIDN_yaw[2] - PID_Controller_DW.Filter_DSTATE_h) *
    PID_Controller_U.PIDN_yaw[3];

  // Sum: '<S58>/Sum' incorporates:
  //   DiscreteIntegrator: '<S49>/Integrator'
  //   Inport: '<Root>/PIDN_yaw'
  //   Product: '<S54>/PProd Out'

  PID_Controller_B.DeadZone_b = (PID_Controller_B.corrected_error *
    PID_Controller_U.PIDN_yaw[0] + PID_Controller_DW.Integrator_DSTATE_g) +
    PID_Controller_B.NProdOut_g;

  // Product: '<S106>/NProd Out' incorporates:
  //   DiscreteIntegrator: '<S98>/Filter'
  //   Inport: '<Root>/PIDN_pitch'
  //   Product: '<S96>/DProd Out'
  //   Sum: '<S98>/SumD'

  PID_Controller_B.NProdOut_i = (PID_Controller_U.PIDN_pitch[2] *
    PID_Controller_B.Sum[4] - PID_Controller_DW.Filter_DSTATE_o) *
    PID_Controller_U.PIDN_pitch[3];

  // Sum: '<S112>/Sum' incorporates:
  //   DiscreteIntegrator: '<S103>/Integrator'
  //   Inport: '<Root>/PIDN_pitch'
  //   Product: '<S108>/PProd Out'

  PID_Controller_B.DeadZone_e = (PID_Controller_U.PIDN_pitch[0] *
    PID_Controller_B.Sum[4] + PID_Controller_DW.Integrator_DSTATE_l) +
    PID_Controller_B.NProdOut_i;

  // Product: '<S160>/NProd Out' incorporates:
  //   DiscreteIntegrator: '<S152>/Filter'
  //   Inport: '<Root>/PIDN_roll'
  //   Product: '<S150>/DProd Out'
  //   Sum: '<S152>/SumD'

  rtb_NProdOut_h3 = (PID_Controller_U.PIDN_roll[2] * PID_Controller_B.Sum[3] -
                     PID_Controller_DW.Filter_DSTATE_n) *
    PID_Controller_U.PIDN_roll[3];

  // Sum: '<S166>/Sum' incorporates:
  //   DiscreteIntegrator: '<S157>/Integrator'
  //   Inport: '<Root>/PIDN_roll'
  //   Product: '<S162>/PProd Out'

  PID_Controller_B.DeadZone_j = (PID_Controller_U.PIDN_roll[0] *
    PID_Controller_B.Sum[3] + PID_Controller_DW.Integrator_DSTATE_h3) +
    rtb_NProdOut_h3;

  // Saturate: '<S272>/Saturation'
  if (PID_Controller_B.absx11 > 24.0) {
    PID_Controller_B.y = 24.0;
  } else if (PID_Controller_B.absx11 < -24.0) {
    PID_Controller_B.y = -24.0;
  } else {
    PID_Controller_B.y = PID_Controller_B.absx11;
  }

  // Saturate: '<S326>/Saturation'
  if (PID_Controller_B.DeadZone_f > 24.0) {
    tmp_0 = 24.0;
  } else if (PID_Controller_B.DeadZone_f < -24.0) {
    tmp_0 = -24.0;
  } else {
    tmp_0 = PID_Controller_B.DeadZone_f;
  }

  // Saturate: '<S218>/Saturation'
  if (PID_Controller_B.DeadZone_k > 24.0) {
    tmp = 24.0;
  } else if (PID_Controller_B.DeadZone_k < -24.0) {
    tmp = -24.0;
  } else {
    tmp = PID_Controller_B.DeadZone_k;
  }

  for (p2 = 0; p2 < 3; p2++) {
    // SignalConversion generated from: '<S1>/Maps forces to pwms' incorporates:
    //   Product: '<S2>/Matrix Multiply'
    //   Saturate: '<S218>/Saturation'
    //   Saturate: '<S272>/Saturation'
    //   Saturate: '<S326>/Saturation'

    PID_Controller_B.rtb_DCMbe_m[p2] = (PID_Controller_B.DCMbe[p2 + 3] * tmp_0 +
      PID_Controller_B.DCMbe[p2] * PID_Controller_B.y) +
      PID_Controller_B.DCMbe[p2 + 6] * tmp;
  }

  // Saturate: '<S164>/Saturation'
  if (PID_Controller_B.DeadZone_j > 24.0) {
    // SignalConversion generated from: '<S1>/Maps forces to pwms'
    PID_Controller_B.rtb_DCMbe_m[3] = 24.0;
  } else if (PID_Controller_B.DeadZone_j < -24.0) {
    // SignalConversion generated from: '<S1>/Maps forces to pwms'
    PID_Controller_B.rtb_DCMbe_m[3] = -24.0;
  } else {
    // SignalConversion generated from: '<S1>/Maps forces to pwms'
    PID_Controller_B.rtb_DCMbe_m[3] = PID_Controller_B.DeadZone_j;
  }

  // End of Saturate: '<S164>/Saturation'

  // Saturate: '<S110>/Saturation'
  if (PID_Controller_B.DeadZone_e > 24.0) {
    // SignalConversion generated from: '<S1>/Maps forces to pwms'
    PID_Controller_B.rtb_DCMbe_m[4] = 24.0;
  } else if (PID_Controller_B.DeadZone_e < -24.0) {
    // SignalConversion generated from: '<S1>/Maps forces to pwms'
    PID_Controller_B.rtb_DCMbe_m[4] = -24.0;
  } else {
    // SignalConversion generated from: '<S1>/Maps forces to pwms'
    PID_Controller_B.rtb_DCMbe_m[4] = PID_Controller_B.DeadZone_e;
  }

  // End of Saturate: '<S110>/Saturation'

  // Saturate: '<S56>/Saturation'
  if (PID_Controller_B.DeadZone_b > 24.0) {
    // SignalConversion generated from: '<S1>/Maps forces to pwms'
    PID_Controller_B.rtb_DCMbe_m[5] = 24.0;
  } else if (PID_Controller_B.DeadZone_b < -24.0) {
    // SignalConversion generated from: '<S1>/Maps forces to pwms'
    PID_Controller_B.rtb_DCMbe_m[5] = -24.0;
  } else {
    // SignalConversion generated from: '<S1>/Maps forces to pwms'
    PID_Controller_B.rtb_DCMbe_m[5] = PID_Controller_B.DeadZone_b;
  }

  // End of Saturate: '<S56>/Saturation'
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

  // DeadZone: '<S149>/DeadZone'
  if (PID_Controller_B.DeadZone_j > 24.0) {
    PID_Controller_B.DeadZone_j -= 24.0;
  } else if (PID_Controller_B.DeadZone_j >= -24.0) {
    PID_Controller_B.DeadZone_j = 0.0;
  } else {
    PID_Controller_B.DeadZone_j -= -24.0;
  }

  // End of DeadZone: '<S149>/DeadZone'

  // Product: '<S154>/IProd Out' incorporates:
  //   Inport: '<Root>/PIDN_roll'

  PID_Controller_B.y = PID_Controller_U.PIDN_roll[1] * PID_Controller_B.Sum[3];

  // Switch: '<S147>/Switch1' incorporates:
  //   Constant: '<S147>/Clamping_zero'
  //   Constant: '<S147>/Constant'
  //   Constant: '<S147>/Constant2'
  //   RelationalOperator: '<S147>/fix for DT propagation issue'

  if (PID_Controller_B.DeadZone_j > 0.0) {
    tmp_1 = 1;
  } else {
    tmp_1 = -1;
  }

  // Switch: '<S147>/Switch2' incorporates:
  //   Constant: '<S147>/Clamping_zero'
  //   Constant: '<S147>/Constant3'
  //   Constant: '<S147>/Constant4'
  //   RelationalOperator: '<S147>/fix for DT propagation issue1'

  if (PID_Controller_B.y > 0.0) {
    tmp_2 = 1;
  } else {
    tmp_2 = -1;
  }

  // Switch: '<S147>/Switch' incorporates:
  //   Constant: '<S147>/Clamping_zero'
  //   Constant: '<S147>/Constant1'
  //   Logic: '<S147>/AND3'
  //   RelationalOperator: '<S147>/Equal1'
  //   RelationalOperator: '<S147>/Relational Operator'
  //   Switch: '<S147>/Switch1'
  //   Switch: '<S147>/Switch2'

  if ((PID_Controller_B.DeadZone_j != 0.0) && (tmp_1 == tmp_2)) {
    PID_Controller_B.DeadZone_j = 0.0;
  } else {
    PID_Controller_B.DeadZone_j = PID_Controller_B.y;
  }

  // End of Switch: '<S147>/Switch'

  // DeadZone: '<S95>/DeadZone'
  if (PID_Controller_B.DeadZone_e > 24.0) {
    PID_Controller_B.DeadZone_e -= 24.0;
  } else if (PID_Controller_B.DeadZone_e >= -24.0) {
    PID_Controller_B.DeadZone_e = 0.0;
  } else {
    PID_Controller_B.DeadZone_e -= -24.0;
  }

  // End of DeadZone: '<S95>/DeadZone'

  // Product: '<S100>/IProd Out' incorporates:
  //   Inport: '<Root>/PIDN_pitch'

  PID_Controller_B.y = PID_Controller_U.PIDN_pitch[1] * PID_Controller_B.Sum[4];

  // Switch: '<S93>/Switch1' incorporates:
  //   Constant: '<S93>/Clamping_zero'
  //   Constant: '<S93>/Constant'
  //   Constant: '<S93>/Constant2'
  //   RelationalOperator: '<S93>/fix for DT propagation issue'

  if (PID_Controller_B.DeadZone_e > 0.0) {
    tmp_1 = 1;
  } else {
    tmp_1 = -1;
  }

  // Switch: '<S93>/Switch2' incorporates:
  //   Constant: '<S93>/Clamping_zero'
  //   Constant: '<S93>/Constant3'
  //   Constant: '<S93>/Constant4'
  //   RelationalOperator: '<S93>/fix for DT propagation issue1'

  if (PID_Controller_B.y > 0.0) {
    tmp_2 = 1;
  } else {
    tmp_2 = -1;
  }

  // Switch: '<S93>/Switch' incorporates:
  //   Constant: '<S93>/Clamping_zero'
  //   Constant: '<S93>/Constant1'
  //   Logic: '<S93>/AND3'
  //   RelationalOperator: '<S93>/Equal1'
  //   RelationalOperator: '<S93>/Relational Operator'
  //   Switch: '<S93>/Switch1'
  //   Switch: '<S93>/Switch2'

  if ((PID_Controller_B.DeadZone_e != 0.0) && (tmp_1 == tmp_2)) {
    PID_Controller_B.DeadZone_e = 0.0;
  } else {
    PID_Controller_B.DeadZone_e = PID_Controller_B.y;
  }

  // End of Switch: '<S93>/Switch'

  // DeadZone: '<S41>/DeadZone'
  if (PID_Controller_B.DeadZone_b > 24.0) {
    PID_Controller_B.DeadZone_b -= 24.0;
  } else if (PID_Controller_B.DeadZone_b >= -24.0) {
    PID_Controller_B.DeadZone_b = 0.0;
  } else {
    PID_Controller_B.DeadZone_b -= -24.0;
  }

  // End of DeadZone: '<S41>/DeadZone'

  // Product: '<S46>/IProd Out' incorporates:
  //   Inport: '<Root>/PIDN_yaw'

  PID_Controller_B.y = PID_Controller_B.corrected_error *
    PID_Controller_U.PIDN_yaw[1];

  // Switch: '<S39>/Switch1' incorporates:
  //   Constant: '<S39>/Clamping_zero'
  //   Constant: '<S39>/Constant'
  //   Constant: '<S39>/Constant2'
  //   RelationalOperator: '<S39>/fix for DT propagation issue'

  if (PID_Controller_B.DeadZone_b > 0.0) {
    tmp_1 = 1;
  } else {
    tmp_1 = -1;
  }

  // Switch: '<S39>/Switch2' incorporates:
  //   Constant: '<S39>/Clamping_zero'
  //   Constant: '<S39>/Constant3'
  //   Constant: '<S39>/Constant4'
  //   RelationalOperator: '<S39>/fix for DT propagation issue1'

  if (PID_Controller_B.y > 0.0) {
    tmp_2 = 1;
  } else {
    tmp_2 = -1;
  }

  // Switch: '<S39>/Switch' incorporates:
  //   Constant: '<S39>/Clamping_zero'
  //   Constant: '<S39>/Constant1'
  //   Logic: '<S39>/AND3'
  //   RelationalOperator: '<S39>/Equal1'
  //   RelationalOperator: '<S39>/Relational Operator'
  //   Switch: '<S39>/Switch1'
  //   Switch: '<S39>/Switch2'

  if ((PID_Controller_B.DeadZone_b != 0.0) && (tmp_1 == tmp_2)) {
    PID_Controller_B.corrected_error = 0.0;
  } else {
    PID_Controller_B.corrected_error = PID_Controller_B.y;
  }

  // End of Switch: '<S39>/Switch'

  // DeadZone: '<S203>/DeadZone'
  if (PID_Controller_B.DeadZone_k > 24.0) {
    PID_Controller_B.DeadZone_k -= 24.0;
  } else if (PID_Controller_B.DeadZone_k >= -24.0) {
    PID_Controller_B.DeadZone_k = 0.0;
  } else {
    PID_Controller_B.DeadZone_k -= -24.0;
  }

  // End of DeadZone: '<S203>/DeadZone'

  // Product: '<S208>/IProd Out' incorporates:
  //   Inport: '<Root>/PIDN_Z'

  PID_Controller_B.y = PID_Controller_U.PIDN_Z[1] * PID_Controller_B.Sum[2];

  // Switch: '<S201>/Switch1' incorporates:
  //   Constant: '<S201>/Clamping_zero'
  //   Constant: '<S201>/Constant'
  //   Constant: '<S201>/Constant2'
  //   RelationalOperator: '<S201>/fix for DT propagation issue'

  if (PID_Controller_B.DeadZone_k > 0.0) {
    tmp_1 = 1;
  } else {
    tmp_1 = -1;
  }

  // Switch: '<S201>/Switch2' incorporates:
  //   Constant: '<S201>/Clamping_zero'
  //   Constant: '<S201>/Constant3'
  //   Constant: '<S201>/Constant4'
  //   RelationalOperator: '<S201>/fix for DT propagation issue1'

  if (PID_Controller_B.y > 0.0) {
    tmp_2 = 1;
  } else {
    tmp_2 = -1;
  }

  // Switch: '<S201>/Switch' incorporates:
  //   Constant: '<S201>/Clamping_zero'
  //   Constant: '<S201>/Constant1'
  //   Logic: '<S201>/AND3'
  //   RelationalOperator: '<S201>/Equal1'
  //   RelationalOperator: '<S201>/Relational Operator'
  //   Switch: '<S201>/Switch1'
  //   Switch: '<S201>/Switch2'

  if ((PID_Controller_B.DeadZone_k != 0.0) && (tmp_1 == tmp_2)) {
    PID_Controller_B.DeadZone_k = 0.0;
  } else {
    PID_Controller_B.DeadZone_k = PID_Controller_B.y;
  }

  // End of Switch: '<S201>/Switch'

  // DeadZone: '<S311>/DeadZone'
  if (PID_Controller_B.DeadZone_f > 24.0) {
    PID_Controller_B.DeadZone_f -= 24.0;
  } else if (PID_Controller_B.DeadZone_f >= -24.0) {
    PID_Controller_B.DeadZone_f = 0.0;
  } else {
    PID_Controller_B.DeadZone_f -= -24.0;
  }

  // End of DeadZone: '<S311>/DeadZone'

  // Product: '<S316>/IProd Out' incorporates:
  //   Inport: '<Root>/PIDN_Y'

  PID_Controller_B.y = PID_Controller_B.Sum[1] * PID_Controller_U.PIDN_Y[1];

  // Switch: '<S309>/Switch1' incorporates:
  //   Constant: '<S309>/Clamping_zero'
  //   Constant: '<S309>/Constant'
  //   Constant: '<S309>/Constant2'
  //   RelationalOperator: '<S309>/fix for DT propagation issue'

  if (PID_Controller_B.DeadZone_f > 0.0) {
    tmp_1 = 1;
  } else {
    tmp_1 = -1;
  }

  // Switch: '<S309>/Switch2' incorporates:
  //   Constant: '<S309>/Clamping_zero'
  //   Constant: '<S309>/Constant3'
  //   Constant: '<S309>/Constant4'
  //   RelationalOperator: '<S309>/fix for DT propagation issue1'

  if (PID_Controller_B.y > 0.0) {
    tmp_2 = 1;
  } else {
    tmp_2 = -1;
  }

  // Switch: '<S309>/Switch' incorporates:
  //   Constant: '<S309>/Clamping_zero'
  //   Constant: '<S309>/Constant1'
  //   Logic: '<S309>/AND3'
  //   RelationalOperator: '<S309>/Equal1'
  //   RelationalOperator: '<S309>/Relational Operator'
  //   Switch: '<S309>/Switch1'
  //   Switch: '<S309>/Switch2'

  if ((PID_Controller_B.DeadZone_f != 0.0) && (tmp_1 == tmp_2)) {
    PID_Controller_B.DeadZone_f = 0.0;
  } else {
    PID_Controller_B.DeadZone_f = PID_Controller_B.y;
  }

  // End of Switch: '<S309>/Switch'

  // DeadZone: '<S257>/DeadZone'
  if (PID_Controller_B.absx11 > 24.0) {
    PID_Controller_B.absx11 -= 24.0;
  } else if (PID_Controller_B.absx11 >= -24.0) {
    PID_Controller_B.absx11 = 0.0;
  } else {
    PID_Controller_B.absx11 -= -24.0;
  }

  // End of DeadZone: '<S257>/DeadZone'

  // Product: '<S262>/IProd Out' incorporates:
  //   Inport: '<Root>/PIDN_X'

  PID_Controller_B.y = PID_Controller_B.Sum[0] * PID_Controller_U.PIDN_X[1];

  // Switch: '<S255>/Switch1' incorporates:
  //   Constant: '<S255>/Clamping_zero'
  //   Constant: '<S255>/Constant'
  //   Constant: '<S255>/Constant2'
  //   RelationalOperator: '<S255>/fix for DT propagation issue'

  if (PID_Controller_B.absx11 > 0.0) {
    tmp_1 = 1;
  } else {
    tmp_1 = -1;
  }

  // Switch: '<S255>/Switch2' incorporates:
  //   Constant: '<S255>/Clamping_zero'
  //   Constant: '<S255>/Constant3'
  //   Constant: '<S255>/Constant4'
  //   RelationalOperator: '<S255>/fix for DT propagation issue1'

  if (PID_Controller_B.y > 0.0) {
    tmp_2 = 1;
  } else {
    tmp_2 = -1;
  }

  // Switch: '<S255>/Switch' incorporates:
  //   Constant: '<S255>/Clamping_zero'
  //   Constant: '<S255>/Constant1'
  //   Logic: '<S255>/AND3'
  //   RelationalOperator: '<S255>/Equal1'
  //   RelationalOperator: '<S255>/Relational Operator'
  //   Switch: '<S255>/Switch1'
  //   Switch: '<S255>/Switch2'

  if ((PID_Controller_B.absx11 != 0.0) && (tmp_1 == tmp_2)) {
    PID_Controller_B.y = 0.0;
  }

  // Update for DiscreteIntegrator: '<S265>/Integrator' incorporates:
  //   Switch: '<S255>/Switch'

  PID_Controller_DW.Integrator_DSTATE += 0.01 * PID_Controller_B.y;

  // Update for DiscreteIntegrator: '<S260>/Filter'
  PID_Controller_DW.Filter_DSTATE += 0.01 * PID_Controller_B.t1;

  // Update for DiscreteIntegrator: '<S319>/Integrator'
  PID_Controller_DW.Integrator_DSTATE_a += 0.01 * PID_Controller_B.DeadZone_f;

  // Update for DiscreteIntegrator: '<S314>/Filter'
  PID_Controller_DW.Filter_DSTATE_m += 0.01 * PID_Controller_B.absx21;

  // Update for DiscreteIntegrator: '<S211>/Integrator'
  PID_Controller_DW.Integrator_DSTATE_h += 0.01 * PID_Controller_B.DeadZone_k;

  // Update for DiscreteIntegrator: '<S206>/Filter'
  PID_Controller_DW.Filter_DSTATE_a += 0.01 * PID_Controller_B.absx31;

  // Update for DiscreteIntegrator: '<S49>/Integrator'
  PID_Controller_DW.Integrator_DSTATE_g += 0.01 *
    PID_Controller_B.corrected_error;

  // Update for DiscreteIntegrator: '<S44>/Filter'
  PID_Controller_DW.Filter_DSTATE_h += 0.01 * PID_Controller_B.NProdOut_g;

  // Update for DiscreteIntegrator: '<S103>/Integrator'
  PID_Controller_DW.Integrator_DSTATE_l += 0.01 * PID_Controller_B.DeadZone_e;

  // Update for DiscreteIntegrator: '<S98>/Filter'
  PID_Controller_DW.Filter_DSTATE_o += 0.01 * PID_Controller_B.NProdOut_i;

  // Update for DiscreteIntegrator: '<S157>/Integrator'
  PID_Controller_DW.Integrator_DSTATE_h3 += 0.01 * PID_Controller_B.DeadZone_j;

  // Update for DiscreteIntegrator: '<S152>/Filter'
  PID_Controller_DW.Filter_DSTATE_n += 0.01 * rtb_NProdOut_h3;

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
