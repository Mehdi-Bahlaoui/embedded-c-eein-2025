/*
 * TP_MBD3.h
 *
 * Code generation for model "TP_MBD3".
 *
 * Model version              : 1.8
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Thu Oct 30 23:38:14 2025
 *
 * Target selection: rsim.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TP_MBD3_h_
#define RTW_HEADER_TP_MBD3_h_
#ifndef TP_MBD3_COMMON_INCLUDES_
#define TP_MBD3_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rsim.h"
#include "rt_logging.h"
#include "dt_info.h"
#endif                                 /* TP_MBD3_COMMON_INCLUDES_ */

#include "TP_MBD3_types.h"
#include <stddef.h>
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include <string.h>
#define MODEL_NAME                     TP_MBD3
#define NSAMPLE_TIMES                  (3)                       /* Number of sample times */
#define NINPUTS                        (1)                       /* Number of model inputs */
#define NOUTPUTS                       (1)                       /* Number of model outputs */
#define NBLOCKIO                       (3)                       /* Number of data output port signals */
#define NUM_ZC_EVENTS                  (0)                       /* Number of zero-crossing events */
#ifndef NCSTATES
#define NCSTATES                       (0)                       /* Number of continuous states */
#elif NCSTATES != 0
# error Invalid specification of NCSTATES defined in compiler command
#endif

#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm)         (NULL)
#endif

#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Switch;                       /* '<Root>/Switch' */
  boolean_T RelationalOperator;        /* '<Root>/Relational Operator' */
  boolean_T HitScheduler;              /* '<Root>/Hit Scheduler' */
} B;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE;                 /* '<Root>/Delay' */
  void* TNext;                         /* '<Root>/Hit Scheduler' */
  void* T0;                            /* '<Root>/Hit Scheduler' */
  uint32_T Head;                       /* '<Root>/Hit Scheduler' */
  uint32_T Tail;                       /* '<Root>/Hit Scheduler' */
  uint32_T Size;                       /* '<Root>/Hit Scheduler' */
  uint32_T BufferCapacity;             /* '<Root>/Hit Scheduler' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T R;                            /* '<Root>/R' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Cnt;                          /* '<Root>/Cnt' */
} ExtY;

/* External data declarations for dependent source files */
extern const char *RT_MEMORY_ALLOCATION_ERROR;
extern B rtB;                          /* block i/o */
extern DW rtDW;                        /* states (dwork) */
extern ExtU rtU;                       /* external inputs */
extern ExtY rtY;                       /* external outputs */

/* Simulation Structure */
extern SimStruct *const rtS;

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
 * '<Root>' : 'TP_MBD3'
 */

/* user code (bottom of header file) */
extern const int_T gblNumToFiles;
extern const int_T gblNumFrFiles;
extern const int_T gblNumFrWksBlocks;
extern rtInportTUtable *gblInportTUtables;
extern const char *gblInportFileName;
extern const int_T gblNumRootInportBlks;
extern const int_T gblNumModelInputs;
extern const int_T gblInportDataTypeIdx[];
extern const int_T gblInportDims[];
extern const int_T gblInportComplex[];
extern const int_T gblInportInterpoFlag[];
extern const int_T gblInportContinuous[];

#endif                                 /* RTW_HEADER_TP_MBD3_h_ */
