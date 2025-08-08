//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: PID_Controller.h
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

// Class declaration for model PID_Controller
class PID_Controller final
{
  // public data and function members
 public:
  // Block states (default storage) for system '<Root>'
  struct DW_PID_Controller_T {
    real_T Integrator_DSTATE[3];       // '<S204>/Integrator'
    real_T Filter_DSTATE[3];           // '<S199>/Filter'
    real_T Integrator_DSTATE_n;        // '<S46>/Integrator'
    real_T Filter_DSTATE_c;            // '<S41>/Filter'
    real_T Integrator_DSTATE_p;        // '<S100>/Integrator'
    real_T Filter_DSTATE_l;            // '<S95>/Filter'
    real_T Integrator_DSTATE_pu;       // '<S152>/Integrator'
    real_T Filter_DSTATE_f;            // '<S147>/Filter'
  };

  // Constant parameters (default storage)
  struct ConstP_PID_Controller_T {
    // Expression: inverse_wrench
    //  Referenced by: '<S1>/Constant'

    real_T Constant_Value[48];
  };

  // External inputs (root inport signals with default storage)
  struct ExtU_PID_Controller_T {
    real_T state_error_e[6];           // '<Root>/state_error_e'
    real_T DCMbe[9];                   // '<Root>/DCMbe'
    real_T controller_mode;            // '<Root>/controller_mode'
    real_T dfc_error[2];               // '<Root>/dfc_error'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_PID_Controller_T {
    real_T PWM[8];                     // '<Root>/PWM'
  };

  // Real-time Model Data Structure
  struct RT_MODEL_PID_Controller_T {
    const char_T * volatile errorStatus;
    const char_T* getErrorStatus() const;
    void setErrorStatus(const char_T* const volatile aErrorStatus);
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
//  '<S1>'   : 'PID_Controller/Controller1'
//  '<S2>'   : 'PID_Controller/Controller1/6dof PID'
//  '<S3>'   : 'PID_Controller/Controller1/Mode Selector'
//  '<S4>'   : 'PID_Controller/Controller1/Thruster Forces to PWM'
//  '<S5>'   : 'PID_Controller/Controller1/6dof PID/PID Controller2'
//  '<S6>'   : 'PID_Controller/Controller1/6dof PID/PID Controller3'
//  '<S7>'   : 'PID_Controller/Controller1/6dof PID/PID Controller4'
//  '<S8>'   : 'PID_Controller/Controller1/6dof PID/Yaw Overshoot Corrector'
//  '<S9>'   : 'PID_Controller/Controller1/6dof PID/xyz controller'
//  '<S10>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/Anti-windup'
//  '<S11>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/D Gain'
//  '<S12>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/External Derivative'
//  '<S13>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/Filter'
//  '<S14>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/Filter ICs'
//  '<S15>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/I Gain'
//  '<S16>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/Ideal P Gain'
//  '<S17>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/Ideal P Gain Fdbk'
//  '<S18>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/Integrator'
//  '<S19>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/Integrator ICs'
//  '<S20>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/N Copy'
//  '<S21>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/N Gain'
//  '<S22>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/P Copy'
//  '<S23>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/Parallel P Gain'
//  '<S24>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/Reset Signal'
//  '<S25>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/Saturation'
//  '<S26>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/Saturation Fdbk'
//  '<S27>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/Sum'
//  '<S28>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/Sum Fdbk'
//  '<S29>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/Tracking Mode'
//  '<S30>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/Tracking Mode Sum'
//  '<S31>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/Tsamp - Integral'
//  '<S32>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/Tsamp - Ngain'
//  '<S33>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/postSat Signal'
//  '<S34>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/preInt Signal'
//  '<S35>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/preSat Signal'
//  '<S36>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/Anti-windup/Disc. Clamping Parallel'
//  '<S37>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S38>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S39>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/D Gain/Internal Parameters'
//  '<S40>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/External Derivative/Error'
//  '<S41>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/Filter/Disc. Forward Euler Filter'
//  '<S42>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/Filter ICs/Internal IC - Filter'
//  '<S43>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/I Gain/Internal Parameters'
//  '<S44>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/Ideal P Gain/Passthrough'
//  '<S45>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/Ideal P Gain Fdbk/Disabled'
//  '<S46>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/Integrator/Discrete'
//  '<S47>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/Integrator ICs/Internal IC'
//  '<S48>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/N Copy/Disabled'
//  '<S49>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/N Gain/Internal Parameters'
//  '<S50>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/P Copy/Disabled'
//  '<S51>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/Parallel P Gain/Internal Parameters'
//  '<S52>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/Reset Signal/Disabled'
//  '<S53>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/Saturation/Enabled'
//  '<S54>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/Saturation Fdbk/Disabled'
//  '<S55>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/Sum/Sum_PID'
//  '<S56>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/Sum Fdbk/Disabled'
//  '<S57>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/Tracking Mode/Disabled'
//  '<S58>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/Tracking Mode Sum/Passthrough'
//  '<S59>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/Tsamp - Integral/TsSignalSpecification'
//  '<S60>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/Tsamp - Ngain/Passthrough'
//  '<S61>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/postSat Signal/Forward_Path'
//  '<S62>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/preInt Signal/Internal PreInt'
//  '<S63>'  : 'PID_Controller/Controller1/6dof PID/PID Controller2/preSat Signal/Forward_Path'
//  '<S64>'  : 'PID_Controller/Controller1/6dof PID/PID Controller3/Anti-windup'
//  '<S65>'  : 'PID_Controller/Controller1/6dof PID/PID Controller3/D Gain'
//  '<S66>'  : 'PID_Controller/Controller1/6dof PID/PID Controller3/External Derivative'
//  '<S67>'  : 'PID_Controller/Controller1/6dof PID/PID Controller3/Filter'
//  '<S68>'  : 'PID_Controller/Controller1/6dof PID/PID Controller3/Filter ICs'
//  '<S69>'  : 'PID_Controller/Controller1/6dof PID/PID Controller3/I Gain'
//  '<S70>'  : 'PID_Controller/Controller1/6dof PID/PID Controller3/Ideal P Gain'
//  '<S71>'  : 'PID_Controller/Controller1/6dof PID/PID Controller3/Ideal P Gain Fdbk'
//  '<S72>'  : 'PID_Controller/Controller1/6dof PID/PID Controller3/Integrator'
//  '<S73>'  : 'PID_Controller/Controller1/6dof PID/PID Controller3/Integrator ICs'
//  '<S74>'  : 'PID_Controller/Controller1/6dof PID/PID Controller3/N Copy'
//  '<S75>'  : 'PID_Controller/Controller1/6dof PID/PID Controller3/N Gain'
//  '<S76>'  : 'PID_Controller/Controller1/6dof PID/PID Controller3/P Copy'
//  '<S77>'  : 'PID_Controller/Controller1/6dof PID/PID Controller3/Parallel P Gain'
//  '<S78>'  : 'PID_Controller/Controller1/6dof PID/PID Controller3/Reset Signal'
//  '<S79>'  : 'PID_Controller/Controller1/6dof PID/PID Controller3/Saturation'
//  '<S80>'  : 'PID_Controller/Controller1/6dof PID/PID Controller3/Saturation Fdbk'
//  '<S81>'  : 'PID_Controller/Controller1/6dof PID/PID Controller3/Sum'
//  '<S82>'  : 'PID_Controller/Controller1/6dof PID/PID Controller3/Sum Fdbk'
//  '<S83>'  : 'PID_Controller/Controller1/6dof PID/PID Controller3/Tracking Mode'
//  '<S84>'  : 'PID_Controller/Controller1/6dof PID/PID Controller3/Tracking Mode Sum'
//  '<S85>'  : 'PID_Controller/Controller1/6dof PID/PID Controller3/Tsamp - Integral'
//  '<S86>'  : 'PID_Controller/Controller1/6dof PID/PID Controller3/Tsamp - Ngain'
//  '<S87>'  : 'PID_Controller/Controller1/6dof PID/PID Controller3/postSat Signal'
//  '<S88>'  : 'PID_Controller/Controller1/6dof PID/PID Controller3/preInt Signal'
//  '<S89>'  : 'PID_Controller/Controller1/6dof PID/PID Controller3/preSat Signal'
//  '<S90>'  : 'PID_Controller/Controller1/6dof PID/PID Controller3/Anti-windup/Disc. Clamping Parallel'
//  '<S91>'  : 'PID_Controller/Controller1/6dof PID/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S92>'  : 'PID_Controller/Controller1/6dof PID/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S93>'  : 'PID_Controller/Controller1/6dof PID/PID Controller3/D Gain/Internal Parameters'
//  '<S94>'  : 'PID_Controller/Controller1/6dof PID/PID Controller3/External Derivative/Error'
//  '<S95>'  : 'PID_Controller/Controller1/6dof PID/PID Controller3/Filter/Disc. Forward Euler Filter'
//  '<S96>'  : 'PID_Controller/Controller1/6dof PID/PID Controller3/Filter ICs/Internal IC - Filter'
//  '<S97>'  : 'PID_Controller/Controller1/6dof PID/PID Controller3/I Gain/Internal Parameters'
//  '<S98>'  : 'PID_Controller/Controller1/6dof PID/PID Controller3/Ideal P Gain/Passthrough'
//  '<S99>'  : 'PID_Controller/Controller1/6dof PID/PID Controller3/Ideal P Gain Fdbk/Disabled'
//  '<S100>' : 'PID_Controller/Controller1/6dof PID/PID Controller3/Integrator/Discrete'
//  '<S101>' : 'PID_Controller/Controller1/6dof PID/PID Controller3/Integrator ICs/Internal IC'
//  '<S102>' : 'PID_Controller/Controller1/6dof PID/PID Controller3/N Copy/Disabled'
//  '<S103>' : 'PID_Controller/Controller1/6dof PID/PID Controller3/N Gain/Internal Parameters'
//  '<S104>' : 'PID_Controller/Controller1/6dof PID/PID Controller3/P Copy/Disabled'
//  '<S105>' : 'PID_Controller/Controller1/6dof PID/PID Controller3/Parallel P Gain/Internal Parameters'
//  '<S106>' : 'PID_Controller/Controller1/6dof PID/PID Controller3/Reset Signal/Disabled'
//  '<S107>' : 'PID_Controller/Controller1/6dof PID/PID Controller3/Saturation/Enabled'
//  '<S108>' : 'PID_Controller/Controller1/6dof PID/PID Controller3/Saturation Fdbk/Disabled'
//  '<S109>' : 'PID_Controller/Controller1/6dof PID/PID Controller3/Sum/Sum_PID'
//  '<S110>' : 'PID_Controller/Controller1/6dof PID/PID Controller3/Sum Fdbk/Disabled'
//  '<S111>' : 'PID_Controller/Controller1/6dof PID/PID Controller3/Tracking Mode/Disabled'
//  '<S112>' : 'PID_Controller/Controller1/6dof PID/PID Controller3/Tracking Mode Sum/Passthrough'
//  '<S113>' : 'PID_Controller/Controller1/6dof PID/PID Controller3/Tsamp - Integral/TsSignalSpecification'
//  '<S114>' : 'PID_Controller/Controller1/6dof PID/PID Controller3/Tsamp - Ngain/Passthrough'
//  '<S115>' : 'PID_Controller/Controller1/6dof PID/PID Controller3/postSat Signal/Forward_Path'
//  '<S116>' : 'PID_Controller/Controller1/6dof PID/PID Controller3/preInt Signal/Internal PreInt'
//  '<S117>' : 'PID_Controller/Controller1/6dof PID/PID Controller3/preSat Signal/Forward_Path'
//  '<S118>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/Anti-windup'
//  '<S119>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/D Gain'
//  '<S120>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/External Derivative'
//  '<S121>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/Filter'
//  '<S122>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/Filter ICs'
//  '<S123>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/I Gain'
//  '<S124>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/Ideal P Gain'
//  '<S125>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/Ideal P Gain Fdbk'
//  '<S126>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/Integrator'
//  '<S127>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/Integrator ICs'
//  '<S128>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/N Copy'
//  '<S129>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/N Gain'
//  '<S130>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/P Copy'
//  '<S131>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/Parallel P Gain'
//  '<S132>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/Reset Signal'
//  '<S133>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/Saturation'
//  '<S134>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/Saturation Fdbk'
//  '<S135>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/Sum'
//  '<S136>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/Sum Fdbk'
//  '<S137>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/Tracking Mode'
//  '<S138>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/Tracking Mode Sum'
//  '<S139>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/Tsamp - Integral'
//  '<S140>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/Tsamp - Ngain'
//  '<S141>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/postSat Signal'
//  '<S142>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/preInt Signal'
//  '<S143>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/preSat Signal'
//  '<S144>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/Anti-windup/Passthrough'
//  '<S145>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/D Gain/Internal Parameters'
//  '<S146>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/External Derivative/Error'
//  '<S147>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/Filter/Disc. Forward Euler Filter'
//  '<S148>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/Filter ICs/Internal IC - Filter'
//  '<S149>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/I Gain/Internal Parameters'
//  '<S150>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/Ideal P Gain/Passthrough'
//  '<S151>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/Ideal P Gain Fdbk/Disabled'
//  '<S152>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/Integrator/Discrete'
//  '<S153>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/Integrator ICs/Internal IC'
//  '<S154>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/N Copy/Disabled'
//  '<S155>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/N Gain/Internal Parameters'
//  '<S156>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/P Copy/Disabled'
//  '<S157>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/Parallel P Gain/Internal Parameters'
//  '<S158>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/Reset Signal/Disabled'
//  '<S159>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/Saturation/Enabled'
//  '<S160>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/Saturation Fdbk/Disabled'
//  '<S161>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/Sum/Sum_PID'
//  '<S162>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/Sum Fdbk/Disabled'
//  '<S163>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/Tracking Mode/Disabled'
//  '<S164>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/Tracking Mode Sum/Passthrough'
//  '<S165>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/Tsamp - Integral/TsSignalSpecification'
//  '<S166>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/Tsamp - Ngain/Passthrough'
//  '<S167>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/postSat Signal/Forward_Path'
//  '<S168>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/preInt Signal/Internal PreInt'
//  '<S169>' : 'PID_Controller/Controller1/6dof PID/PID Controller4/preSat Signal/Forward_Path'
//  '<S170>' : 'PID_Controller/Controller1/6dof PID/xyz controller/Anti-windup'
//  '<S171>' : 'PID_Controller/Controller1/6dof PID/xyz controller/D Gain'
//  '<S172>' : 'PID_Controller/Controller1/6dof PID/xyz controller/External Derivative'
//  '<S173>' : 'PID_Controller/Controller1/6dof PID/xyz controller/Filter'
//  '<S174>' : 'PID_Controller/Controller1/6dof PID/xyz controller/Filter ICs'
//  '<S175>' : 'PID_Controller/Controller1/6dof PID/xyz controller/I Gain'
//  '<S176>' : 'PID_Controller/Controller1/6dof PID/xyz controller/Ideal P Gain'
//  '<S177>' : 'PID_Controller/Controller1/6dof PID/xyz controller/Ideal P Gain Fdbk'
//  '<S178>' : 'PID_Controller/Controller1/6dof PID/xyz controller/Integrator'
//  '<S179>' : 'PID_Controller/Controller1/6dof PID/xyz controller/Integrator ICs'
//  '<S180>' : 'PID_Controller/Controller1/6dof PID/xyz controller/N Copy'
//  '<S181>' : 'PID_Controller/Controller1/6dof PID/xyz controller/N Gain'
//  '<S182>' : 'PID_Controller/Controller1/6dof PID/xyz controller/P Copy'
//  '<S183>' : 'PID_Controller/Controller1/6dof PID/xyz controller/Parallel P Gain'
//  '<S184>' : 'PID_Controller/Controller1/6dof PID/xyz controller/Reset Signal'
//  '<S185>' : 'PID_Controller/Controller1/6dof PID/xyz controller/Saturation'
//  '<S186>' : 'PID_Controller/Controller1/6dof PID/xyz controller/Saturation Fdbk'
//  '<S187>' : 'PID_Controller/Controller1/6dof PID/xyz controller/Sum'
//  '<S188>' : 'PID_Controller/Controller1/6dof PID/xyz controller/Sum Fdbk'
//  '<S189>' : 'PID_Controller/Controller1/6dof PID/xyz controller/Tracking Mode'
//  '<S190>' : 'PID_Controller/Controller1/6dof PID/xyz controller/Tracking Mode Sum'
//  '<S191>' : 'PID_Controller/Controller1/6dof PID/xyz controller/Tsamp - Integral'
//  '<S192>' : 'PID_Controller/Controller1/6dof PID/xyz controller/Tsamp - Ngain'
//  '<S193>' : 'PID_Controller/Controller1/6dof PID/xyz controller/postSat Signal'
//  '<S194>' : 'PID_Controller/Controller1/6dof PID/xyz controller/preInt Signal'
//  '<S195>' : 'PID_Controller/Controller1/6dof PID/xyz controller/preSat Signal'
//  '<S196>' : 'PID_Controller/Controller1/6dof PID/xyz controller/Anti-windup/Passthrough'
//  '<S197>' : 'PID_Controller/Controller1/6dof PID/xyz controller/D Gain/Internal Parameters'
//  '<S198>' : 'PID_Controller/Controller1/6dof PID/xyz controller/External Derivative/Error'
//  '<S199>' : 'PID_Controller/Controller1/6dof PID/xyz controller/Filter/Disc. Forward Euler Filter'
//  '<S200>' : 'PID_Controller/Controller1/6dof PID/xyz controller/Filter ICs/Internal IC - Filter'
//  '<S201>' : 'PID_Controller/Controller1/6dof PID/xyz controller/I Gain/Internal Parameters'
//  '<S202>' : 'PID_Controller/Controller1/6dof PID/xyz controller/Ideal P Gain/Passthrough'
//  '<S203>' : 'PID_Controller/Controller1/6dof PID/xyz controller/Ideal P Gain Fdbk/Disabled'
//  '<S204>' : 'PID_Controller/Controller1/6dof PID/xyz controller/Integrator/Discrete'
//  '<S205>' : 'PID_Controller/Controller1/6dof PID/xyz controller/Integrator ICs/Internal IC'
//  '<S206>' : 'PID_Controller/Controller1/6dof PID/xyz controller/N Copy/Disabled'
//  '<S207>' : 'PID_Controller/Controller1/6dof PID/xyz controller/N Gain/Internal Parameters'
//  '<S208>' : 'PID_Controller/Controller1/6dof PID/xyz controller/P Copy/Disabled'
//  '<S209>' : 'PID_Controller/Controller1/6dof PID/xyz controller/Parallel P Gain/Internal Parameters'
//  '<S210>' : 'PID_Controller/Controller1/6dof PID/xyz controller/Reset Signal/Disabled'
//  '<S211>' : 'PID_Controller/Controller1/6dof PID/xyz controller/Saturation/Enabled'
//  '<S212>' : 'PID_Controller/Controller1/6dof PID/xyz controller/Saturation Fdbk/Disabled'
//  '<S213>' : 'PID_Controller/Controller1/6dof PID/xyz controller/Sum/Sum_PID'
//  '<S214>' : 'PID_Controller/Controller1/6dof PID/xyz controller/Sum Fdbk/Disabled'
//  '<S215>' : 'PID_Controller/Controller1/6dof PID/xyz controller/Tracking Mode/Disabled'
//  '<S216>' : 'PID_Controller/Controller1/6dof PID/xyz controller/Tracking Mode Sum/Passthrough'
//  '<S217>' : 'PID_Controller/Controller1/6dof PID/xyz controller/Tsamp - Integral/TsSignalSpecification'
//  '<S218>' : 'PID_Controller/Controller1/6dof PID/xyz controller/Tsamp - Ngain/Passthrough'
//  '<S219>' : 'PID_Controller/Controller1/6dof PID/xyz controller/postSat Signal/Forward_Path'
//  '<S220>' : 'PID_Controller/Controller1/6dof PID/xyz controller/preInt Signal/Internal PreInt'
//  '<S221>' : 'PID_Controller/Controller1/6dof PID/xyz controller/preSat Signal/Forward_Path'

#endif                                 // PID_Controller_h_

//
// File trailer for generated code.
//
// [EOF]
//
