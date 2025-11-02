/*
 * File: TP_MBD.c
 *
 * Code generated for Simulink model 'TP_MBD'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Oct 30 20:41:28 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "TP_MBD.h"

/* External inputs (root inport signals with default storage) */
ExtU_TP_MBD_T TP_MBD_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_TP_MBD_T TP_MBD_Y;

/* Real-time model */
static RT_MODEL_TP_MBD_T TP_MBD_M_;
RT_MODEL_TP_MBD_T *const TP_MBD_M = &TP_MBD_M_;

/* Model step function */
void TP_MBD_step(void)
{
  /* Outport: '<Root>/Out1' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In2'
   *  Inport: '<Root>/In3'
   *  Product: '<Root>/Product1'
   *  Product: '<Root>/Product2'
   *  Sum: '<Root>/Add'
   */
  TP_MBD_Y.Out1 = (TP_MBD_U.In2 * 2.0 + TP_MBD_U.In1) + TP_MBD_U.In3 * 4.0;
}

/* Model initialize function */
void TP_MBD_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void TP_MBD_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
