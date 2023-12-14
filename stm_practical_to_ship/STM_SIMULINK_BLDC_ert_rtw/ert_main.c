/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'STM_SIMULINK_BLDC'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Dec 14 16:52:02 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "STM_SIMULINK_BLDC.h"
#include "rtwtypes.h"

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

  __enable_irq();
  STM_SIMULINK_BLDC_step();

  /* Get model outputs here */
  __disable_irq();
  OverrunFlag--;
}

volatile boolean_T stopRequested;
volatile boolean_T runModel;
int main(void)
{
  float modelBaseRate = 0.001;
  float systemClock = 72;

  /* Initialize variables */
  stopRequested = false;
  runModel = false;

#if defined(MW_MULTI_TASKING_MODE) && (MW_MULTI_TASKING_MODE == 1)

  MW_ASM (" SVC #1");

#endif

  ;
  (void)systemClock;
  HAL_Init();
  SystemCoreClockUpdate();
  rtmSetErrorStatus(STM_SIMULINK_BLDC_M, 0);
  STM_SIMULINK_BLDC_initialize();
  ARMCM_SysTick_Config(modelBaseRate);
  runModel = rtmGetErrorStatus(STM_SIMULINK_BLDC_M) == (NULL);
  __enable_irq();
  while (runModel) {
    stopRequested = !(rtmGetErrorStatus(STM_SIMULINK_BLDC_M) == (NULL));
    runModel = !(stopRequested);
  }

  /* Terminate model */
  STM_SIMULINK_BLDC_terminate();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
