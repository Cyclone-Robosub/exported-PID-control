//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: PID_Controller.cpp
//
// Code generated for Simulink model 'PID_Controller'.
//
// Model version                  : 1.2
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Fri May 30 20:48:22 2025
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
  __m128d tmp_0;
  real_T tmp[6];
  real_T rtb_FilterCoefficient_4;
  real_T rtb_FilterCoefficient_c;
  real_T rtb_FilterCoefficient_idx_0;
  real_T rtb_FilterCoefficient_idx_1;
  real_T rtb_FilterCoefficient_o;
  real_T rtb_FilterCoefficient_oz;
  real_T u0;
  real_T u0_0;
  real_T u0_1;
  real_T u0_2;
  real_T u0_3;
  real_T y;
  int32_T i;
  int32_T i_0;

  // Outputs for Atomic SubSystem: '<Root>/Controller'
  // Gain: '<S46>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S38>/Filter'
  //   Gain: '<S36>/Derivative Gain'
  //   Sum: '<S38>/SumD'

  rtb_FilterCoefficient_c = (0.0 - PID_Controller_DW.Filter_DSTATE_d) * 54.54;

  // Gain: '<S96>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S88>/Filter'
  //   Gain: '<S86>/Derivative Gain'
  //   Sum: '<S88>/SumD'

  rtb_FilterCoefficient_oz = (0.0 - PID_Controller_DW.Filter_DSTATE_c) * 54.54;

  // Gain: '<S146>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S138>/Filter'
  //   Gain: '<S136>/Derivative Gain'
  //   Sum: '<S138>/SumD'

  rtb_FilterCoefficient_o = (0.0 - PID_Controller_DW.Filter_DSTATE_h) * 1142.828;

  // Gain: '<S196>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S188>/Filter'
  //   Gain: '<S186>/Derivative Gain'
  //   Sum: '<S188>/SumD'

  rtb_FilterCoefficient_4 = (0.0 - PID_Controller_DW.Filter_DSTATE[0]) *
    17.2469682941307;
  rtb_FilterCoefficient_idx_0 = rtb_FilterCoefficient_4;

  // Saturate: '<S200>/Saturation' incorporates:
  //   DiscreteIntegrator: '<S193>/Integrator'
  //   Gain: '<S196>/Filter Coefficient'
  //   Sum: '<S202>/Sum'

  y = PID_Controller_DW.Integrator_DSTATE[0] + rtb_FilterCoefficient_4;
  if (y > 120.0) {
    y = 120.0;
  } else if (y < -120.0) {
    y = -120.0;
  }

  // Gain: '<S196>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S188>/Filter'
  //   Gain: '<S186>/Derivative Gain'
  //   Sum: '<S188>/SumD'

  rtb_FilterCoefficient_4 = (0.0 - PID_Controller_DW.Filter_DSTATE[1]) *
    17.2469682941307;
  rtb_FilterCoefficient_idx_1 = rtb_FilterCoefficient_4;

  // Saturate: '<S200>/Saturation' incorporates:
  //   DiscreteIntegrator: '<S193>/Integrator'
  //   Gain: '<S196>/Filter Coefficient'
  //   Sum: '<S202>/Sum'

  u0 = PID_Controller_DW.Integrator_DSTATE[1] + rtb_FilterCoefficient_4;
  if (u0 > 120.0) {
    u0 = 120.0;
  } else if (u0 < -120.0) {
    u0 = -120.0;
  }

  // Gain: '<S196>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S188>/Filter'
  //   Gain: '<S186>/Derivative Gain'
  //   Sum: '<S188>/SumD'

  rtb_FilterCoefficient_4 = (0.0 - PID_Controller_DW.Filter_DSTATE[2]) *
    17.2469682941307;

  // Saturate: '<S200>/Saturation' incorporates:
  //   DiscreteIntegrator: '<S193>/Integrator'
  //   Gain: '<S196>/Filter Coefficient'
  //   Sum: '<S202>/Sum'

  u0_0 = PID_Controller_DW.Integrator_DSTATE[2] + rtb_FilterCoefficient_4;
  if (u0_0 > 120.0) {
    u0_0 = 120.0;
  } else if (u0_0 < -120.0) {
    u0_0 = -120.0;
  }

  // Sum: '<S52>/Sum' incorporates:
  //   DiscreteIntegrator: '<S43>/Integrator'

  u0_1 = PID_Controller_DW.Integrator_DSTATE_j + rtb_FilterCoefficient_c;

  // Sum: '<S102>/Sum' incorporates:
  //   DiscreteIntegrator: '<S93>/Integrator'

  u0_2 = PID_Controller_DW.Integrator_DSTATE_h + rtb_FilterCoefficient_oz;

  // Sum: '<S152>/Sum' incorporates:
  //   DiscreteIntegrator: '<S143>/Integrator'

  u0_3 = PID_Controller_DW.Integrator_DSTATE_hi + rtb_FilterCoefficient_o;
  for (i = 0; i <= 0; i += 2) {
    // Product: '<S1>/Maps forces to pwms' incorporates:
    //   Inport: '<Root>/Input1'
    //   Product: '<S2>/Matrix Multiply'

    _mm_storeu_pd(&tmp[i], _mm_add_pd(_mm_add_pd(_mm_mul_pd(_mm_loadu_pd
      (&PID_Controller_U.Input1[i + 3]), _mm_set1_pd(u0)), _mm_mul_pd
      (_mm_loadu_pd(&PID_Controller_U.Input1[i]), _mm_set1_pd(y))), _mm_mul_pd
      (_mm_loadu_pd(&PID_Controller_U.Input1[i + 6]), _mm_set1_pd(u0_0))));
  }

  for (i = 2; i < 3; i++) {
    // Product: '<S1>/Maps forces to pwms' incorporates:
    //   Inport: '<Root>/Input1'
    //   Product: '<S2>/Matrix Multiply'

    tmp[i] = (PID_Controller_U.Input1[i + 3] * u0 + PID_Controller_U.Input1[i] *
              y) + PID_Controller_U.Input1[i + 6] * u0_0;
  }

  // Saturate: '<S50>/Saturation'
  if (u0_1 > 24.360000000000003) {
    // Product: '<S1>/Maps forces to pwms'
    tmp[3] = 24.360000000000003;
  } else if (u0_1 < -24.360000000000003) {
    // Product: '<S1>/Maps forces to pwms'
    tmp[3] = -24.360000000000003;
  } else {
    // Product: '<S1>/Maps forces to pwms'
    tmp[3] = u0_1;
  }

  // End of Saturate: '<S50>/Saturation'

  // Saturate: '<S100>/Saturation'
  if (u0_2 > 30.48) {
    // Product: '<S1>/Maps forces to pwms'
    tmp[4] = 30.48;
  } else if (u0_2 < -30.48) {
    // Product: '<S1>/Maps forces to pwms'
    tmp[4] = -30.48;
  } else {
    // Product: '<S1>/Maps forces to pwms'
    tmp[4] = u0_2;
  }

  // End of Saturate: '<S100>/Saturation'

  // Saturate: '<S150>/Saturation'
  if (u0_3 > 25.880108191427642) {
    // Product: '<S1>/Maps forces to pwms'
    tmp[5] = 25.880108191427642;
  } else if (u0_3 < -25.880108191427642) {
    // Product: '<S1>/Maps forces to pwms'
    tmp[5] = -25.880108191427642;
  } else {
    // Product: '<S1>/Maps forces to pwms'
    tmp[5] = u0_3;
  }

  // End of Saturate: '<S150>/Saturation'
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

  // Update for DiscreteIntegrator: '<S188>/Filter' incorporates:
  //   Gain: '<S196>/Filter Coefficient'
  //
  tmp_0 = _mm_add_pd(_mm_mul_pd(_mm_set1_pd(0.01), _mm_set_pd
    (rtb_FilterCoefficient_idx_1, rtb_FilterCoefficient_idx_0)), _mm_loadu_pd
                     (&PID_Controller_DW.Filter_DSTATE[0]));
  _mm_storeu_pd(&PID_Controller_DW.Filter_DSTATE[0], tmp_0);
  PID_Controller_DW.Filter_DSTATE[2] += 0.01 * rtb_FilterCoefficient_4;

  // Update for DiscreteIntegrator: '<S38>/Filter'
  PID_Controller_DW.Filter_DSTATE_d += 0.01 * rtb_FilterCoefficient_c;

  // Update for DiscreteIntegrator: '<S88>/Filter'
  PID_Controller_DW.Filter_DSTATE_c += 0.01 * rtb_FilterCoefficient_oz;

  // Update for DiscreteIntegrator: '<S138>/Filter'
  PID_Controller_DW.Filter_DSTATE_h += 0.01 * rtb_FilterCoefficient_o;

  // End of Outputs for SubSystem: '<Root>/Controller'
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
