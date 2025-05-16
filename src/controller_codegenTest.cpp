//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controller_codegenTest.cpp
//
// Code generated for Simulink model 'controller_codegenTest'.
//
// Model version                  : 1.4
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Tue May 13 21:32:40 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Custom Processor->Custom Processor
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#include "controller_codegenTest.h"
#include <cmath>
#include "rtwtypes.h"
#include "cmath"
#include "limits"

extern real_T rt_powd_snf(real_T u0, real_T u1);
extern "C"
{
  real_T rtNaN { -std::numeric_limits<real_T>::quiet_NaN() };

  real_T rtInf { std::numeric_limits<real_T>::infinity() };

  real_T rtMinusInf { -std::numeric_limits<real_T>::infinity() };

  real32_T rtNaNF { -std::numeric_limits<real32_T>::quiet_NaN() };

  real32_T rtInfF { std::numeric_limits<real32_T>::infinity() };

  real32_T rtMinusInfF { -std::numeric_limits<real32_T>::infinity() };
}

extern "C"
{
  // Return rtInf needed by the generated code.
  static real_T rtGetInf(void)
  {
    return rtInf;
  }

  // Get rtInfF needed by the generated code.
  static real32_T rtGetInfF(void)
  {
    return rtInfF;
  }

  // Return rtMinusInf needed by the generated code.
  static real_T rtGetMinusInf(void)
  {
    return rtMinusInf;
  }

  // Return rtMinusInfF needed by the generated code.
  static real32_T rtGetMinusInfF(void)
  {
    return rtMinusInfF;
  }
}

extern "C"
{
  // Return rtNaN needed by the generated code.
  static real_T rtGetNaN(void)
  {
    return rtNaN;
  }

  // Return rtNaNF needed by the generated code.
  static real32_T rtGetNaNF(void)
  {
    return rtNaNF;
  }
}

extern "C"
{
  // Test if value is infinite
  static boolean_T rtIsInf(real_T value)
  {
    return std::isinf(value);
  }

  // Test if single-precision value is infinite
  static boolean_T rtIsInfF(real32_T value)
  {
    return std::isinf(value);
  }

  // Test if value is not a number
  static boolean_T rtIsNaN(real_T value)
  {
    return std::isnan(value);
  }

  // Test if single-precision value is not a number
  static boolean_T rtIsNaNF(real32_T value)
  {
    return std::isnan(value);
  }
}

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
void controller_codegenTest::step()
{
  real_T tmp[6];
  real_T pitch_flag;
  real_T roll_flag;
  real_T rtb_NProdOut_0;
  real_T rtb_NProdOut_idx_0;
  real_T rtb_NProdOut_idx_1;
  real_T rtb_xyz_idx_0;
  real_T rtb_xyz_idx_1;
  real_T rtb_xyz_idx_2;
  real_T rtb_xyz_idx_3;
  real_T rtb_yaw_idx_0;
  real_T rtb_yaw_idx_1;
  real_T rtb_yaw_idx_2;
  real_T rtb_yaw_idx_3;
  real_T u0;
  real_T u0_0;
  real_T yaw_flag;
  int32_T i;
  int32_T i_0;

  // Outputs for Atomic SubSystem: '<Root>/Controller'
  // MATLAB Function: '<S2>/Gain Scheduler' incorporates:
  //   DataStoreWrite: '<S2>/Data Store Write'
  //   Inport: '<Root>/Input'

  yaw_flag = std::abs(rtU.Input[5]);
  if (yaw_flag >= 0.087266462599716474) {
    yaw_flag = 1.0;
  } else if (yaw_flag < 0.017453292519943295) {
    yaw_flag = 0.0;
  } else {
    yaw_flag = rtDW.flags[2];
  }

  roll_flag = std::abs(rtU.Input[4]);
  if (roll_flag >= 0.087266462599716474) {
    pitch_flag = 1.0;
    yaw_flag = 0.0;
  } else if (roll_flag < 0.017453292519943295) {
    pitch_flag = 0.0;
  } else {
    pitch_flag = rtDW.flags[1];
    yaw_flag = 0.0;
  }

  roll_flag = std::abs(rtU.Input[3]);
  if (roll_flag >= 0.087266462599716474) {
    roll_flag = 1.0;
    yaw_flag = 0.0;
  } else if (roll_flag < 0.017453292519943295) {
    roll_flag = 0.0;
  } else {
    roll_flag = rtDW.flags[0];
    yaw_flag = 0.0;
  }

  if ((roll_flag == 1.0) || (pitch_flag == 1.0)) {
    rtb_yaw_idx_0 = 0.0;
    rtb_xyz_idx_0 = 0.0;
    rtb_yaw_idx_1 = 0.0;
    rtb_xyz_idx_1 = 0.0;
    rtb_yaw_idx_2 = 0.0;
    rtb_xyz_idx_2 = 0.0;
    rtb_yaw_idx_3 = 0.0;
    rtb_xyz_idx_3 = 1.0;
  } else if (yaw_flag == 1.0) {
    rtb_yaw_idx_0 = 6.782;
    rtb_xyz_idx_0 = 0.0;
    rtb_yaw_idx_1 = 2.479;
    rtb_xyz_idx_1 = 0.0;
    rtb_yaw_idx_2 = 2.957;
    rtb_xyz_idx_2 = 0.0;
    rtb_yaw_idx_3 = 1142.828;
    rtb_xyz_idx_3 = 1.0;
  } else {
    rtb_xyz_idx_0 = 18.568;
    rtb_yaw_idx_0 = 6.782;
    rtb_xyz_idx_1 = 2.749;
    rtb_yaw_idx_1 = 2.479;
    rtb_xyz_idx_2 = 30.798;
    rtb_yaw_idx_2 = 2.957;
    rtb_xyz_idx_3 = 17.247;
    rtb_yaw_idx_3 = 1142.828;
  }

  rtDW.flags[0] = roll_flag;
  rtDW.flags[1] = pitch_flag;
  rtDW.flags[2] = yaw_flag;

  // End of MATLAB Function: '<S2>/Gain Scheduler'

  // Product: '<S96>/NProd Out' incorporates:
  //   DiscreteIntegrator: '<S88>/Filter'
  //   Inport: '<Root>/Input'
  //   Product: '<S86>/DProd Out'
  //   Sum: '<S88>/SumD'

  yaw_flag = (2.504 * rtU.Input[3] - rtDW.Filter_DSTATE_j) * 54.54;

  // Product: '<S146>/NProd Out' incorporates:
  //   DiscreteIntegrator: '<S138>/Filter'
  //   Inport: '<Root>/Input'
  //   Product: '<S136>/DProd Out'
  //   Sum: '<S138>/SumD'

  pitch_flag = (3.625 * rtU.Input[4] - rtDW.Filter_DSTATE_k) * 54.54;

  // MATLAB Function: '<S2>/Yaw Cross-Talk Corrector' incorporates:
  //   Inport: '<Root>/Input'

  if (rtU.Input[5] > 180.0) {
    roll_flag = rtU.Input[5] - 360.0;
  } else if (rtU.Input[5] < -180.0) {
    roll_flag = rtU.Input[5] + 360.0;
  } else {
    roll_flag = rtU.Input[5];
  }

  // End of MATLAB Function: '<S2>/Yaw Cross-Talk Corrector'

  // Product: '<S196>/NProd Out' incorporates:
  //   DiscreteIntegrator: '<S188>/Filter'
  //   Product: '<S186>/DProd Out'
  //   Sum: '<S188>/SumD'

  rtb_yaw_idx_2 = (roll_flag * rtb_yaw_idx_2 - rtDW.Filter_DSTATE_b) *
    rtb_yaw_idx_3;

  // Sum: '<S102>/Sum' incorporates:
  //   DiscreteIntegrator: '<S93>/Integrator'
  //   Inport: '<Root>/Input'
  //   Product: '<S98>/PProd Out'

  rtb_yaw_idx_3 = (4.773 * rtU.Input[3] + rtDW.Integrator_DSTATE_k) + yaw_flag;

  // Sum: '<S152>/Sum' incorporates:
  //   DiscreteIntegrator: '<S143>/Integrator'
  //   Inport: '<Root>/Input'
  //   Product: '<S148>/PProd Out'

  u0 = (6.912 * rtU.Input[4] + rtDW.Integrator_DSTATE_o) + pitch_flag;

  // Sum: '<S202>/Sum' incorporates:
  //   DiscreteIntegrator: '<S193>/Integrator'
  //   Product: '<S198>/PProd Out'

  rtb_yaw_idx_0 = (roll_flag * rtb_yaw_idx_0 + rtDW.Integrator_DSTATE_a) +
    rtb_yaw_idx_2;

  // Product: '<S46>/NProd Out' incorporates:
  //   DiscreteIntegrator: '<S38>/Filter'
  //   Inport: '<Root>/Input'
  //   Product: '<S36>/DProd Out'
  //   Sum: '<S38>/SumD'

  rtb_NProdOut_0 = (rtU.Input[0] * rtb_xyz_idx_2 - rtDW.Filter_DSTATE[0]) *
    rtb_xyz_idx_3;
  rtb_NProdOut_idx_0 = rtb_NProdOut_0;

  // Saturate: '<S50>/Saturation' incorporates:
  //   DiscreteIntegrator: '<S43>/Integrator'
  //   Inport: '<Root>/Input'
  //   Product: '<S36>/DProd Out'
  //   Product: '<S48>/PProd Out'
  //   Sum: '<S52>/Sum'

  u0_0 = (rtU.Input[0] * rtb_xyz_idx_0 + rtDW.Integrator_DSTATE[0]) +
    rtb_NProdOut_0;
  if (u0_0 > 80.0) {
    // SignalConversion generated from: '<S1>/Maps forces to pwms'
    tmp[0] = 80.0;
  } else if (u0_0 < -80.0) {
    // SignalConversion generated from: '<S1>/Maps forces to pwms'
    tmp[0] = -80.0;
  } else {
    // SignalConversion generated from: '<S1>/Maps forces to pwms'
    tmp[0] = u0_0;
  }

  // Product: '<S46>/NProd Out' incorporates:
  //   DiscreteIntegrator: '<S38>/Filter'
  //   Inport: '<Root>/Input'
  //   Product: '<S36>/DProd Out'
  //   Sum: '<S38>/SumD'

  rtb_NProdOut_0 = (rtU.Input[1] * rtb_xyz_idx_2 - rtDW.Filter_DSTATE[1]) *
    rtb_xyz_idx_3;
  rtb_NProdOut_idx_1 = rtb_NProdOut_0;

  // Saturate: '<S50>/Saturation' incorporates:
  //   DiscreteIntegrator: '<S43>/Integrator'
  //   Inport: '<Root>/Input'
  //   Product: '<S36>/DProd Out'
  //   Product: '<S48>/PProd Out'
  //   Sum: '<S52>/Sum'

  u0_0 = (rtU.Input[1] * rtb_xyz_idx_0 + rtDW.Integrator_DSTATE[1]) +
    rtb_NProdOut_0;
  if (u0_0 > 80.0) {
    // SignalConversion generated from: '<S1>/Maps forces to pwms'
    tmp[1] = 80.0;
  } else if (u0_0 < -80.0) {
    // SignalConversion generated from: '<S1>/Maps forces to pwms'
    tmp[1] = -80.0;
  } else {
    // SignalConversion generated from: '<S1>/Maps forces to pwms'
    tmp[1] = u0_0;
  }

  // Product: '<S46>/NProd Out' incorporates:
  //   DiscreteIntegrator: '<S38>/Filter'
  //   Inport: '<Root>/Input'
  //   Product: '<S36>/DProd Out'
  //   Sum: '<S38>/SumD'

  rtb_NProdOut_0 = (rtU.Input[2] * rtb_xyz_idx_2 - rtDW.Filter_DSTATE[2]) *
    rtb_xyz_idx_3;

  // Saturate: '<S50>/Saturation' incorporates:
  //   DiscreteIntegrator: '<S43>/Integrator'
  //   Inport: '<Root>/Input'
  //   Product: '<S36>/DProd Out'
  //   Product: '<S48>/PProd Out'
  //   Sum: '<S52>/Sum'

  u0_0 = (rtU.Input[2] * rtb_xyz_idx_0 + rtDW.Integrator_DSTATE[2]) +
    rtb_NProdOut_0;
  if (u0_0 > 80.0) {
    // SignalConversion generated from: '<S1>/Maps forces to pwms'
    tmp[2] = 80.0;
  } else if (u0_0 < -80.0) {
    // SignalConversion generated from: '<S1>/Maps forces to pwms'
    tmp[2] = -80.0;
  } else {
    // SignalConversion generated from: '<S1>/Maps forces to pwms'
    tmp[2] = u0_0;
  }

  // Saturate: '<S100>/Saturation'
  if (rtb_yaw_idx_3 > 26.4) {
    // SignalConversion generated from: '<S1>/Maps forces to pwms'
    tmp[3] = 26.4;
  } else if (rtb_yaw_idx_3 < -26.4) {
    // SignalConversion generated from: '<S1>/Maps forces to pwms'
    tmp[3] = -26.4;
  } else {
    // SignalConversion generated from: '<S1>/Maps forces to pwms'
    tmp[3] = rtb_yaw_idx_3;
  }

  // End of Saturate: '<S100>/Saturation'

  // Saturate: '<S150>/Saturation'
  if (u0 > 30.0) {
    // SignalConversion generated from: '<S1>/Maps forces to pwms'
    tmp[4] = 30.0;
  } else if (u0 < -30.0) {
    // SignalConversion generated from: '<S1>/Maps forces to pwms'
    tmp[4] = -30.0;
  } else {
    // SignalConversion generated from: '<S1>/Maps forces to pwms'
    tmp[4] = u0;
  }

  // End of Saturate: '<S150>/Saturation'

  // Saturate: '<S200>/Saturation'
  if (rtb_yaw_idx_0 > 22.910259710444141) {
    // SignalConversion generated from: '<S1>/Maps forces to pwms'
    tmp[5] = 22.910259710444141;
  } else if (rtb_yaw_idx_0 < -22.910259710444141) {
    // SignalConversion generated from: '<S1>/Maps forces to pwms'
    tmp[5] = -22.910259710444141;
  } else {
    // SignalConversion generated from: '<S1>/Maps forces to pwms'
    tmp[5] = rtb_yaw_idx_0;
  }

  // End of Saturate: '<S200>/Saturation'

  // Update for DiscreteIntegrator: '<S38>/Filter'
  rtDW.Filter_DSTATE[0] += 0.1 * rtb_NProdOut_idx_0;

  // Update for DiscreteIntegrator: '<S43>/Integrator' incorporates:
  //   Inport: '<Root>/Input'
  //   Product: '<S40>/IProd Out'

  rtDW.Integrator_DSTATE[0] += rtU.Input[0] * rtb_xyz_idx_1;

  // Update for DiscreteIntegrator: '<S38>/Filter'
  rtDW.Filter_DSTATE[1] += 0.1 * rtb_NProdOut_idx_1;

  // Update for DiscreteIntegrator: '<S43>/Integrator' incorporates:
  //   Inport: '<Root>/Input'
  //   Product: '<S40>/IProd Out'

  rtDW.Integrator_DSTATE[1] += rtU.Input[1] * rtb_xyz_idx_1;

  // Update for DiscreteIntegrator: '<S38>/Filter' incorporates:
  //   Product: '<S46>/NProd Out'

  rtDW.Filter_DSTATE[2] += 0.1 * rtb_NProdOut_0;

  // Update for DiscreteIntegrator: '<S43>/Integrator' incorporates:
  //   Inport: '<Root>/Input'
  //   Product: '<S40>/IProd Out'

  rtDW.Integrator_DSTATE[2] += rtU.Input[2] * rtb_xyz_idx_1;

  // Update for DiscreteIntegrator: '<S88>/Filter'
  rtDW.Filter_DSTATE_j += 0.1 * yaw_flag;

  // Update for DiscreteIntegrator: '<S93>/Integrator' incorporates:
  //   Inport: '<Root>/Input'
  //   Product: '<S90>/IProd Out'

  rtDW.Integrator_DSTATE_k += 2.325 * rtU.Input[3];

  // Update for DiscreteIntegrator: '<S138>/Filter'
  rtDW.Filter_DSTATE_k += 0.1 * pitch_flag;

  // Update for DiscreteIntegrator: '<S143>/Integrator' incorporates:
  //   Inport: '<Root>/Input'
  //   Product: '<S140>/IProd Out'

  rtDW.Integrator_DSTATE_o += 3.236 * rtU.Input[4];

  // Update for DiscreteIntegrator: '<S188>/Filter'
  rtDW.Filter_DSTATE_b += 0.1 * rtb_yaw_idx_2;

  // Update for DiscreteIntegrator: '<S193>/Integrator' incorporates:
  //   Product: '<S190>/IProd Out'

  rtDW.Integrator_DSTATE_a += roll_flag * rtb_yaw_idx_1;
  for (i = 0; i < 8; i++) {
    // Product: '<S1>/Maps forces to pwms' incorporates:
    //   Constant: '<S1>/Constant'

    yaw_flag = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      yaw_flag += rtConstP.Constant_Value[(i_0 << 3) + i] * tmp[i_0];
    }

    // MATLAB Function: '<S1>/Thruster Forces to PWM' incorporates:
    //   Product: '<S1>/Maps forces to pwms'

    if (yaw_flag > 0.0) {
      yaw_flag = std::round(((yaw_flag * yaw_flag * -0.229204832763592 +
        0.00231011300235566 * rt_powd_snf(yaw_flag, 3.0)) + 13.7272237851422 *
        yaw_flag) + 1536.34500151024);
    } else if (yaw_flag < 0.0) {
      yaw_flag = std::round(((yaw_flag * yaw_flag * 0.360062809963915 +
        0.00475737746846442 * rt_powd_snf(yaw_flag, 3.0)) + 17.2034080439155 *
        yaw_flag) + 1463.91061014397);
    } else {
      yaw_flag = 1500.0;
    }

    if (yaw_flag > 1900.0) {
      yaw_flag = 1900.0;
    }

    if (yaw_flag < 1100.0) {
      yaw_flag = 1100.0;
    }

    // Outport: '<Root>/Out1' incorporates:
    //   MATLAB Function: '<S1>/Thruster Forces to PWM'

    rtY.Out1[i] = yaw_flag;
  }

  // End of Outputs for SubSystem: '<Root>/Controller'
}

// Model initialize function
void controller_codegenTest::initialize()
{
  // SystemInitialize for Atomic SubSystem: '<Root>/Controller'
  // Start for DataStoreMemory: '<S2>/Data Store Memory'
  rtDW.flags[0] = 1.0;
  rtDW.flags[1] = 1.0;
  rtDW.flags[2] = 0.0;

  // End of SystemInitialize for SubSystem: '<Root>/Controller'
}

// Constructor
controller_codegenTest::controller_codegenTest() :
  rtU(),
  rtY(),
  rtDW(),
  rtM()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
controller_codegenTest::~controller_codegenTest() = default;

// Real-Time Model get method
controller_codegenTest::RT_MODEL * controller_codegenTest::getRTM()
{
  return (&rtM);
}

//
// File trailer for generated code.
//
// [EOF]
//
