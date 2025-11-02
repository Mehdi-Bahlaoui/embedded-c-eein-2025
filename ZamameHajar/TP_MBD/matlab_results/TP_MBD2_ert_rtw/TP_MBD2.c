/*
 * File: TP_MBD2.c
 *
 * Code generated for Simulink model 'TP_MBD2'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Oct 30 22:20:09 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "TP_MBD2.h"
#include "rtwtypes.h"

/* External inputs (root inport signals with default storage) */
ExtU_TP_MBD2_T TP_MBD2_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_TP_MBD2_T TP_MBD2_Y;

/* Real-time model */
static RT_MODEL_TP_MBD2_T TP_MBD2_M_;
RT_MODEL_TP_MBD2_T *const TP_MBD2_M = &TP_MBD2_M_;

/* Model step function */
void TP_MBD2_step(void)
{
  boolean_T rtb_RelationalOperator;

  /* Sum: '<Root>/Sum' incorporates:
   *  Delay: '<Root>/Delay'
   *  Inport: '<Root>/input'
   */
  TP_MBD2_Y.output += TP_MBD2_U.input;

  /* RelationalOperator: '<Root>/Relational Operator' incorporates:
   *  Inport: '<Root>/lower'
   */
  rtb_RelationalOperator = (TP_MBD2_Y.output >= TP_MBD2_U.lower);

  /* Switch: '<Root>/Switch' incorporates:
   *  Inport: '<Root>/upper'
   *  Logic: '<Root>/Logical Operator'
   *  RelationalOperator: '<Root>/Relational Operator1'
   */
  if ((!(TP_MBD2_U.upper >= TP_MBD2_Y.output)) || (!rtb_RelationalOperator)) {
    /* Switch: '<Root>/limit' */
    if (rtb_RelationalOperator) {
      /* Sum: '<Root>/Sum' */
      TP_MBD2_Y.output = TP_MBD2_U.upper;
    } else {
      /* Sum: '<Root>/Sum' incorporates:
       *  Inport: '<Root>/lower'
       */
      TP_MBD2_Y.output = TP_MBD2_U.lower;
    }

    /* End of Switch: '<Root>/limit' */
  }

  /* End of Switch: '<Root>/Switch' */
}

/* Model initialize function */
void TP_MBD2_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void TP_MBD2_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
