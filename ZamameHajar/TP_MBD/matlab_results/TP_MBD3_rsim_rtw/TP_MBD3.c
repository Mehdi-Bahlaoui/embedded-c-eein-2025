/*
 * TP_MBD3.c
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

#include "TP_MBD3.h"
#include <stdlib.h>
#include "rtwtypes.h"
#include <math.h>
#include <string.h>
#include "TP_MBD3_dt.h"

/* user code (top of parameter file) */
const int_T gblNumToFiles = 0;
const int_T gblNumFrFiles = 0;
const int_T gblNumFrWksBlocks = 0;
const char *gblSlvrJacPatternFileName = "TP_MBD3_rsim_rtw\\TP_MBD3_Jpattern.mat";

/* Root inports information  */
const int_T gblNumRootInportBlks = 1;
const int_T gblNumModelInputs = 1;
extern rtInportTUtable *gblInportTUtables;
extern const char *gblInportFileName;
const int_T gblInportDataTypeIdx[] = { 0 };

const int_T gblInportDims[] = { 1, 1 } ;

const int_T gblInportComplex[] = { 0 };

const int_T gblInportInterpoFlag[] = { 1 };

const int_T gblInportContinuous[] = { 0 };

#include "simstruc.h"
#include "fixedpoint.h"

/* Block signals (default storage) */
B rtB;

/* Block states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Parent Simstruct */
static SimStruct model_S;
SimStruct *const rtS = &model_S;

/* System initialize for root system: '<Root>' */
void MdlInitialize(void)
{
  /* InitializeConditions for Delay: '<Root>/Delay' */
  rtDW.Delay_DSTATE = 0.0;

  /* InitializeConditions for HitScheduler: '<Root>/Hit Scheduler' */
  rtDW.TNext = malloc((uint32_T)(256.0 * (real_T)sizeof(real_T)));
  rtDW.T0 = malloc((uint32_T)(256.0 * (real_T)sizeof(real_T)));
  rtDW.Head = 0U;
  rtDW.Tail = 0U;
  rtDW.Size = 0U;
  rtDW.BufferCapacity = 256U;
}

/* Enable for root system: '<Root>' */
void MdlEnable(void)
{
  /* Enable for HitScheduler: '<Root>/Hit Scheduler' */
  /* Force a sample hit at this major time step */
  _ssSetSampleHit(rtS, 2, 1);
  _ssSetTaskTime(rtS, 2, ssGetT(rtS));
  _ssSetVarNextHitTime(rtS, 0, ssGetT(rtS));
  ;
}

/* Start for root system: '<Root>' */
void MdlStart(void)
{
  MdlInitialize();
  MdlEnable();
}

/* Outputs for root system: '<Root>' */
void MdlOutputs(int_T tid)
{
  /* Read data from the mat file of inport block */
  if (gblInportFileName != (NULL)) {
    int_T currTimeIdx;
    int_T i;

    /*
     *  Read in data from mat file for root inport R
     */
    if (gblInportTUtables[0].nTimePoints > 0) {
      if (ssIsSampleHit(rtS, 0, 0)) {
        {
          real_T time = ssGetTaskTime(rtS,0);
          int k = 1;
          if (gblInportTUtables[0].nTimePoints == 1) {
            k = 0;
          }

          currTimeIdx = rt_getTimeIdx(gblInportTUtables[0].time, time,
            gblInportTUtables[0].nTimePoints,
            *(gblInportTUtables[0].currTimeIdx),
            1,
            0);
          (*gblInportTUtables[0].currTimeIdx) = currTimeIdx;
          for (i = 0; i < 1; i++) {
            real_T* realPtr1 = (real_T*)gblInportTUtables[0].ur +
              i*gblInportTUtables[0].nTimePoints +currTimeIdx;
            real_T* realPtr2 = realPtr1 + 1*k;
            (void)rt_Interpolate_Datatype(
              realPtr1,
              realPtr2,
              &rtU.R,
              time,
              gblInportTUtables[0].time[currTimeIdx],
              gblInportTUtables[0].time[currTimeIdx + k],
              gblInportTUtables[0].uDataType);
          }
        }
      }
    }
  }

  /* end read inport data from file */
  if (ssIsSampleHit(rtS, 1, 0)) {
    /* RelationalOperator: '<Root>/Relational Operator' incorporates:
     *  Constant: '<Root>/Cst'
     *  Delay: '<Root>/Delay'
     */
    rtB.RelationalOperator = (rtDW.Delay_DSTATE < 1.0);
  }

  /* HitScheduler: '<Root>/Hit Scheduler' */
  rtB.HitScheduler = ((!ssIsSampleHit(rtS, 0, 0)) && rtB.HitScheduler);

  /* HitScheduler: '<Root>/Hit Scheduler' */
  if (ssIsSampleHit(rtS, 2, 0)) {
    /* HitScheduler: '<Root>/Hit Scheduler' */
    rtB.HitScheduler = true;
    if (rtDW.Size == 0U) {
      _ssSetVarNextHitTime(rtS, 0, (rtMinusInf));
    } else {
      rtDW.Size--;
      rtDW.Head = (rtDW.Head + 1U) % rtDW.BufferCapacity;
      if (rtDW.Size == 0U) {
        _ssSetVarNextHitTime(rtS, 0, (rtMinusInf));
      } else {
        _ssSetVarNextHitTime(rtS, 0, *((real_T *)rtDW.TNext + rtDW.Head));
      }
    }
  }

  if (ssIsSampleHit(rtS, 0, 0)) {
    /* Switch: '<Root>/Switch' incorporates:
     *  Inport: '<Root>/R'
     */
    if (rtU.R != 0.0) {
      /* Switch: '<Root>/Switch' incorporates:
       *  Constant: '<Root>/Constant2'
       */
      rtB.Switch = 0.0;
    } else {
      /* Switch: '<Root>/Switch' */
      rtB.Switch = rtB.HitScheduler;
    }

    /* End of Switch: '<Root>/Switch' */

    /* Outport: '<Root>/Cnt' */
    rtY.Cnt = rtB.Switch;
  }

  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
void MdlUpdate(int_T tid)
{
  real_T *T0AtIdx;
  real_T *tNextTempAtEnd;
  int_T idx;
  void *tNextTempBuf;
  if (ssIsSampleHit(rtS, 1, 0)) {
    /* Update for Delay: '<Root>/Delay' */
    rtDW.Delay_DSTATE = rtB.Switch;
  }

  /* Update for HitScheduler: '<Root>/Hit Scheduler' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  if (rtB.RelationalOperator) {
    real_T minHmin;
    real_T minHmin_0;
    real_T t0Holder;
    real_T tNextHolder;
    int_T isunique;
    minHmin_0 = ssGetTaskTime(rtS,1);
    if (minHmin_0 == 0.0) {
      minHmin = 2.2250738585072014E-308;
    } else {
      minHmin = 3.5527136788005009E-15 * fabs(minHmin_0);
    }

    if (!(minHmin > 0.0)) {
      minHmin = 0.0;
    }

    if (!(minHmin > 1.0)) {
      minHmin = 1.0;
    }

    isunique = 1;
    tNextHolder = minHmin_0 + minHmin;
    t0Holder = minHmin_0;
    for (idx = (int_T)rtDW.Head; (int64_T)idx < rtDW.Head + rtDW.Size; idx++) {
      if (*(idx % (int_T)rtDW.BufferCapacity + (real_T *)rtDW.TNext) ==
          ssGetTaskTime(rtS,1) + minHmin) {
        isunique = 0;
      }
    }

    if (rtDW.Size == rtDW.BufferCapacity) {
      uint32_T distance;
      rtDW.BufferCapacity <<= 1;
      tNextTempBuf = malloc(rtDW.BufferCapacity * (uint32_T)sizeof(real_T));
      distance = rtDW.Size - rtDW.Head;
      tNextTempAtEnd = (real_T *)tNextTempBuf + distance;
      memcpy(tNextTempBuf, (real_T *)rtDW.TNext + rtDW.Head, (rtDW.Size -
              rtDW.Head) * (uint32_T)sizeof(real_T));
      memcpy(tNextTempAtEnd, rtDW.TNext, rtDW.Head * (uint32_T)sizeof(real_T));
      free(rtDW.TNext);
      rtDW.TNext = tNextTempBuf;
      tNextTempBuf = malloc(rtDW.BufferCapacity * (uint32_T)sizeof(real_T));
      tNextTempAtEnd = (real_T *)tNextTempBuf + distance;
      memcpy(tNextTempBuf, (real_T *)rtDW.T0 + rtDW.Head, (rtDW.Size - rtDW.Head)
             * (uint32_T)sizeof(real_T));
      memcpy(tNextTempAtEnd, rtDW.T0, rtDW.Head * (uint32_T)sizeof(real_T));
      free(rtDW.T0);
      rtDW.T0 = tNextTempBuf;
      rtDW.Head = 0U;
      rtDW.Tail = rtDW.Size;
    }

    if (isunique == 1) {
      minHmin += ssGetTaskTime(rtS,1);
      if ((minHmin > *((rtDW.Tail - 1U) % rtDW.BufferCapacity + (real_T *)
                       rtDW.TNext)) || (rtDW.Size == 0U)) {
        *((real_T *)rtDW.TNext + rtDW.Tail) = minHmin;
        *((real_T *)rtDW.T0 + rtDW.Tail) = minHmin_0;
      } else {
        for (idx = (int_T)rtDW.Head; (int64_T)idx < rtDW.Head + rtDW.Size; idx++)
        {
          isunique = idx % (int_T)rtDW.BufferCapacity;
          tNextTempAtEnd = isunique + (real_T *)rtDW.TNext;
          T0AtIdx = isunique + (real_T *)rtDW.T0;
          if (minHmin_0 + 1.0 < *tNextTempAtEnd) {
            minHmin = *tNextTempAtEnd;
            *tNextTempAtEnd = tNextHolder;
            tNextHolder = minHmin;
            minHmin = *T0AtIdx;
            *T0AtIdx = t0Holder;
            t0Holder = minHmin;
          }
        }
      }

      _ssSetVarNextHitTime(rtS, 0, *((real_T *)rtDW.TNext + rtDW.Head));
      rtDW.Tail = (rtDW.Tail + 1U) % rtDW.BufferCapacity;
      rtDW.Size++;
    }
  }

  /* End of Update for HitScheduler: '<Root>/Hit Scheduler' */
  UNUSED_PARAMETER(tid);
}

/* Termination for root system: '<Root>' */
void MdlTerminate(void)
{
  /* Terminate for HitScheduler: '<Root>/Hit Scheduler' */
  free(rtDW.TNext);
  free(rtDW.T0);
}

/* Function to initialize sizes */
void MdlInitializeSizes(void)
{
  ssSetNumContStates(rtS, 0);          /* Number of continuous states */
  ssSetNumY(rtS, 1);                   /* Number of model outputs */
  ssSetNumU(rtS, 1);                   /* Number of model inputs */
  ssSetDirectFeedThrough(rtS, 1);      /* The model is direct feedthrough */
  ssSetNumSampleTimes(rtS, 3);         /* Number of sample times */
  ssSetNumBlocks(rtS, 8);              /* Number of blocks */
  ssSetNumBlockIO(rtS, 3);             /* Number of block outputs */
}

/* Function to initialize sample times. */
void MdlInitializeSampleTimes(void)
{
  /* task periods */
  ssSetSampleTime(rtS, 0, 0.0);
  ssSetSampleTime(rtS, 1, 0.2);
  ssSetSampleTime(rtS, 2, -2.0);

  /* task offsets */
  ssSetOffsetTime(rtS, 0, 1.0);
  ssSetOffsetTime(rtS, 1, 0.0);
  ssSetOffsetTime(rtS, 2, 0.0);
}

/* Function to register the model */
/* Turns off all optimizations on Windows because of issues with VC 2015 compiler.
   This function is not performance-critical, hence this is not a problem.
 */
#if defined(_MSC_VER)

#pragma optimize( "", off )

#endif

SimStruct * TP_MBD3(void)
{
  static struct _ssMdlInfo mdlInfo;
  static struct _ssBlkInfo2 blkInfo2;
  static struct _ssBlkInfoSLSize blkInfoSLSize;
  (void) memset((char *)rtS, 0,
                sizeof(SimStruct));
  (void) memset((char *)&mdlInfo, 0,
                sizeof(struct _ssMdlInfo));
  (void) memset((char *)&blkInfo2, 0,
                sizeof(struct _ssBlkInfo2));
  (void) memset((char *)&blkInfoSLSize, 0,
                sizeof(struct _ssBlkInfoSLSize));
  ssSetBlkInfo2Ptr(rtS, &blkInfo2);
  ssSetBlkInfoSLSizePtr(rtS, &blkInfoSLSize);
  ssSetMdlInfoPtr(rtS, &mdlInfo);

  /* timing info */
  {
    static time_T mdlPeriod[NSAMPLE_TIMES];
    static time_T mdlOffset[NSAMPLE_TIMES];
    static time_T mdlTaskTimes[NSAMPLE_TIMES];
    static int_T mdlTsMap[NSAMPLE_TIMES];
    static int_T mdlSampleHits[NSAMPLE_TIMES];
    static boolean_T mdlTNextWasAdjustedPtr[NSAMPLE_TIMES];
    static int_T mdlPerTaskSampleHits[NSAMPLE_TIMES * NSAMPLE_TIMES];
    static time_T mdlTimeOfNextSampleHit[NSAMPLE_TIMES];

    {
      int_T i;
      for (i = 0; i < NSAMPLE_TIMES; i++) {
        mdlPeriod[i] = 0.0;
        mdlOffset[i] = 0.0;
        mdlTaskTimes[i] = 0.0;
        mdlTsMap[i] = i;
        mdlSampleHits[i] = 1;
      }
    }

    ssSetSampleTimePtr(rtS, &mdlPeriod[0]);
    ssSetOffsetTimePtr(rtS, &mdlOffset[0]);
    ssSetSampleTimeTaskIDPtr(rtS, &mdlTsMap[0]);
    ssSetTPtr(rtS, &mdlTaskTimes[0]);
    ssSetSampleHitPtr(rtS, &mdlSampleHits[0]);
    ssSetTNextWasAdjustedPtr(rtS, &mdlTNextWasAdjustedPtr[0]);
    ssSetPerTaskSampleHitsPtr(rtS, &mdlPerTaskSampleHits[0]);
    ssSetTimeOfNextSampleHitPtr(rtS, &mdlTimeOfNextSampleHit[0]);
  }

  ssSetSolverMode(rtS, SOLVER_MODE_SINGLETASKING);

  /*
   * initialize model vectors and cache them in SimStruct
   */

  /* block I/O */
  {
    ssSetBlockIO(rtS, ((void *) &rtB));
    (void) memset(((void *) &rtB), 0,
                  sizeof(B));
  }

  /* external inputs */
  {
    ssSetU(rtS, ((void*) &rtU));
    rtU.R = 0.0;
  }

  /* external outputs */
  {
    ssSetY(rtS, &rtY);
    rtY.Cnt = 0.0;
  }

  /* states (dwork) */
  {
    void *dwork = (void *) &rtDW;
    ssSetRootDWork(rtS, dwork);
    (void) memset(dwork, 0,
                  sizeof(DW));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    ssSetModelMappingInfo(rtS, &dtInfo);
    dtInfo.numDataTypes = 23;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;
  }

  /* Model specific registration */
  ssSetRootSS(rtS, rtS);
  ssSetVersion(rtS, SIMSTRUCT_VERSION_LEVEL2);
  ssSetModelName(rtS, "TP_MBD3");
  ssSetPath(rtS, "TP_MBD3");
  ssSetTStart(rtS, 0.0);
  ssSetTFinal(rtS, 10.0);

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    ssSetRTWLogInfo(rtS, &rt_DataLoggingInfo);
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ssGetRTWLogInfo(rtS), (NULL));
    rtliSetLogXSignalPtrs(ssGetRTWLogInfo(rtS), (NULL));
    rtliSetLogT(ssGetRTWLogInfo(rtS), "tout");
    rtliSetLogX(ssGetRTWLogInfo(rtS), "");
    rtliSetLogXFinal(ssGetRTWLogInfo(rtS), "");
    rtliSetLogVarNameModifier(ssGetRTWLogInfo(rtS), "rt_");
    rtliSetLogFormat(ssGetRTWLogInfo(rtS), 4);
    rtliSetLogMaxRows(ssGetRTWLogInfo(rtS), 0);
    rtliSetLogDecimation(ssGetRTWLogInfo(rtS), 1);
    rtliSetLogY(ssGetRTWLogInfo(rtS), "");
    rtliSetLogYSignalInfo(ssGetRTWLogInfo(rtS), (NULL));
    rtliSetLogYSignalPtrs(ssGetRTWLogInfo(rtS), (NULL));
  }

  {
    static ssSolverInfo slvrInfo;
    ssSetStepSize(rtS, 0.2);
    ssSetMinStepSize(rtS, 0.0);
    ssSetMaxNumMinSteps(rtS, -1);
    ssSetMinStepViolatedError(rtS, 0);
    ssSetMaxStepSize(rtS, 0.2);
    ssSetSolverMaxOrder(rtS, -1);
    ssSetSolverRefineFactor(rtS, 1);
    ssSetOutputTimes(rtS, (NULL));
    ssSetNumOutputTimes(rtS, 0);
    ssSetOutputTimesOnly(rtS, 0);
    ssSetOutputTimesIndex(rtS, 0);
    ssSetZCCacheNeedsReset(rtS, 0);
    ssSetDerivCacheNeedsReset(rtS, 0);
    ssSetNumNonContDerivSigInfos(rtS, 0);
    ssSetNonContDerivSigInfos(rtS, (NULL));
    ssSetSolverInfo(rtS, &slvrInfo);
    ssSetSolverName(rtS, "VariableStepDiscrete");
    ssSetVariableStepSolver(rtS, 1);
    ssSetSolverConsistencyChecking(rtS, 0);
    ssSetSolverAdaptiveZcDetection(rtS, 0);
    ssSetSolverRobustResetMethod(rtS, 0);
    ssSetSolverStateProjection(rtS, 0);
    ssSetSolverMassMatrixType(rtS, (ssMatrixType)0);
    ssSetSolverMassMatrixNzMax(rtS, 0);
    ssSetModelOutputs(rtS, MdlOutputs);
    ssSetModelLogData(rtS, rt_UpdateTXYLogVars);
    ssSetModelLogDataIfInInterval(rtS, rt_UpdateTXXFYLogVars);
    ssSetModelUpdate(rtS, MdlUpdate);
    ssSetTNextTid(rtS, INT_MIN);
    ssSetTNext(rtS, rtMinusInf);
    ssSetSolverNeedsReset(rtS);
    ssSetNumNonsampledZCs(rtS, 0);
  }

  ssSetChecksumVal(rtS, 0, 1872807410U);
  ssSetChecksumVal(rtS, 1, 2709446505U);
  ssSetChecksumVal(rtS, 2, 3365242439U);
  ssSetChecksumVal(rtS, 3, 3025438433U);
  return rtS;
}

/* When you use the on parameter, it resets the optimizations to those that you
   specified with the /O compiler option. */
#if defined(_MSC_VER)

#pragma optimize( "", on )

#endif
