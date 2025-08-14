//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: PID_Controller.h
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
  // Block signals (default storage)
  struct B_PID_Controller_T {
    real_T DCMeb[9];
    real_T x[9];
    real_T DCMbe[9];                   // '<S1>/MATLAB Function'
    real_T Sum[6];                     // '<S1>/Sum'
    real_T rtb_DCMbe_m[6];
    real_T DCMeb_c[3];
    real_T absx11;
    real_T absx21;
    real_T absx31;
    real_T t1;
    real_T y;
    real_T DeadZone_f;                 // '<S311>/DeadZone'
    real_T DeadZone_k;                 // '<S203>/DeadZone'
    real_T DeadZone_b;                 // '<S41>/DeadZone'
    real_T corrected_error;            // '<S2>/Yaw Overshoot Corrector'
    real_T NProdOut_g;                 // '<S52>/NProd Out'
    real_T DeadZone_e;                 // '<S95>/DeadZone'
    real_T NProdOut_i;                 // '<S106>/NProd Out'
    real_T DeadZone_j;                 // '<S149>/DeadZone'
  };

  // Block states (default storage) for system '<Root>'
  struct DW_PID_Controller_T {
    real_T Integrator_DSTATE;          // '<S265>/Integrator'
    real_T Filter_DSTATE;              // '<S260>/Filter'
    real_T Integrator_DSTATE_a;        // '<S319>/Integrator'
    real_T Filter_DSTATE_m;            // '<S314>/Filter'
    real_T Integrator_DSTATE_h;        // '<S211>/Integrator'
    real_T Filter_DSTATE_a;            // '<S206>/Filter'
    real_T Integrator_DSTATE_g;        // '<S49>/Integrator'
    real_T Filter_DSTATE_h;            // '<S44>/Filter'
    real_T Integrator_DSTATE_l;        // '<S103>/Integrator'
    real_T Filter_DSTATE_o;            // '<S98>/Filter'
    real_T Integrator_DSTATE_h3;       // '<S157>/Integrator'
    real_T Filter_DSTATE_n;            // '<S152>/Filter'
  };

  // Constant parameters (default storage)
  struct ConstP_PID_Controller_T {
    // Expression: inverse_wrench
    //  Referenced by: '<S1>/Constant'

    real_T Constant_Value[48];
  };

  // External inputs (root inport signals with default storage)
  struct ExtU_PID_Controller_T {
    real_T controller_mode;            // '<Root>/controller_mode'
    real_T DFC_error[2];               // '<Root>/DFC_error'
    real_T waypoint[6];                // '<Root>/waypoint'
    real_T states[6];                  // '<Root>/states'
    real_T PIDN_X[4];                  // '<Root>/PIDN_X'
    real_T PIDN_Y[4];                  // '<Root>/PIDN_Y'
    real_T PIDN_Z[4];                  // '<Root>/PIDN_Z'
    real_T PIDN_roll[4];               // '<Root>/PIDN_roll'
    real_T PIDN_pitch[4];              // '<Root>/PIDN_pitch'
    real_T PIDN_yaw[4];                // '<Root>/PIDN_yaw'
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

  // Block signals
  B_PID_Controller_T PID_Controller_B;

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
//  '<S1>'   : 'PID_Controller/Controller2'
//  '<S2>'   : 'PID_Controller/Controller2/6dof PID'
//  '<S3>'   : 'PID_Controller/Controller2/MATLAB Function'
//  '<S4>'   : 'PID_Controller/Controller2/PWM Clamping'
//  '<S5>'   : 'PID_Controller/Controller2/Thruster Forces to PWM'
//  '<S6>'   : 'PID_Controller/Controller2/6dof PID/PID Controller1'
//  '<S7>'   : 'PID_Controller/Controller2/6dof PID/PID Controller2'
//  '<S8>'   : 'PID_Controller/Controller2/6dof PID/PID Controller3'
//  '<S9>'   : 'PID_Controller/Controller2/6dof PID/PID Controller4'
//  '<S10>'  : 'PID_Controller/Controller2/6dof PID/PID Controller5'
//  '<S11>'  : 'PID_Controller/Controller2/6dof PID/PID Controller6'
//  '<S12>'  : 'PID_Controller/Controller2/6dof PID/Yaw Overshoot Corrector'
//  '<S13>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Anti-windup'
//  '<S14>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/D Gain'
//  '<S15>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/External Derivative'
//  '<S16>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Filter'
//  '<S17>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Filter ICs'
//  '<S18>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/I Gain'
//  '<S19>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Ideal P Gain'
//  '<S20>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Ideal P Gain Fdbk'
//  '<S21>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Integrator'
//  '<S22>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Integrator ICs'
//  '<S23>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/N Copy'
//  '<S24>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/N Gain'
//  '<S25>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/P Copy'
//  '<S26>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Parallel P Gain'
//  '<S27>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Reset Signal'
//  '<S28>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Saturation'
//  '<S29>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Saturation Fdbk'
//  '<S30>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Sum'
//  '<S31>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Sum Fdbk'
//  '<S32>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Tracking Mode'
//  '<S33>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Tracking Mode Sum'
//  '<S34>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Tsamp - Integral'
//  '<S35>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Tsamp - Ngain'
//  '<S36>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/postSat Signal'
//  '<S37>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/preInt Signal'
//  '<S38>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/preSat Signal'
//  '<S39>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Anti-windup/Disc. Clamping Parallel'
//  '<S40>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S41>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S42>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/D Gain/External Parameters'
//  '<S43>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/External Derivative/Error'
//  '<S44>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Filter/Disc. Forward Euler Filter'
//  '<S45>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Filter ICs/Internal IC - Filter'
//  '<S46>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/I Gain/External Parameters'
//  '<S47>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Ideal P Gain/Passthrough'
//  '<S48>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S49>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Integrator/Discrete'
//  '<S50>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Integrator ICs/Internal IC'
//  '<S51>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/N Copy/Disabled'
//  '<S52>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/N Gain/External Parameters'
//  '<S53>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/P Copy/Disabled'
//  '<S54>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Parallel P Gain/External Parameters'
//  '<S55>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Reset Signal/Disabled'
//  '<S56>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Saturation/Enabled'
//  '<S57>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Saturation Fdbk/Disabled'
//  '<S58>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Sum/Sum_PID'
//  '<S59>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Sum Fdbk/Disabled'
//  '<S60>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Tracking Mode/Disabled'
//  '<S61>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S62>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Tsamp - Integral/TsSignalSpecification'
//  '<S63>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S64>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/postSat Signal/Forward_Path'
//  '<S65>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/preInt Signal/Internal PreInt'
//  '<S66>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/preSat Signal/Forward_Path'
//  '<S67>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Anti-windup'
//  '<S68>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/D Gain'
//  '<S69>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/External Derivative'
//  '<S70>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Filter'
//  '<S71>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Filter ICs'
//  '<S72>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/I Gain'
//  '<S73>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Ideal P Gain'
//  '<S74>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Ideal P Gain Fdbk'
//  '<S75>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Integrator'
//  '<S76>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Integrator ICs'
//  '<S77>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/N Copy'
//  '<S78>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/N Gain'
//  '<S79>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/P Copy'
//  '<S80>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Parallel P Gain'
//  '<S81>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Reset Signal'
//  '<S82>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Saturation'
//  '<S83>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Saturation Fdbk'
//  '<S84>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Sum'
//  '<S85>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Sum Fdbk'
//  '<S86>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Tracking Mode'
//  '<S87>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Tracking Mode Sum'
//  '<S88>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Tsamp - Integral'
//  '<S89>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Tsamp - Ngain'
//  '<S90>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/postSat Signal'
//  '<S91>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/preInt Signal'
//  '<S92>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/preSat Signal'
//  '<S93>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Anti-windup/Disc. Clamping Parallel'
//  '<S94>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S95>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S96>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/D Gain/External Parameters'
//  '<S97>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/External Derivative/Error'
//  '<S98>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Filter/Disc. Forward Euler Filter'
//  '<S99>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Filter ICs/Internal IC - Filter'
//  '<S100>' : 'PID_Controller/Controller2/6dof PID/PID Controller2/I Gain/External Parameters'
//  '<S101>' : 'PID_Controller/Controller2/6dof PID/PID Controller2/Ideal P Gain/Passthrough'
//  '<S102>' : 'PID_Controller/Controller2/6dof PID/PID Controller2/Ideal P Gain Fdbk/Disabled'
//  '<S103>' : 'PID_Controller/Controller2/6dof PID/PID Controller2/Integrator/Discrete'
//  '<S104>' : 'PID_Controller/Controller2/6dof PID/PID Controller2/Integrator ICs/Internal IC'
//  '<S105>' : 'PID_Controller/Controller2/6dof PID/PID Controller2/N Copy/Disabled'
//  '<S106>' : 'PID_Controller/Controller2/6dof PID/PID Controller2/N Gain/External Parameters'
//  '<S107>' : 'PID_Controller/Controller2/6dof PID/PID Controller2/P Copy/Disabled'
//  '<S108>' : 'PID_Controller/Controller2/6dof PID/PID Controller2/Parallel P Gain/External Parameters'
//  '<S109>' : 'PID_Controller/Controller2/6dof PID/PID Controller2/Reset Signal/Disabled'
//  '<S110>' : 'PID_Controller/Controller2/6dof PID/PID Controller2/Saturation/Enabled'
//  '<S111>' : 'PID_Controller/Controller2/6dof PID/PID Controller2/Saturation Fdbk/Disabled'
//  '<S112>' : 'PID_Controller/Controller2/6dof PID/PID Controller2/Sum/Sum_PID'
//  '<S113>' : 'PID_Controller/Controller2/6dof PID/PID Controller2/Sum Fdbk/Disabled'
//  '<S114>' : 'PID_Controller/Controller2/6dof PID/PID Controller2/Tracking Mode/Disabled'
//  '<S115>' : 'PID_Controller/Controller2/6dof PID/PID Controller2/Tracking Mode Sum/Passthrough'
//  '<S116>' : 'PID_Controller/Controller2/6dof PID/PID Controller2/Tsamp - Integral/TsSignalSpecification'
//  '<S117>' : 'PID_Controller/Controller2/6dof PID/PID Controller2/Tsamp - Ngain/Passthrough'
//  '<S118>' : 'PID_Controller/Controller2/6dof PID/PID Controller2/postSat Signal/Forward_Path'
//  '<S119>' : 'PID_Controller/Controller2/6dof PID/PID Controller2/preInt Signal/Internal PreInt'
//  '<S120>' : 'PID_Controller/Controller2/6dof PID/PID Controller2/preSat Signal/Forward_Path'
//  '<S121>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Anti-windup'
//  '<S122>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/D Gain'
//  '<S123>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/External Derivative'
//  '<S124>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Filter'
//  '<S125>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Filter ICs'
//  '<S126>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/I Gain'
//  '<S127>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Ideal P Gain'
//  '<S128>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Ideal P Gain Fdbk'
//  '<S129>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Integrator'
//  '<S130>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Integrator ICs'
//  '<S131>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/N Copy'
//  '<S132>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/N Gain'
//  '<S133>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/P Copy'
//  '<S134>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Parallel P Gain'
//  '<S135>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Reset Signal'
//  '<S136>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Saturation'
//  '<S137>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Saturation Fdbk'
//  '<S138>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Sum'
//  '<S139>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Sum Fdbk'
//  '<S140>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Tracking Mode'
//  '<S141>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Tracking Mode Sum'
//  '<S142>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Tsamp - Integral'
//  '<S143>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Tsamp - Ngain'
//  '<S144>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/postSat Signal'
//  '<S145>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/preInt Signal'
//  '<S146>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/preSat Signal'
//  '<S147>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Anti-windup/Disc. Clamping Parallel'
//  '<S148>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S149>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S150>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/D Gain/External Parameters'
//  '<S151>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/External Derivative/Error'
//  '<S152>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Filter/Disc. Forward Euler Filter'
//  '<S153>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Filter ICs/Internal IC - Filter'
//  '<S154>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/I Gain/External Parameters'
//  '<S155>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Ideal P Gain/Passthrough'
//  '<S156>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Ideal P Gain Fdbk/Disabled'
//  '<S157>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Integrator/Discrete'
//  '<S158>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Integrator ICs/Internal IC'
//  '<S159>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/N Copy/Disabled'
//  '<S160>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/N Gain/External Parameters'
//  '<S161>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/P Copy/Disabled'
//  '<S162>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Parallel P Gain/External Parameters'
//  '<S163>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Reset Signal/Disabled'
//  '<S164>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Saturation/Enabled'
//  '<S165>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Saturation Fdbk/Disabled'
//  '<S166>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Sum/Sum_PID'
//  '<S167>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Sum Fdbk/Disabled'
//  '<S168>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Tracking Mode/Disabled'
//  '<S169>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Tracking Mode Sum/Passthrough'
//  '<S170>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Tsamp - Integral/TsSignalSpecification'
//  '<S171>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Tsamp - Ngain/Passthrough'
//  '<S172>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/postSat Signal/Forward_Path'
//  '<S173>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/preInt Signal/Internal PreInt'
//  '<S174>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/preSat Signal/Forward_Path'
//  '<S175>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Anti-windup'
//  '<S176>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/D Gain'
//  '<S177>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/External Derivative'
//  '<S178>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Filter'
//  '<S179>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Filter ICs'
//  '<S180>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/I Gain'
//  '<S181>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Ideal P Gain'
//  '<S182>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Ideal P Gain Fdbk'
//  '<S183>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Integrator'
//  '<S184>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Integrator ICs'
//  '<S185>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/N Copy'
//  '<S186>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/N Gain'
//  '<S187>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/P Copy'
//  '<S188>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Parallel P Gain'
//  '<S189>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Reset Signal'
//  '<S190>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Saturation'
//  '<S191>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Saturation Fdbk'
//  '<S192>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Sum'
//  '<S193>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Sum Fdbk'
//  '<S194>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Tracking Mode'
//  '<S195>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Tracking Mode Sum'
//  '<S196>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Tsamp - Integral'
//  '<S197>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Tsamp - Ngain'
//  '<S198>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/postSat Signal'
//  '<S199>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/preInt Signal'
//  '<S200>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/preSat Signal'
//  '<S201>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Anti-windup/Disc. Clamping Parallel'
//  '<S202>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S203>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S204>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/D Gain/External Parameters'
//  '<S205>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/External Derivative/Error'
//  '<S206>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Filter/Disc. Forward Euler Filter'
//  '<S207>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Filter ICs/Internal IC - Filter'
//  '<S208>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/I Gain/External Parameters'
//  '<S209>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Ideal P Gain/Passthrough'
//  '<S210>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Ideal P Gain Fdbk/Disabled'
//  '<S211>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Integrator/Discrete'
//  '<S212>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Integrator ICs/Internal IC'
//  '<S213>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/N Copy/Disabled'
//  '<S214>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/N Gain/External Parameters'
//  '<S215>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/P Copy/Disabled'
//  '<S216>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Parallel P Gain/External Parameters'
//  '<S217>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Reset Signal/Disabled'
//  '<S218>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Saturation/Enabled'
//  '<S219>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Saturation Fdbk/Disabled'
//  '<S220>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Sum/Sum_PID'
//  '<S221>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Sum Fdbk/Disabled'
//  '<S222>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Tracking Mode/Disabled'
//  '<S223>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Tracking Mode Sum/Passthrough'
//  '<S224>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Tsamp - Integral/TsSignalSpecification'
//  '<S225>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Tsamp - Ngain/Passthrough'
//  '<S226>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/postSat Signal/Forward_Path'
//  '<S227>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/preInt Signal/Internal PreInt'
//  '<S228>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/preSat Signal/Forward_Path'
//  '<S229>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/Anti-windup'
//  '<S230>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/D Gain'
//  '<S231>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/External Derivative'
//  '<S232>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/Filter'
//  '<S233>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/Filter ICs'
//  '<S234>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/I Gain'
//  '<S235>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/Ideal P Gain'
//  '<S236>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/Ideal P Gain Fdbk'
//  '<S237>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/Integrator'
//  '<S238>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/Integrator ICs'
//  '<S239>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/N Copy'
//  '<S240>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/N Gain'
//  '<S241>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/P Copy'
//  '<S242>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/Parallel P Gain'
//  '<S243>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/Reset Signal'
//  '<S244>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/Saturation'
//  '<S245>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/Saturation Fdbk'
//  '<S246>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/Sum'
//  '<S247>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/Sum Fdbk'
//  '<S248>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/Tracking Mode'
//  '<S249>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/Tracking Mode Sum'
//  '<S250>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/Tsamp - Integral'
//  '<S251>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/Tsamp - Ngain'
//  '<S252>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/postSat Signal'
//  '<S253>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/preInt Signal'
//  '<S254>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/preSat Signal'
//  '<S255>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/Anti-windup/Disc. Clamping Parallel'
//  '<S256>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S257>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S258>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/D Gain/External Parameters'
//  '<S259>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/External Derivative/Error'
//  '<S260>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/Filter/Disc. Forward Euler Filter'
//  '<S261>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/Filter ICs/Internal IC - Filter'
//  '<S262>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/I Gain/External Parameters'
//  '<S263>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/Ideal P Gain/Passthrough'
//  '<S264>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/Ideal P Gain Fdbk/Disabled'
//  '<S265>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/Integrator/Discrete'
//  '<S266>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/Integrator ICs/Internal IC'
//  '<S267>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/N Copy/Disabled'
//  '<S268>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/N Gain/External Parameters'
//  '<S269>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/P Copy/Disabled'
//  '<S270>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/Parallel P Gain/External Parameters'
//  '<S271>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/Reset Signal/Disabled'
//  '<S272>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/Saturation/Enabled'
//  '<S273>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/Saturation Fdbk/Disabled'
//  '<S274>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/Sum/Sum_PID'
//  '<S275>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/Sum Fdbk/Disabled'
//  '<S276>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/Tracking Mode/Disabled'
//  '<S277>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/Tracking Mode Sum/Passthrough'
//  '<S278>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/Tsamp - Integral/TsSignalSpecification'
//  '<S279>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/Tsamp - Ngain/Passthrough'
//  '<S280>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/postSat Signal/Forward_Path'
//  '<S281>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/preInt Signal/Internal PreInt'
//  '<S282>' : 'PID_Controller/Controller2/6dof PID/PID Controller5/preSat Signal/Forward_Path'
//  '<S283>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/Anti-windup'
//  '<S284>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/D Gain'
//  '<S285>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/External Derivative'
//  '<S286>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/Filter'
//  '<S287>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/Filter ICs'
//  '<S288>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/I Gain'
//  '<S289>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/Ideal P Gain'
//  '<S290>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/Ideal P Gain Fdbk'
//  '<S291>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/Integrator'
//  '<S292>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/Integrator ICs'
//  '<S293>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/N Copy'
//  '<S294>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/N Gain'
//  '<S295>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/P Copy'
//  '<S296>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/Parallel P Gain'
//  '<S297>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/Reset Signal'
//  '<S298>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/Saturation'
//  '<S299>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/Saturation Fdbk'
//  '<S300>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/Sum'
//  '<S301>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/Sum Fdbk'
//  '<S302>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/Tracking Mode'
//  '<S303>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/Tracking Mode Sum'
//  '<S304>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/Tsamp - Integral'
//  '<S305>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/Tsamp - Ngain'
//  '<S306>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/postSat Signal'
//  '<S307>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/preInt Signal'
//  '<S308>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/preSat Signal'
//  '<S309>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/Anti-windup/Disc. Clamping Parallel'
//  '<S310>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S311>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S312>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/D Gain/External Parameters'
//  '<S313>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/External Derivative/Error'
//  '<S314>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/Filter/Disc. Forward Euler Filter'
//  '<S315>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/Filter ICs/Internal IC - Filter'
//  '<S316>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/I Gain/External Parameters'
//  '<S317>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/Ideal P Gain/Passthrough'
//  '<S318>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/Ideal P Gain Fdbk/Disabled'
//  '<S319>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/Integrator/Discrete'
//  '<S320>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/Integrator ICs/Internal IC'
//  '<S321>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/N Copy/Disabled'
//  '<S322>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/N Gain/External Parameters'
//  '<S323>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/P Copy/Disabled'
//  '<S324>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/Parallel P Gain/External Parameters'
//  '<S325>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/Reset Signal/Disabled'
//  '<S326>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/Saturation/Enabled'
//  '<S327>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/Saturation Fdbk/Disabled'
//  '<S328>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/Sum/Sum_PID'
//  '<S329>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/Sum Fdbk/Disabled'
//  '<S330>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/Tracking Mode/Disabled'
//  '<S331>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/Tracking Mode Sum/Passthrough'
//  '<S332>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/Tsamp - Integral/TsSignalSpecification'
//  '<S333>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/Tsamp - Ngain/Passthrough'
//  '<S334>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/postSat Signal/Forward_Path'
//  '<S335>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/preInt Signal/Internal PreInt'
//  '<S336>' : 'PID_Controller/Controller2/6dof PID/PID Controller6/preSat Signal/Forward_Path'

#endif                                 // PID_Controller_h_

//
// File trailer for generated code.
//
// [EOF]
//
