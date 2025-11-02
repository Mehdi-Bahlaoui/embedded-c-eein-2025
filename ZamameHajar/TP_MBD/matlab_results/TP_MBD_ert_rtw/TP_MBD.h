/*
 * File: TP_MBD.h
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

#ifndef RTW_HEADER_TP_MBD_h_
#define RTW_HEADER_TP_MBD_h_
#ifndef TP_MBD_COMMON_INCLUDES_
#define TP_MBD_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* TP_MBD_COMMON_INCLUDES_ */

#include "TP_MBD_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T In1;                          /* '<Root>/In1' */
  real_T In2;                          /* '<Root>/In2' */
  real_T In3;                          /* '<Root>/In3' */
} ExtU_TP_MBD_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
} ExtY_TP_MBD_T;

/* Real-time Model Data Structure */
struct tag_RTM_TP_MBD_T {
  const char_T * volatile errorStatus;
};

/* External inputs (root inport signals with default storage) */
extern ExtU_TP_MBD_T TP_MBD_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_TP_MBD_T TP_MBD_Y;

/* Model entry point functions */
extern void TP_MBD_initialize(void);
extern void TP_MBD_step(void);
extern void TP_MBD_terminate(void);

/* Real-time Model object */
extern RT_MODEL_TP_MBD_T *const TP_MBD_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'TP_MBD'
 */
#endif                                 /* RTW_HEADER_TP_MBD_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
