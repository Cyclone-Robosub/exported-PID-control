//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: PID_Controller.h
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
    real_T y;
    real_T FilterCoefficient_n;        // '<S104>/Filter Coefficient'
    real_T DeadZone_l;                 // '<S147>/DeadZone'
    real_T FilterCoefficient_c;        // '<S158>/Filter Coefficient'
    real_T corrected_error;            // '<S2>/Yaw Overshoot Corrector'
    real_T FilterCoefficient_e;        // '<S210>/Filter Coefficient'
    real_T st_idx_0;
    real_T st_idx_1;
    real_T ct_idx_0;
    real_T ct_idx_1;
  };

  // Block states (default storage) for system '<Root>'
  struct DW_PID_Controller_T {
    real_T Integrator_DSTATE[3];       // '<S47>/Integrator'
    real_T Filter_DSTATE[3];           // '<S42>/Filter'
    real_T Integrator_DSTATE_j;        // '<S101>/Integrator'
    real_T Filter_DSTATE_d;            // '<S96>/Filter'
    real_T Integrator_DSTATE_l;        // '<S155>/Integrator'
    real_T Filter_DSTATE_n;            // '<S150>/Filter'
    real_T Integrator_DSTATE_h;        // '<S207>/Integrator'
    real_T Filter_DSTATE_nq;           // '<S202>/Filter'
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
//  '<S10>'  : 'PID_Controller/Controller2/6dof PID/Yaw Overshoot Corrector'
//  '<S11>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Anti-windup'
//  '<S12>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/D Gain'
//  '<S13>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/External Derivative'
//  '<S14>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Filter'
//  '<S15>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Filter ICs'
//  '<S16>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/I Gain'
//  '<S17>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Ideal P Gain'
//  '<S18>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Ideal P Gain Fdbk'
//  '<S19>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Integrator'
//  '<S20>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Integrator ICs'
//  '<S21>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/N Copy'
//  '<S22>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/N Gain'
//  '<S23>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/P Copy'
//  '<S24>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Parallel P Gain'
//  '<S25>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Reset Signal'
//  '<S26>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Saturation'
//  '<S27>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Saturation Fdbk'
//  '<S28>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Sum'
//  '<S29>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Sum Fdbk'
//  '<S30>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Tracking Mode'
//  '<S31>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Tracking Mode Sum'
//  '<S32>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Tsamp - Integral'
//  '<S33>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Tsamp - Ngain'
//  '<S34>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/postSat Signal'
//  '<S35>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/preInt Signal'
//  '<S36>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/preSat Signal'
//  '<S37>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Anti-windup/Disc. Clamping Parallel'
//  '<S38>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S39>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S40>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/D Gain/Internal Parameters'
//  '<S41>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/External Derivative/Error'
//  '<S42>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Filter/Disc. Forward Euler Filter'
//  '<S43>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Filter ICs/Internal IC - Filter'
//  '<S44>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/I Gain/Internal Parameters'
//  '<S45>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Ideal P Gain/Passthrough'
//  '<S46>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S47>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Integrator/Discrete'
//  '<S48>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Integrator ICs/Internal IC'
//  '<S49>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/N Copy/Disabled'
//  '<S50>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/N Gain/Internal Parameters'
//  '<S51>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/P Copy/Disabled'
//  '<S52>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S53>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Reset Signal/Disabled'
//  '<S54>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Saturation/Enabled'
//  '<S55>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Saturation Fdbk/Disabled'
//  '<S56>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Sum/Sum_PID'
//  '<S57>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Sum Fdbk/Disabled'
//  '<S58>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Tracking Mode/Disabled'
//  '<S59>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S60>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Tsamp - Integral/TsSignalSpecification'
//  '<S61>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S62>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/postSat Signal/Forward_Path'
//  '<S63>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/preInt Signal/Internal PreInt'
//  '<S64>'  : 'PID_Controller/Controller2/6dof PID/PID Controller1/preSat Signal/Forward_Path'
//  '<S65>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Anti-windup'
//  '<S66>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/D Gain'
//  '<S67>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/External Derivative'
//  '<S68>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Filter'
//  '<S69>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Filter ICs'
//  '<S70>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/I Gain'
//  '<S71>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Ideal P Gain'
//  '<S72>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Ideal P Gain Fdbk'
//  '<S73>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Integrator'
//  '<S74>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Integrator ICs'
//  '<S75>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/N Copy'
//  '<S76>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/N Gain'
//  '<S77>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/P Copy'
//  '<S78>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Parallel P Gain'
//  '<S79>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Reset Signal'
//  '<S80>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Saturation'
//  '<S81>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Saturation Fdbk'
//  '<S82>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Sum'
//  '<S83>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Sum Fdbk'
//  '<S84>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Tracking Mode'
//  '<S85>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Tracking Mode Sum'
//  '<S86>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Tsamp - Integral'
//  '<S87>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Tsamp - Ngain'
//  '<S88>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/postSat Signal'
//  '<S89>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/preInt Signal'
//  '<S90>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/preSat Signal'
//  '<S91>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Anti-windup/Disc. Clamping Parallel'
//  '<S92>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S93>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S94>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/D Gain/Internal Parameters'
//  '<S95>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/External Derivative/Error'
//  '<S96>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Filter/Disc. Forward Euler Filter'
//  '<S97>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Filter ICs/Internal IC - Filter'
//  '<S98>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/I Gain/Internal Parameters'
//  '<S99>'  : 'PID_Controller/Controller2/6dof PID/PID Controller2/Ideal P Gain/Passthrough'
//  '<S100>' : 'PID_Controller/Controller2/6dof PID/PID Controller2/Ideal P Gain Fdbk/Disabled'
//  '<S101>' : 'PID_Controller/Controller2/6dof PID/PID Controller2/Integrator/Discrete'
//  '<S102>' : 'PID_Controller/Controller2/6dof PID/PID Controller2/Integrator ICs/Internal IC'
//  '<S103>' : 'PID_Controller/Controller2/6dof PID/PID Controller2/N Copy/Disabled'
//  '<S104>' : 'PID_Controller/Controller2/6dof PID/PID Controller2/N Gain/Internal Parameters'
//  '<S105>' : 'PID_Controller/Controller2/6dof PID/PID Controller2/P Copy/Disabled'
//  '<S106>' : 'PID_Controller/Controller2/6dof PID/PID Controller2/Parallel P Gain/Internal Parameters'
//  '<S107>' : 'PID_Controller/Controller2/6dof PID/PID Controller2/Reset Signal/Disabled'
//  '<S108>' : 'PID_Controller/Controller2/6dof PID/PID Controller2/Saturation/Enabled'
//  '<S109>' : 'PID_Controller/Controller2/6dof PID/PID Controller2/Saturation Fdbk/Disabled'
//  '<S110>' : 'PID_Controller/Controller2/6dof PID/PID Controller2/Sum/Sum_PID'
//  '<S111>' : 'PID_Controller/Controller2/6dof PID/PID Controller2/Sum Fdbk/Disabled'
//  '<S112>' : 'PID_Controller/Controller2/6dof PID/PID Controller2/Tracking Mode/Disabled'
//  '<S113>' : 'PID_Controller/Controller2/6dof PID/PID Controller2/Tracking Mode Sum/Passthrough'
//  '<S114>' : 'PID_Controller/Controller2/6dof PID/PID Controller2/Tsamp - Integral/TsSignalSpecification'
//  '<S115>' : 'PID_Controller/Controller2/6dof PID/PID Controller2/Tsamp - Ngain/Passthrough'
//  '<S116>' : 'PID_Controller/Controller2/6dof PID/PID Controller2/postSat Signal/Forward_Path'
//  '<S117>' : 'PID_Controller/Controller2/6dof PID/PID Controller2/preInt Signal/Internal PreInt'
//  '<S118>' : 'PID_Controller/Controller2/6dof PID/PID Controller2/preSat Signal/Forward_Path'
//  '<S119>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Anti-windup'
//  '<S120>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/D Gain'
//  '<S121>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/External Derivative'
//  '<S122>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Filter'
//  '<S123>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Filter ICs'
//  '<S124>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/I Gain'
//  '<S125>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Ideal P Gain'
//  '<S126>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Ideal P Gain Fdbk'
//  '<S127>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Integrator'
//  '<S128>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Integrator ICs'
//  '<S129>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/N Copy'
//  '<S130>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/N Gain'
//  '<S131>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/P Copy'
//  '<S132>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Parallel P Gain'
//  '<S133>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Reset Signal'
//  '<S134>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Saturation'
//  '<S135>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Saturation Fdbk'
//  '<S136>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Sum'
//  '<S137>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Sum Fdbk'
//  '<S138>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Tracking Mode'
//  '<S139>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Tracking Mode Sum'
//  '<S140>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Tsamp - Integral'
//  '<S141>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Tsamp - Ngain'
//  '<S142>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/postSat Signal'
//  '<S143>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/preInt Signal'
//  '<S144>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/preSat Signal'
//  '<S145>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Anti-windup/Disc. Clamping Parallel'
//  '<S146>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S147>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S148>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/D Gain/Internal Parameters'
//  '<S149>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/External Derivative/Error'
//  '<S150>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Filter/Disc. Forward Euler Filter'
//  '<S151>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Filter ICs/Internal IC - Filter'
//  '<S152>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/I Gain/Internal Parameters'
//  '<S153>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Ideal P Gain/Passthrough'
//  '<S154>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Ideal P Gain Fdbk/Disabled'
//  '<S155>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Integrator/Discrete'
//  '<S156>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Integrator ICs/Internal IC'
//  '<S157>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/N Copy/Disabled'
//  '<S158>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/N Gain/Internal Parameters'
//  '<S159>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/P Copy/Disabled'
//  '<S160>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Parallel P Gain/Internal Parameters'
//  '<S161>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Reset Signal/Disabled'
//  '<S162>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Saturation/Enabled'
//  '<S163>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Saturation Fdbk/Disabled'
//  '<S164>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Sum/Sum_PID'
//  '<S165>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Sum Fdbk/Disabled'
//  '<S166>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Tracking Mode/Disabled'
//  '<S167>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Tracking Mode Sum/Passthrough'
//  '<S168>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Tsamp - Integral/TsSignalSpecification'
//  '<S169>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/Tsamp - Ngain/Passthrough'
//  '<S170>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/postSat Signal/Forward_Path'
//  '<S171>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/preInt Signal/Internal PreInt'
//  '<S172>' : 'PID_Controller/Controller2/6dof PID/PID Controller3/preSat Signal/Forward_Path'
//  '<S173>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Anti-windup'
//  '<S174>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/D Gain'
//  '<S175>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/External Derivative'
//  '<S176>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Filter'
//  '<S177>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Filter ICs'
//  '<S178>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/I Gain'
//  '<S179>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Ideal P Gain'
//  '<S180>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Ideal P Gain Fdbk'
//  '<S181>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Integrator'
//  '<S182>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Integrator ICs'
//  '<S183>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/N Copy'
//  '<S184>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/N Gain'
//  '<S185>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/P Copy'
//  '<S186>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Parallel P Gain'
//  '<S187>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Reset Signal'
//  '<S188>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Saturation'
//  '<S189>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Saturation Fdbk'
//  '<S190>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Sum'
//  '<S191>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Sum Fdbk'
//  '<S192>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Tracking Mode'
//  '<S193>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Tracking Mode Sum'
//  '<S194>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Tsamp - Integral'
//  '<S195>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Tsamp - Ngain'
//  '<S196>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/postSat Signal'
//  '<S197>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/preInt Signal'
//  '<S198>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/preSat Signal'
//  '<S199>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Anti-windup/Passthrough'
//  '<S200>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/D Gain/Internal Parameters'
//  '<S201>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/External Derivative/Error'
//  '<S202>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Filter/Disc. Forward Euler Filter'
//  '<S203>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Filter ICs/Internal IC - Filter'
//  '<S204>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/I Gain/Internal Parameters'
//  '<S205>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Ideal P Gain/Passthrough'
//  '<S206>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Ideal P Gain Fdbk/Disabled'
//  '<S207>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Integrator/Discrete'
//  '<S208>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Integrator ICs/Internal IC'
//  '<S209>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/N Copy/Disabled'
//  '<S210>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/N Gain/Internal Parameters'
//  '<S211>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/P Copy/Disabled'
//  '<S212>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Parallel P Gain/Internal Parameters'
//  '<S213>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Reset Signal/Disabled'
//  '<S214>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Saturation/Enabled'
//  '<S215>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Saturation Fdbk/Disabled'
//  '<S216>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Sum/Sum_PID'
//  '<S217>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Sum Fdbk/Disabled'
//  '<S218>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Tracking Mode/Disabled'
//  '<S219>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Tracking Mode Sum/Passthrough'
//  '<S220>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Tsamp - Integral/TsSignalSpecification'
//  '<S221>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/Tsamp - Ngain/Passthrough'
//  '<S222>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/postSat Signal/Forward_Path'
//  '<S223>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/preInt Signal/Internal PreInt'
//  '<S224>' : 'PID_Controller/Controller2/6dof PID/PID Controller4/preSat Signal/Forward_Path'

#endif                                 // PID_Controller_h_

//
// File trailer for generated code.
//
// [EOF]
//
