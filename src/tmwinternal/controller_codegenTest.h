//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controller_codegenTest.h
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
#ifndef controller_codegenTest_h_
#define controller_codegenTest_h_
#include <cmath>
#include "rtwtypes.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

extern "C"
{
  static real_T rtGetInf(void);
  static real32_T rtGetInfF(void);
  static real_T rtGetMinusInf(void);
  static real32_T rtGetMinusInfF(void);
}                                      // extern "C"

extern "C"
{
  static real_T rtGetNaN(void);
  static real32_T rtGetNaNF(void);
}                                      // extern "C"

extern "C"
{
  extern real_T rtInf;
  extern real_T rtMinusInf;
  extern real_T rtNaN;
  extern real32_T rtInfF;
  extern real32_T rtMinusInfF;
  extern real32_T rtNaNF;
  static boolean_T rtIsInf(real_T value);
  static boolean_T rtIsInfF(real32_T value);
  static boolean_T rtIsNaN(real_T value);
  static boolean_T rtIsNaNF(real32_T value);
}                                      // extern "C"

// Class declaration for model controller_codegenTest
class controller_codegenTest final
{
  // public data and function members
 public:
  // Block signals and states (default storage) for system '<Root>'
  struct DW {
    real_T Filter_DSTATE[3];           // '<S38>/Filter'
    real_T Integrator_DSTATE[3];       // '<S43>/Integrator'
    real_T flags[3];                   // '<S2>/Data Store Memory'
    real_T Filter_DSTATE_j;            // '<S88>/Filter'
    real_T Integrator_DSTATE_k;        // '<S93>/Integrator'
    real_T Filter_DSTATE_k;            // '<S138>/Filter'
    real_T Integrator_DSTATE_o;        // '<S143>/Integrator'
    real_T Filter_DSTATE_b;            // '<S188>/Filter'
    real_T Integrator_DSTATE_a;        // '<S193>/Integrator'
  };

  // Constant parameters (default storage)
  struct ConstP {
    // Expression: inverse_wrench
    //  Referenced by: '<S1>/Constant'

    real_T Constant_Value[48];
  };

  // External inputs (root inport signals with default storage)
  struct ExtU {
    real_T Input[6];                   // '<Root>/Input'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY {
    real_T Out1[8];                    // '<Root>/Out1'
  };

  // Real-time Model Data Structure
  struct RT_MODEL {
    const char_T * volatile errorStatus;
  };

  // Copy Constructor
  controller_codegenTest(controller_codegenTest const&) = delete;

  // Assignment Operator
  controller_codegenTest& operator= (controller_codegenTest const&) & = delete;

  // Move Constructor
  controller_codegenTest(controller_codegenTest &&) = delete;

  // Move Assignment Operator
  controller_codegenTest& operator= (controller_codegenTest &&) = delete;

  // Real-Time Model get method
  controller_codegenTest::RT_MODEL * getRTM();

  // External inputs
  ExtU rtU;

  // External outputs
  ExtY rtY;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // Constructor
  controller_codegenTest();

  // Destructor
  ~controller_codegenTest();

  // private data and function members
 private:
  // Block states
  DW rtDW;

  // Real-Time Model
  RT_MODEL rtM;
};

// Constant parameters (default storage)
extern const controller_codegenTest::ConstP rtConstP;

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'controller_codegenTest'
//  '<S1>'   : 'controller_codegenTest/Controller'
//  '<S2>'   : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID'
//  '<S3>'   : 'controller_codegenTest/Controller/Thruster Forces to PWM'
//  '<S4>'   : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/Gain Scheduler'
//  '<S5>'   : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller'
//  '<S6>'   : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2'
//  '<S7>'   : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3'
//  '<S8>'   : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4'
//  '<S9>'   : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/Yaw Cross-Talk Corrector'
//  '<S10>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/Anti-windup'
//  '<S11>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/D Gain'
//  '<S12>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/External Derivative'
//  '<S13>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/Filter'
//  '<S14>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/Filter ICs'
//  '<S15>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/I Gain'
//  '<S16>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/Ideal P Gain'
//  '<S17>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/Ideal P Gain Fdbk'
//  '<S18>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/Integrator'
//  '<S19>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/Integrator ICs'
//  '<S20>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/N Copy'
//  '<S21>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/N Gain'
//  '<S22>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/P Copy'
//  '<S23>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/Parallel P Gain'
//  '<S24>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/Reset Signal'
//  '<S25>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/Saturation'
//  '<S26>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/Saturation Fdbk'
//  '<S27>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/Sum'
//  '<S28>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/Sum Fdbk'
//  '<S29>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/Tracking Mode'
//  '<S30>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/Tracking Mode Sum'
//  '<S31>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/Tsamp - Integral'
//  '<S32>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/Tsamp - Ngain'
//  '<S33>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/postSat Signal'
//  '<S34>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/preSat Signal'
//  '<S35>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/Anti-windup/Passthrough'
//  '<S36>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/D Gain/External Parameters'
//  '<S37>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/External Derivative/Error'
//  '<S38>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/Filter/Disc. Forward Euler Filter'
//  '<S39>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/Filter ICs/Internal IC - Filter'
//  '<S40>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/I Gain/External Parameters'
//  '<S41>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/Ideal P Gain/Passthrough'
//  '<S42>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S43>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/Integrator/Discrete'
//  '<S44>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/Integrator ICs/Internal IC'
//  '<S45>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/N Copy/Disabled'
//  '<S46>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/N Gain/External Parameters'
//  '<S47>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/P Copy/Disabled'
//  '<S48>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/Parallel P Gain/External Parameters'
//  '<S49>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/Reset Signal/Disabled'
//  '<S50>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/Saturation/Enabled'
//  '<S51>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/Saturation Fdbk/Disabled'
//  '<S52>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/Sum/Sum_PID'
//  '<S53>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/Sum Fdbk/Disabled'
//  '<S54>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/Tracking Mode/Disabled'
//  '<S55>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S56>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S57>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S58>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/postSat Signal/Forward_Path'
//  '<S59>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller/preSat Signal/Forward_Path'
//  '<S60>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/Anti-windup'
//  '<S61>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/D Gain'
//  '<S62>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/External Derivative'
//  '<S63>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/Filter'
//  '<S64>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/Filter ICs'
//  '<S65>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/I Gain'
//  '<S66>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/Ideal P Gain'
//  '<S67>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/Ideal P Gain Fdbk'
//  '<S68>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/Integrator'
//  '<S69>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/Integrator ICs'
//  '<S70>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/N Copy'
//  '<S71>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/N Gain'
//  '<S72>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/P Copy'
//  '<S73>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/Parallel P Gain'
//  '<S74>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/Reset Signal'
//  '<S75>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/Saturation'
//  '<S76>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/Saturation Fdbk'
//  '<S77>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/Sum'
//  '<S78>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/Sum Fdbk'
//  '<S79>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/Tracking Mode'
//  '<S80>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/Tracking Mode Sum'
//  '<S81>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/Tsamp - Integral'
//  '<S82>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/Tsamp - Ngain'
//  '<S83>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/postSat Signal'
//  '<S84>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/preSat Signal'
//  '<S85>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/Anti-windup/Passthrough'
//  '<S86>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/D Gain/External Parameters'
//  '<S87>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/External Derivative/Error'
//  '<S88>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/Filter/Disc. Forward Euler Filter'
//  '<S89>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/Filter ICs/Internal IC - Filter'
//  '<S90>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/I Gain/External Parameters'
//  '<S91>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/Ideal P Gain/Passthrough'
//  '<S92>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/Ideal P Gain Fdbk/Disabled'
//  '<S93>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/Integrator/Discrete'
//  '<S94>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/Integrator ICs/Internal IC'
//  '<S95>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/N Copy/Disabled'
//  '<S96>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/N Gain/External Parameters'
//  '<S97>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/P Copy/Disabled'
//  '<S98>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/Parallel P Gain/External Parameters'
//  '<S99>'  : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/Reset Signal/Disabled'
//  '<S100>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/Saturation/Enabled'
//  '<S101>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/Saturation Fdbk/Disabled'
//  '<S102>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/Sum/Sum_PID'
//  '<S103>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/Sum Fdbk/Disabled'
//  '<S104>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/Tracking Mode/Disabled'
//  '<S105>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/Tracking Mode Sum/Passthrough'
//  '<S106>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/Tsamp - Integral/TsSignalSpecification'
//  '<S107>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/Tsamp - Ngain/Passthrough'
//  '<S108>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/postSat Signal/Forward_Path'
//  '<S109>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller2/preSat Signal/Forward_Path'
//  '<S110>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/Anti-windup'
//  '<S111>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/D Gain'
//  '<S112>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/External Derivative'
//  '<S113>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/Filter'
//  '<S114>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/Filter ICs'
//  '<S115>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/I Gain'
//  '<S116>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/Ideal P Gain'
//  '<S117>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/Ideal P Gain Fdbk'
//  '<S118>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/Integrator'
//  '<S119>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/Integrator ICs'
//  '<S120>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/N Copy'
//  '<S121>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/N Gain'
//  '<S122>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/P Copy'
//  '<S123>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/Parallel P Gain'
//  '<S124>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/Reset Signal'
//  '<S125>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/Saturation'
//  '<S126>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/Saturation Fdbk'
//  '<S127>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/Sum'
//  '<S128>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/Sum Fdbk'
//  '<S129>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/Tracking Mode'
//  '<S130>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/Tracking Mode Sum'
//  '<S131>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/Tsamp - Integral'
//  '<S132>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/Tsamp - Ngain'
//  '<S133>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/postSat Signal'
//  '<S134>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/preSat Signal'
//  '<S135>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/Anti-windup/Passthrough'
//  '<S136>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/D Gain/External Parameters'
//  '<S137>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/External Derivative/Error'
//  '<S138>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/Filter/Disc. Forward Euler Filter'
//  '<S139>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/Filter ICs/Internal IC - Filter'
//  '<S140>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/I Gain/External Parameters'
//  '<S141>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/Ideal P Gain/Passthrough'
//  '<S142>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/Ideal P Gain Fdbk/Disabled'
//  '<S143>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/Integrator/Discrete'
//  '<S144>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/Integrator ICs/Internal IC'
//  '<S145>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/N Copy/Disabled'
//  '<S146>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/N Gain/External Parameters'
//  '<S147>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/P Copy/Disabled'
//  '<S148>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/Parallel P Gain/External Parameters'
//  '<S149>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/Reset Signal/Disabled'
//  '<S150>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/Saturation/Enabled'
//  '<S151>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/Saturation Fdbk/Disabled'
//  '<S152>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/Sum/Sum_PID'
//  '<S153>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/Sum Fdbk/Disabled'
//  '<S154>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/Tracking Mode/Disabled'
//  '<S155>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/Tracking Mode Sum/Passthrough'
//  '<S156>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/Tsamp - Integral/TsSignalSpecification'
//  '<S157>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/Tsamp - Ngain/Passthrough'
//  '<S158>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/postSat Signal/Forward_Path'
//  '<S159>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller3/preSat Signal/Forward_Path'
//  '<S160>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/Anti-windup'
//  '<S161>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/D Gain'
//  '<S162>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/External Derivative'
//  '<S163>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/Filter'
//  '<S164>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/Filter ICs'
//  '<S165>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/I Gain'
//  '<S166>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/Ideal P Gain'
//  '<S167>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/Ideal P Gain Fdbk'
//  '<S168>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/Integrator'
//  '<S169>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/Integrator ICs'
//  '<S170>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/N Copy'
//  '<S171>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/N Gain'
//  '<S172>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/P Copy'
//  '<S173>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/Parallel P Gain'
//  '<S174>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/Reset Signal'
//  '<S175>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/Saturation'
//  '<S176>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/Saturation Fdbk'
//  '<S177>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/Sum'
//  '<S178>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/Sum Fdbk'
//  '<S179>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/Tracking Mode'
//  '<S180>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/Tracking Mode Sum'
//  '<S181>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/Tsamp - Integral'
//  '<S182>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/Tsamp - Ngain'
//  '<S183>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/postSat Signal'
//  '<S184>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/preSat Signal'
//  '<S185>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/Anti-windup/Passthrough'
//  '<S186>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/D Gain/External Parameters'
//  '<S187>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/External Derivative/Error'
//  '<S188>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/Filter/Disc. Forward Euler Filter'
//  '<S189>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/Filter ICs/Internal IC - Filter'
//  '<S190>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/I Gain/External Parameters'
//  '<S191>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/Ideal P Gain/Passthrough'
//  '<S192>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/Ideal P Gain Fdbk/Disabled'
//  '<S193>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/Integrator/Discrete'
//  '<S194>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/Integrator ICs/Internal IC'
//  '<S195>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/N Copy/Disabled'
//  '<S196>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/N Gain/External Parameters'
//  '<S197>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/P Copy/Disabled'
//  '<S198>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/Parallel P Gain/External Parameters'
//  '<S199>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/Reset Signal/Disabled'
//  '<S200>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/Saturation/Enabled'
//  '<S201>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/Saturation Fdbk/Disabled'
//  '<S202>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/Sum/Sum_PID'
//  '<S203>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/Sum Fdbk/Disabled'
//  '<S204>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/Tracking Mode/Disabled'
//  '<S205>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/Tracking Mode Sum/Passthrough'
//  '<S206>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/Tsamp - Integral/TsSignalSpecification'
//  '<S207>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/Tsamp - Ngain/Passthrough'
//  '<S208>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/postSat Signal/Forward_Path'
//  '<S209>' : 'controller_codegenTest/Controller/6 DOF Gain Scheduled PID/PID Controller4/preSat Signal/Forward_Path'

#endif                                 // controller_codegenTest_h_

//
// File trailer for generated code.
//
// [EOF]
//
