//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: PID_Controller.cpp
//
// Code generated for Simulink model 'PID_Controller'.
//
// Model version                  : 4.0
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Thu Aug  7 00:14:38 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "PID_Controller.h"
#include <emmintrin.h>
#include "PID_Controller_private.h"
#include <cmath>
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
  real_T tmp[6];
  real_T rtb_DeadZone;
  real_T rtb_DeadZone_n;
  real_T rtb_FilterCoefficient_3;
  real_T rtb_FilterCoefficient_b;
  real_T rtb_FilterCoefficient_idx_0;
  real_T rtb_FilterCoefficient_idx_1;
  real_T rtb_FilterCoefficient_k;
  real_T rtb_FilterCoefficient_n;
  real_T rtb_corrected_error;
  real_T u0;
  real_T u0_0;
  real_T u0_1;
  real_T y;
  int32_T i;
  int32_T i_0;
  int8_T tmp_0;
  int8_T tmp_1;

  // Outputs for Atomic SubSystem: '<Root>/Controller1'
  // Gain: '<S49>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S41>/Filter'
  //   Gain: '<S39>/Derivative Gain'
  //   Inport: '<Root>/state_error_e'
  //   Sum: '<S41>/SumD'

  rtb_FilterCoefficient_n = (2.504 * PID_Controller_U.state_error_e[3] -
    PID_Controller_DW.Filter_DSTATE_c) * 54.54;

  // Sum: '<S55>/Sum' incorporates:
  //   DiscreteIntegrator: '<S46>/Integrator'
  //   Gain: '<S51>/Proportional Gain'
  //   Inport: '<Root>/state_error_e'

  rtb_DeadZone = (4.773 * PID_Controller_U.state_error_e[3] +
                  PID_Controller_DW.Integrator_DSTATE_n) +
    rtb_FilterCoefficient_n;

  // Gain: '<S103>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S95>/Filter'
  //   Gain: '<S93>/Derivative Gain'
  //   Inport: '<Root>/state_error_e'
  //   Sum: '<S95>/SumD'

  rtb_FilterCoefficient_b = (3.625 * PID_Controller_U.state_error_e[4] -
    PID_Controller_DW.Filter_DSTATE_l) * 54.54;

  // Sum: '<S109>/Sum' incorporates:
  //   DiscreteIntegrator: '<S100>/Integrator'
  //   Gain: '<S105>/Proportional Gain'
  //   Inport: '<Root>/state_error_e'

  rtb_DeadZone_n = (6.912 * PID_Controller_U.state_error_e[4] +
                    PID_Controller_DW.Integrator_DSTATE_p) +
    rtb_FilterCoefficient_b;

  // MATLAB Function: '<S2>/Yaw Overshoot Corrector' incorporates:
  //   Inport: '<Root>/state_error_e'

  if (PID_Controller_U.state_error_e[5] > 1.5707963267948966) {
    rtb_corrected_error = PID_Controller_U.state_error_e[5] - 6.2831853071795862;
  } else if (PID_Controller_U.state_error_e[5] < -1.5707963267948966) {
    rtb_corrected_error = PID_Controller_U.state_error_e[5] + 6.2831853071795862;
  } else {
    rtb_corrected_error = PID_Controller_U.state_error_e[5];
  }

  // End of MATLAB Function: '<S2>/Yaw Overshoot Corrector'

  // Gain: '<S155>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S147>/Filter'
  //   Gain: '<S145>/Derivative Gain'
  //   Sum: '<S147>/SumD'

  rtb_FilterCoefficient_k = (2.957 * rtb_corrected_error -
    PID_Controller_DW.Filter_DSTATE_f) * 114.828;

  // Gain: '<S207>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S199>/Filter'
  //   Gain: '<S197>/Derivative Gain'
  //   Inport: '<Root>/state_error_e'
  //   Sum: '<S199>/SumD'

  rtb_FilterCoefficient_3 = (30.7980856287723 * PID_Controller_U.state_error_e[0]
    - PID_Controller_DW.Filter_DSTATE[0]) * 17.2469682941307;
  rtb_FilterCoefficient_idx_0 = rtb_FilterCoefficient_3;

  // Saturate: '<S211>/Saturation' incorporates:
  //   DiscreteIntegrator: '<S204>/Integrator'
  //   Gain: '<S197>/Derivative Gain'
  //   Gain: '<S207>/Filter Coefficient'
  //   Gain: '<S209>/Proportional Gain'
  //   Inport: '<Root>/state_error_e'
  //   Sum: '<S213>/Sum'

  y = (18.567926327114 * PID_Controller_U.state_error_e[0] +
       PID_Controller_DW.Integrator_DSTATE[0]) + rtb_FilterCoefficient_3;
  if (y > 120.0) {
    y = 120.0;
  } else if (y < -120.0) {
    y = -120.0;
  }

  // Gain: '<S207>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S199>/Filter'
  //   Gain: '<S197>/Derivative Gain'
  //   Inport: '<Root>/state_error_e'
  //   Sum: '<S199>/SumD'

  rtb_FilterCoefficient_3 = (30.7980856287723 * PID_Controller_U.state_error_e[1]
    - PID_Controller_DW.Filter_DSTATE[1]) * 17.2469682941307;
  rtb_FilterCoefficient_idx_1 = rtb_FilterCoefficient_3;

  // Saturate: '<S211>/Saturation' incorporates:
  //   DiscreteIntegrator: '<S204>/Integrator'
  //   Gain: '<S197>/Derivative Gain'
  //   Gain: '<S207>/Filter Coefficient'
  //   Gain: '<S209>/Proportional Gain'
  //   Inport: '<Root>/state_error_e'
  //   Sum: '<S213>/Sum'

  u0 = (18.567926327114 * PID_Controller_U.state_error_e[1] +
        PID_Controller_DW.Integrator_DSTATE[1]) + rtb_FilterCoefficient_3;
  if (u0 > 120.0) {
    u0 = 120.0;
  } else if (u0 < -120.0) {
    u0 = -120.0;
  }

  // Gain: '<S207>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S199>/Filter'
  //   Gain: '<S197>/Derivative Gain'
  //   Inport: '<Root>/state_error_e'
  //   Sum: '<S199>/SumD'

  rtb_FilterCoefficient_3 = (30.7980856287723 * PID_Controller_U.state_error_e[2]
    - PID_Controller_DW.Filter_DSTATE[2]) * 17.2469682941307;

  // Saturate: '<S211>/Saturation' incorporates:
  //   DiscreteIntegrator: '<S204>/Integrator'
  //   Gain: '<S197>/Derivative Gain'
  //   Gain: '<S207>/Filter Coefficient'
  //   Gain: '<S209>/Proportional Gain'
  //   Inport: '<Root>/state_error_e'
  //   Sum: '<S213>/Sum'

  u0_0 = (18.567926327114 * PID_Controller_U.state_error_e[2] +
          PID_Controller_DW.Integrator_DSTATE[2]) + rtb_FilterCoefficient_3;
  if (u0_0 > 120.0) {
    u0_0 = 120.0;
  } else if (u0_0 < -120.0) {
    u0_0 = -120.0;
  }

  // Sum: '<S161>/Sum' incorporates:
  //   DiscreteIntegrator: '<S152>/Integrator'
  //   Gain: '<S157>/Proportional Gain'

  u0_1 = (6.782 * rtb_corrected_error + PID_Controller_DW.Integrator_DSTATE_pu)
    + rtb_FilterCoefficient_k;
  for (i = 0; i <= 0; i += 2) {
    // Product: '<S1>/Maps forces to pwms' incorporates:
    //   Inport: '<Root>/DCMbe'
    //   Product: '<S2>/Matrix Multiply'

    _mm_storeu_pd(&tmp[i], _mm_add_pd(_mm_add_pd(_mm_mul_pd(_mm_loadu_pd
      (&PID_Controller_U.DCMbe[i + 3]), _mm_set1_pd(u0)), _mm_mul_pd
      (_mm_loadu_pd(&PID_Controller_U.DCMbe[i]), _mm_set1_pd(y))), _mm_mul_pd
      (_mm_loadu_pd(&PID_Controller_U.DCMbe[i + 6]), _mm_set1_pd(u0_0))));
  }

  for (i = 2; i < 3; i++) {
    // Product: '<S1>/Maps forces to pwms' incorporates:
    //   Inport: '<Root>/DCMbe'
    //   Product: '<S2>/Matrix Multiply'

    tmp[i] = (PID_Controller_U.DCMbe[i + 3] * u0 + PID_Controller_U.DCMbe[i] * y)
      + PID_Controller_U.DCMbe[i + 6] * u0_0;
  }

  // Saturate: '<S53>/Saturation'
  if (rtb_DeadZone > 24.360000000000003) {
    // Product: '<S1>/Maps forces to pwms'
    tmp[3] = 24.360000000000003;
  } else if (rtb_DeadZone < -24.360000000000003) {
    // Product: '<S1>/Maps forces to pwms'
    tmp[3] = -24.360000000000003;
  } else {
    // Product: '<S1>/Maps forces to pwms'
    tmp[3] = rtb_DeadZone;
  }

  // End of Saturate: '<S53>/Saturation'

  // Saturate: '<S107>/Saturation'
  if (rtb_DeadZone_n > 30.48) {
    // Product: '<S1>/Maps forces to pwms'
    tmp[4] = 30.48;
  } else if (rtb_DeadZone_n < -30.48) {
    // Product: '<S1>/Maps forces to pwms'
    tmp[4] = -30.48;
  } else {
    // Product: '<S1>/Maps forces to pwms'
    tmp[4] = rtb_DeadZone_n;
  }

  // End of Saturate: '<S107>/Saturation'

  // Saturate: '<S159>/Saturation'
  if (u0_1 > 25.880108191427642) {
    // Product: '<S1>/Maps forces to pwms'
    tmp[5] = 25.880108191427642;
  } else if (u0_1 < -25.880108191427642) {
    // Product: '<S1>/Maps forces to pwms'
    tmp[5] = -25.880108191427642;
  } else {
    // Product: '<S1>/Maps forces to pwms'
    tmp[5] = u0_1;
  }

  // End of Saturate: '<S159>/Saturation'
  for (i_0 = 0; i_0 < 8; i_0++) {
    // Product: '<S1>/Maps forces to pwms' incorporates:
    //   Constant: '<S1>/Constant'

    y = 0.0;
    for (i = 0; i < 6; i++) {
      y += PID_Controller_ConstP.Constant_Value[(i << 3) + i_0] * tmp[i];
    }

    // MATLAB Function: '<S1>/Thruster Forces to PWM' incorporates:
    //   Product: '<S1>/Maps forces to pwms'

    if (y > 0.0) {
      y = std::round(((y * y * -0.229204832763592 + 0.00231011300235566 *
                       rt_powd_snf(y, 3.0)) + 13.7272237851422 * y) +
                     1536.34500151024);
    } else if (y < 0.0) {
      y = std::round(((y * y * 0.360062809963915 + 0.00475737746846442 *
                       rt_powd_snf(y, 3.0)) + 17.2034080439155 * y) +
                     1463.91061014397);
    } else {
      y = 1500.0;
    }

    if (y > 1900.0) {
      y = 1900.0;
    }

    if (y < 1100.0) {
      y = 1100.0;
    }

    PID_Controller_Y.PWM[i_0] = y;

    // End of MATLAB Function: '<S1>/Thruster Forces to PWM'
  }

  // DeadZone: '<S92>/DeadZone'
  if (rtb_DeadZone_n > 30.48) {
    rtb_DeadZone_n -= 30.48;
  } else if (rtb_DeadZone_n >= -30.48) {
    rtb_DeadZone_n = 0.0;
  } else {
    rtb_DeadZone_n -= -30.48;
  }

  // End of DeadZone: '<S92>/DeadZone'

  // Gain: '<S97>/Integral Gain' incorporates:
  //   Inport: '<Root>/state_error_e'

  y = 3.236 * PID_Controller_U.state_error_e[4];

  // Switch: '<S90>/Switch1' incorporates:
  //   Constant: '<S90>/Clamping_zero'
  //   Constant: '<S90>/Constant'
  //   Constant: '<S90>/Constant2'
  //   RelationalOperator: '<S90>/fix for DT propagation issue'

  if (rtb_DeadZone_n > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  // Switch: '<S90>/Switch2' incorporates:
  //   Constant: '<S90>/Clamping_zero'
  //   Constant: '<S90>/Constant3'
  //   Constant: '<S90>/Constant4'
  //   RelationalOperator: '<S90>/fix for DT propagation issue1'

  if (y > 0.0) {
    tmp_1 = 1;
  } else {
    tmp_1 = -1;
  }

  // Switch: '<S90>/Switch' incorporates:
  //   Constant: '<S90>/Clamping_zero'
  //   Constant: '<S90>/Constant1'
  //   Logic: '<S90>/AND3'
  //   RelationalOperator: '<S90>/Equal1'
  //   RelationalOperator: '<S90>/Relational Operator'
  //   Switch: '<S90>/Switch1'
  //   Switch: '<S90>/Switch2'

  if ((rtb_DeadZone_n != 0.0) && (tmp_0 == tmp_1)) {
    rtb_DeadZone_n = 0.0;
  } else {
    rtb_DeadZone_n = y;
  }

  // End of Switch: '<S90>/Switch'

  // DeadZone: '<S38>/DeadZone'
  if (rtb_DeadZone > 24.360000000000003) {
    rtb_DeadZone -= 24.360000000000003;
  } else if (rtb_DeadZone >= -24.360000000000003) {
    rtb_DeadZone = 0.0;
  } else {
    rtb_DeadZone -= -24.360000000000003;
  }

  // End of DeadZone: '<S38>/DeadZone'

  // Gain: '<S43>/Integral Gain' incorporates:
  //   Inport: '<Root>/state_error_e'

  y = 2.325 * PID_Controller_U.state_error_e[3];

  // Update for DiscreteIntegrator: '<S204>/Integrator' incorporates:
  //   Gain: '<S201>/Integral Gain'
  //   Inport: '<Root>/state_error_e'

  PID_Controller_DW.Integrator_DSTATE[0] += 2.74882046275699 *
    PID_Controller_U.state_error_e[0] * 0.01;

  // Update for DiscreteIntegrator: '<S199>/Filter' incorporates:
  //   Gain: '<S207>/Filter Coefficient'

  PID_Controller_DW.Filter_DSTATE[0] += 0.01 * rtb_FilterCoefficient_idx_0;

  // Update for DiscreteIntegrator: '<S204>/Integrator' incorporates:
  //   Gain: '<S201>/Integral Gain'
  //   Inport: '<Root>/state_error_e'

  PID_Controller_DW.Integrator_DSTATE[1] += 2.74882046275699 *
    PID_Controller_U.state_error_e[1] * 0.01;

  // Update for DiscreteIntegrator: '<S199>/Filter' incorporates:
  //   Gain: '<S207>/Filter Coefficient'

  PID_Controller_DW.Filter_DSTATE[1] += 0.01 * rtb_FilterCoefficient_idx_1;

  // Update for DiscreteIntegrator: '<S204>/Integrator' incorporates:
  //   Gain: '<S201>/Integral Gain'
  //   Inport: '<Root>/state_error_e'

  PID_Controller_DW.Integrator_DSTATE[2] += 2.74882046275699 *
    PID_Controller_U.state_error_e[2] * 0.01;

  // Update for DiscreteIntegrator: '<S199>/Filter' incorporates:
  //   Gain: '<S207>/Filter Coefficient'

  PID_Controller_DW.Filter_DSTATE[2] += 0.01 * rtb_FilterCoefficient_3;

  // Switch: '<S36>/Switch1' incorporates:
  //   Constant: '<S36>/Clamping_zero'
  //   Constant: '<S36>/Constant'
  //   Constant: '<S36>/Constant2'
  //   RelationalOperator: '<S36>/fix for DT propagation issue'

  if (rtb_DeadZone > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  // Switch: '<S36>/Switch2' incorporates:
  //   Constant: '<S36>/Clamping_zero'
  //   Constant: '<S36>/Constant3'
  //   Constant: '<S36>/Constant4'
  //   RelationalOperator: '<S36>/fix for DT propagation issue1'

  if (y > 0.0) {
    tmp_1 = 1;
  } else {
    tmp_1 = -1;
  }

  // Switch: '<S36>/Switch' incorporates:
  //   Constant: '<S36>/Clamping_zero'
  //   Constant: '<S36>/Constant1'
  //   Logic: '<S36>/AND3'
  //   RelationalOperator: '<S36>/Equal1'
  //   RelationalOperator: '<S36>/Relational Operator'
  //   Switch: '<S36>/Switch1'
  //   Switch: '<S36>/Switch2'

  if ((rtb_DeadZone != 0.0) && (tmp_0 == tmp_1)) {
    y = 0.0;
  }

  // Update for DiscreteIntegrator: '<S46>/Integrator' incorporates:
  //   Switch: '<S36>/Switch'

  PID_Controller_DW.Integrator_DSTATE_n += 0.01 * y;

  // Update for DiscreteIntegrator: '<S41>/Filter'
  PID_Controller_DW.Filter_DSTATE_c += 0.01 * rtb_FilterCoefficient_n;

  // Update for DiscreteIntegrator: '<S100>/Integrator'
  PID_Controller_DW.Integrator_DSTATE_p += 0.01 * rtb_DeadZone_n;

  // Update for DiscreteIntegrator: '<S95>/Filter'
  PID_Controller_DW.Filter_DSTATE_l += 0.01 * rtb_FilterCoefficient_b;

  // Update for DiscreteIntegrator: '<S152>/Integrator' incorporates:
  //   Gain: '<S149>/Integral Gain'

  PID_Controller_DW.Integrator_DSTATE_pu += 2.479 * rtb_corrected_error * 0.01;

  // Update for DiscreteIntegrator: '<S147>/Filter'
  PID_Controller_DW.Filter_DSTATE_f += 0.01 * rtb_FilterCoefficient_k;

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
