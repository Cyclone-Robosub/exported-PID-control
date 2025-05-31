//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: PID_Controller.h
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
#ifndef PID_Controller_h_
#define PID_Controller_h_
#include <cmath>
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "PID_Controller_types.h"

extern "C"
{

#include "rtGetInf.h"

}

extern "C"
{

#include "rtGetNaN.h"

}

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Class declaration for model PID_Controller
class PID_Controller final
{
  // public data and function members
 public:
  // Block states (default storage) for system '<Root>'
  struct DW_PID_Controller_T {
    real_T Integrator_DSTATE[3];       // '<S193>/Integrator'
    real_T Filter_DSTATE[3];           // '<S188>/Filter'
    real_T Integrator_DSTATE_j;        // '<S43>/Integrator'
    real_T Filter_DSTATE_d;            // '<S38>/Filter'
    real_T Integrator_DSTATE_h;        // '<S93>/Integrator'
    real_T Filter_DSTATE_c;            // '<S88>/Filter'
    real_T Integrator_DSTATE_hi;       // '<S143>/Integrator'
    real_T Filter_DSTATE_h;            // '<S138>/Filter'
  };

  // Constant parameters (default storage)
  struct ConstP_PID_Controller_T {
    // Expression: inverse_wrench
    //  Referenced by: '<S1>/Constant'

    real_T Constant_Value[48];
  };

  // External inputs (root inport signals with default storage)
  struct ExtU_PID_Controller_T {
    real_T Input[6];                   // '<Root>/Input'
    real_T Input1[9];                  // '<Root>/Input1'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_PID_Controller_T {
    real_T PWM[8];                     // '<Root>/PWM'
  };

  // Real-time Model Data Structure
  struct RT_MODEL_PID_Controller_T {
    const char_T * volatile errorStatus;
  };

  // Copy Constructor
  PID_Controller(PID_Controller const&) = delete;

  // Assignment Operator
  PID_Controller& operator= (PID_Controller const&) & = delete;

  // Move Constructor
  PID_Controller(PID_Controller &&) = delete;

  // Move Assignment Operator
  PID_Controller& operator= (PID_Controller &&) = delete;

  // Real-Time Model get method
  PID_Controller::RT_MODEL_PID_Controller_T * getRTM();

  // Root inports set method
  void setExternalInputs(const ExtU_PID_Controller_T *pExtU_PID_Controller_T)
  {
    PID_Controller_U = *pExtU_PID_Controller_T;
  }

  // Root outports get method
  const ExtY_PID_Controller_T &getExternalOutputs() const
  {
    return PID_Controller_Y;
  }

  // model initialize function
  static void initialize();

  // model step function
  void step();

  // model terminate function
  static void terminate();

  // Constructor
  PID_Controller();

  // Destructor
  ~PID_Controller();

  // private data and function members
 private:
  // External inputs
  ExtU_PID_Controller_T PID_Controller_U;

  // External outputs
  ExtY_PID_Controller_T PID_Controller_Y;

  // Block states
  DW_PID_Controller_T PID_Controller_DW;

  // Real-Time Model
  RT_MODEL_PID_Controller_T PID_Controller_M;
};

// Constant parameters (default storage)
extern const PID_Controller::ConstP_PID_Controller_T PID_Controller_ConstP;

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
//  '<Root>' : 'PID_Controller'
//  '<S1>'   : 'PID_Controller/Controller'
//  '<S2>'   : 'PID_Controller/Controller/6 DOF Gain Scheduled PID'
//  '<S3>'   : 'PID_Controller/Controller/Thruster Forces to PWM'
//  '<S4>'   : 'PID_Controller/Controller/Zeroeing'
//  '<S5>'   : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2'
//  '<S6>'   : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3'
//  '<S7>'   : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4'
//  '<S8>'   : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/Yaw Overshoot Corrector'
//  '<S9>'   : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller'
//  '<S10>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/Anti-windup'
//  '<S11>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/D Gain'
//  '<S12>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/External Derivative'
//  '<S13>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/Filter'
//  '<S14>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/Filter ICs'
//  '<S15>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/I Gain'
//  '<S16>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/Ideal P Gain'
//  '<S17>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/Ideal P Gain Fdbk'
//  '<S18>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/Integrator'
//  '<S19>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/Integrator ICs'
//  '<S20>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/N Copy'
//  '<S21>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/N Gain'
//  '<S22>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/P Copy'
//  '<S23>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/Parallel P Gain'
//  '<S24>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/Reset Signal'
//  '<S25>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/Saturation'
//  '<S26>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/Saturation Fdbk'
//  '<S27>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/Sum'
//  '<S28>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/Sum Fdbk'
//  '<S29>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/Tracking Mode'
//  '<S30>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/Tracking Mode Sum'
//  '<S31>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/Tsamp - Integral'
//  '<S32>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/Tsamp - Ngain'
//  '<S33>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/postSat Signal'
//  '<S34>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/preSat Signal'
//  '<S35>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/Anti-windup/Passthrough'
//  '<S36>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/D Gain/Internal Parameters'
//  '<S37>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/External Derivative/Error'
//  '<S38>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/Filter/Disc. Forward Euler Filter'
//  '<S39>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/Filter ICs/Internal IC - Filter'
//  '<S40>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/I Gain/Internal Parameters'
//  '<S41>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/Ideal P Gain/Passthrough'
//  '<S42>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/Ideal P Gain Fdbk/Disabled'
//  '<S43>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/Integrator/Discrete'
//  '<S44>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/Integrator ICs/Internal IC'
//  '<S45>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/N Copy/Disabled'
//  '<S46>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/N Gain/Internal Parameters'
//  '<S47>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/P Copy/Disabled'
//  '<S48>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/Parallel P Gain/Internal Parameters'
//  '<S49>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/Reset Signal/Disabled'
//  '<S50>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/Saturation/Enabled'
//  '<S51>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/Saturation Fdbk/Disabled'
//  '<S52>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/Sum/Sum_PID'
//  '<S53>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/Sum Fdbk/Disabled'
//  '<S54>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/Tracking Mode/Disabled'
//  '<S55>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/Tracking Mode Sum/Passthrough'
//  '<S56>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/Tsamp - Integral/TsSignalSpecification'
//  '<S57>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/Tsamp - Ngain/Passthrough'
//  '<S58>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/postSat Signal/Forward_Path'
//  '<S59>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller2/preSat Signal/Forward_Path'
//  '<S60>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/Anti-windup'
//  '<S61>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/D Gain'
//  '<S62>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/External Derivative'
//  '<S63>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/Filter'
//  '<S64>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/Filter ICs'
//  '<S65>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/I Gain'
//  '<S66>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/Ideal P Gain'
//  '<S67>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/Ideal P Gain Fdbk'
//  '<S68>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/Integrator'
//  '<S69>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/Integrator ICs'
//  '<S70>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/N Copy'
//  '<S71>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/N Gain'
//  '<S72>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/P Copy'
//  '<S73>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/Parallel P Gain'
//  '<S74>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/Reset Signal'
//  '<S75>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/Saturation'
//  '<S76>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/Saturation Fdbk'
//  '<S77>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/Sum'
//  '<S78>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/Sum Fdbk'
//  '<S79>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/Tracking Mode'
//  '<S80>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/Tracking Mode Sum'
//  '<S81>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/Tsamp - Integral'
//  '<S82>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/Tsamp - Ngain'
//  '<S83>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/postSat Signal'
//  '<S84>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/preSat Signal'
//  '<S85>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/Anti-windup/Passthrough'
//  '<S86>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/D Gain/Internal Parameters'
//  '<S87>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/External Derivative/Error'
//  '<S88>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/Filter/Disc. Forward Euler Filter'
//  '<S89>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/Filter ICs/Internal IC - Filter'
//  '<S90>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/I Gain/Internal Parameters'
//  '<S91>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/Ideal P Gain/Passthrough'
//  '<S92>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/Ideal P Gain Fdbk/Disabled'
//  '<S93>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/Integrator/Discrete'
//  '<S94>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/Integrator ICs/Internal IC'
//  '<S95>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/N Copy/Disabled'
//  '<S96>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/N Gain/Internal Parameters'
//  '<S97>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/P Copy/Disabled'
//  '<S98>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/Parallel P Gain/Internal Parameters'
//  '<S99>'  : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/Reset Signal/Disabled'
//  '<S100>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/Saturation/Enabled'
//  '<S101>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/Saturation Fdbk/Disabled'
//  '<S102>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/Sum/Sum_PID'
//  '<S103>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/Sum Fdbk/Disabled'
//  '<S104>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/Tracking Mode/Disabled'
//  '<S105>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/Tracking Mode Sum/Passthrough'
//  '<S106>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/Tsamp - Integral/TsSignalSpecification'
//  '<S107>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/Tsamp - Ngain/Passthrough'
//  '<S108>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/postSat Signal/Forward_Path'
//  '<S109>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller3/preSat Signal/Forward_Path'
//  '<S110>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/Anti-windup'
//  '<S111>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/D Gain'
//  '<S112>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/External Derivative'
//  '<S113>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/Filter'
//  '<S114>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/Filter ICs'
//  '<S115>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/I Gain'
//  '<S116>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/Ideal P Gain'
//  '<S117>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/Ideal P Gain Fdbk'
//  '<S118>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/Integrator'
//  '<S119>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/Integrator ICs'
//  '<S120>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/N Copy'
//  '<S121>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/N Gain'
//  '<S122>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/P Copy'
//  '<S123>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/Parallel P Gain'
//  '<S124>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/Reset Signal'
//  '<S125>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/Saturation'
//  '<S126>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/Saturation Fdbk'
//  '<S127>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/Sum'
//  '<S128>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/Sum Fdbk'
//  '<S129>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/Tracking Mode'
//  '<S130>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/Tracking Mode Sum'
//  '<S131>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/Tsamp - Integral'
//  '<S132>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/Tsamp - Ngain'
//  '<S133>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/postSat Signal'
//  '<S134>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/preSat Signal'
//  '<S135>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/Anti-windup/Passthrough'
//  '<S136>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/D Gain/Internal Parameters'
//  '<S137>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/External Derivative/Error'
//  '<S138>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/Filter/Disc. Forward Euler Filter'
//  '<S139>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/Filter ICs/Internal IC - Filter'
//  '<S140>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/I Gain/Internal Parameters'
//  '<S141>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/Ideal P Gain/Passthrough'
//  '<S142>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/Ideal P Gain Fdbk/Disabled'
//  '<S143>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/Integrator/Discrete'
//  '<S144>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/Integrator ICs/Internal IC'
//  '<S145>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/N Copy/Disabled'
//  '<S146>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/N Gain/Internal Parameters'
//  '<S147>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/P Copy/Disabled'
//  '<S148>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/Parallel P Gain/Internal Parameters'
//  '<S149>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/Reset Signal/Disabled'
//  '<S150>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/Saturation/Enabled'
//  '<S151>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/Saturation Fdbk/Disabled'
//  '<S152>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/Sum/Sum_PID'
//  '<S153>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/Sum Fdbk/Disabled'
//  '<S154>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/Tracking Mode/Disabled'
//  '<S155>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/Tracking Mode Sum/Passthrough'
//  '<S156>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/Tsamp - Integral/TsSignalSpecification'
//  '<S157>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/Tsamp - Ngain/Passthrough'
//  '<S158>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/postSat Signal/Forward_Path'
//  '<S159>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/PID Controller4/preSat Signal/Forward_Path'
//  '<S160>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/Anti-windup'
//  '<S161>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/D Gain'
//  '<S162>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/External Derivative'
//  '<S163>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/Filter'
//  '<S164>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/Filter ICs'
//  '<S165>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/I Gain'
//  '<S166>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/Ideal P Gain'
//  '<S167>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/Ideal P Gain Fdbk'
//  '<S168>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/Integrator'
//  '<S169>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/Integrator ICs'
//  '<S170>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/N Copy'
//  '<S171>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/N Gain'
//  '<S172>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/P Copy'
//  '<S173>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/Parallel P Gain'
//  '<S174>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/Reset Signal'
//  '<S175>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/Saturation'
//  '<S176>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/Saturation Fdbk'
//  '<S177>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/Sum'
//  '<S178>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/Sum Fdbk'
//  '<S179>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/Tracking Mode'
//  '<S180>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/Tracking Mode Sum'
//  '<S181>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/Tsamp - Integral'
//  '<S182>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/Tsamp - Ngain'
//  '<S183>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/postSat Signal'
//  '<S184>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/preSat Signal'
//  '<S185>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/Anti-windup/Passthrough'
//  '<S186>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/D Gain/Internal Parameters'
//  '<S187>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/External Derivative/Error'
//  '<S188>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/Filter/Disc. Forward Euler Filter'
//  '<S189>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/Filter ICs/Internal IC - Filter'
//  '<S190>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/I Gain/Internal Parameters'
//  '<S191>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/Ideal P Gain/Passthrough'
//  '<S192>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/Ideal P Gain Fdbk/Disabled'
//  '<S193>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/Integrator/Discrete'
//  '<S194>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/Integrator ICs/Internal IC'
//  '<S195>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/N Copy/Disabled'
//  '<S196>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/N Gain/Internal Parameters'
//  '<S197>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/P Copy/Disabled'
//  '<S198>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/Parallel P Gain/Internal Parameters'
//  '<S199>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/Reset Signal/Disabled'
//  '<S200>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/Saturation/Enabled'
//  '<S201>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/Saturation Fdbk/Disabled'
//  '<S202>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/Sum/Sum_PID'
//  '<S203>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/Sum Fdbk/Disabled'
//  '<S204>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/Tracking Mode/Disabled'
//  '<S205>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/Tracking Mode Sum/Passthrough'
//  '<S206>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/Tsamp - Integral/TsSignalSpecification'
//  '<S207>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/Tsamp - Ngain/Passthrough'
//  '<S208>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/postSat Signal/Forward_Path'
//  '<S209>' : 'PID_Controller/Controller/6 DOF Gain Scheduled PID/xyz controller/preSat Signal/Forward_Path'

#endif                                 // PID_Controller_h_

//
// File trailer for generated code.
//
// [EOF]
//
