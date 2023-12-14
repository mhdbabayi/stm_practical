/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: STM_SIMULINK_BLDC.h
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

#ifndef RTW_HEADER_STM_SIMULINK_BLDC_h_
#define RTW_HEADER_STM_SIMULINK_BLDC_h_
#ifndef STM_SIMULINK_BLDC_COMMON_INCLUDES_
#define STM_SIMULINK_BLDC_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* STM_SIMULINK_BLDC_COMMON_INCLUDES_ */

#include "STM_SIMULINK_BLDC_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real32_T Add1;                       /* '<S26>/Add1' */
  real32_T Input;                      /* '<S27>/Input' */
  boolean_T UnitDelay;                 /* '<S4>/Unit Delay' */
} B_STM_SIMULINK_BLDC_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T RampGenerator_DSTATE;       /* '<S13>/Ramp Generator' */
  boolean_T Delay_DSTATE;              /* '<S26>/Delay' */
  boolean_T UnitDelay_DSTATE_e;        /* '<S3>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_n;        /* '<S4>/Unit Delay' */
  int8_T RampGenerator_PrevResetState; /* '<S13>/Ramp Generator' */
  boolean_T Accumulate_MODE;           /* '<S15>/Accumulate' */
} DW_STM_SIMULINK_BLDC_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  boolean_T push_button;               /* '<Root>/push_button' */
  uint16_T speed;                      /* '<Root>/speed' */
  uint16_T Phase_A;                    /* '<Root>/Phase_A' */
  uint16_T Phase_B;                    /* '<Root>/Phase_B' */
  uint16_T Phase_C;                    /* '<Root>/Phase_C' */
  uint16_T BusV;                       /* '<Root>/BusV' */
} ExtU_STM_SIMULINK_BLDC_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  boolean_T enable_out;                /* '<Root>/enable_out' */
  uint32_T pwm_1;                      /* '<Root>/pwm_1' */
  uint32_T pwm_2;                      /* '<Root>/pwm_2' */
  uint32_T pwm_3;                      /* '<Root>/pwm_3' */
} ExtY_STM_SIMULINK_BLDC_T;

/* Parameters (default storage) */
struct P_STM_SIMULINK_BLDC_T_ {
  real32_T Ts;                         /* Variable: Ts
                                        * Referenced by: '<S13>/Sample_Time'
                                        */
  real32_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S7>/Constant'
                                        */
  real32_T sqrt3_by_two_Gain;          /* Computed Parameter: sqrt3_by_two_Gain
                                        * Referenced by: '<S17>/sqrt3_by_two'
                                        */
  real32_T one_by_two_Gain;            /* Computed Parameter: one_by_two_Gain
                                        * Referenced by: '<S17>/one_by_two'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S7>/Gain'
                                        */
  real32_T Constant1_Value;            /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S7>/Constant1'
                                        */
  real32_T stop_Value;                 /* Computed Parameter: stop_Value
                                        * Referenced by: '<S10>/stop'
                                        */
  real32_T Out1_Y0;                    /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S27>/Out1'
                                        */
  real32_T theta_e_Y0;                 /* Computed Parameter: theta_e_Y0
                                        * Referenced by: '<S26>/theta_e'
                                        */
  real32_T Constant_Value_l;           /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S23>/Constant'
                                        */
  real32_T sine_table_values_Value[1002];
                                  /* Computed Parameter: sine_table_values_Value
                                   * Referenced by: '<S19>/sine_table_values'
                                   */
  real32_T RampGenerator_gainval;   /* Computed Parameter: RampGenerator_gainval
                                     * Referenced by: '<S13>/Ramp Generator'
                                     */
  real32_T RampGenerator_IC;           /* Computed Parameter: RampGenerator_IC
                                        * Referenced by: '<S13>/Ramp Generator'
                                        */
  real32_T RampGenerator_UpperSat; /* Computed Parameter: RampGenerator_UpperSat
                                    * Referenced by: '<S13>/Ramp Generator'
                                    */
  real32_T RampGenerator_LowerSat; /* Computed Parameter: RampGenerator_LowerSat
                                    * Referenced by: '<S13>/Ramp Generator'
                                    */
  real32_T position_increment_Gain;
                                  /* Computed Parameter: position_increment_Gain
                                   * Referenced by: '<S12>/position_increment'
                                   */
  real32_T scaleIn_Gain;               /* Computed Parameter: scaleIn_Gain
                                        * Referenced by: '<S15>/scaleIn'
                                        */
  real32_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S15>/Unit Delay'
                                */
  real32_T scaleOut_Gain;              /* Computed Parameter: scaleOut_Gain
                                        * Referenced by: '<S15>/scaleOut'
                                        */
  real32_T convert_pu_Gain;            /* Computed Parameter: convert_pu_Gain
                                        * Referenced by: '<S22>/convert_pu'
                                        */
  real32_T indexing_Gain;              /* Computed Parameter: indexing_Gain
                                        * Referenced by: '<S19>/indexing'
                                        */
  real32_T Constant_Value_i;           /* Computed Parameter: Constant_Value_i
                                        * Referenced by: '<S14>/Constant'
                                        */
  real32_T Vbyf_Gain;                  /* Computed Parameter: Vbyf_Gain
                                        * Referenced by: '<S12>/V-by-f'
                                        */
  real32_T Correction_Factor_sinePWM_Gain;
                           /* Computed Parameter: Correction_Factor_sinePWM_Gain
                            * Referenced by: '<S12>/Correction_Factor_sinePWM'
                            */
  real32_T BoostVoltage_Value;         /* Computed Parameter: BoostVoltage_Value
                                        * Referenced by: '<S2>/Boost Voltage'
                                        */
  real32_T Saturation_UpperSat;       /* Computed Parameter: Saturation_UpperSat
                                       * Referenced by: '<S16>/Saturation'
                                       */
  real32_T Saturation_LowerSat;       /* Computed Parameter: Saturation_LowerSat
                                       * Referenced by: '<S16>/Saturation'
                                       */
  real32_T One_Value;                  /* Computed Parameter: One_Value
                                        * Referenced by: '<S13>/One'
                                        */
  real32_T Ramp_Timesec_Value;         /* Computed Parameter: Ramp_Timesec_Value
                                        * Referenced by: '<S11>/Ramp_Time (sec)'
                                        */
  uint32_T rpm2freq_Gain;              /* Computed Parameter: rpm2freq_Gain
                                        * Referenced by: '<S11>/rpm2freq'
                                        */
  int16_T offset_Value[4];             /* Computed Parameter: offset_Value
                                        * Referenced by: '<S19>/offset'
                                        */
  uint16_T Gain_Gain_d;                /* Computed Parameter: Gain_Gain_d
                                        * Referenced by: '<Root>/Gain'
                                        */
  uint16_T Offset_Value;               /* Computed Parameter: Offset_Value
                                        * Referenced by: '<S20>/Offset'
                                        */
  uint16_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S20>/Switch'
                                        */
  uint16_T Saturation_UpperSat_h;   /* Computed Parameter: Saturation_UpperSat_h
                                     * Referenced by: '<Root>/Saturation'
                                     */
  uint16_T Saturation_LowerSat_e;   /* Computed Parameter: Saturation_LowerSat_e
                                     * Referenced by: '<Root>/Saturation'
                                     */
  uint16_T Constant1_Value_b;          /* Computed Parameter: Constant1_Value_b
                                        * Referenced by: '<S9>/Constant1'
                                        */
  uint16_T Switch_Threshold_n;         /* Computed Parameter: Switch_Threshold_n
                                        * Referenced by: '<S9>/Switch'
                                        */
  boolean_T Out1_Y0_g;                 /* Computed Parameter: Out1_Y0_g
                                        * Referenced by: '<S4>/Out1'
                                        */
  boolean_T UnitDelay_InitialCondition_n;/* Expression: true
                                          * Referenced by: '<S4>/Unit Delay'
                                          */
  boolean_T UnitDelay_InitialCondition_m;/* Expression: false
                                          * Referenced by: '<S3>/Unit Delay'
                                          */
  boolean_T Delay_InitialCondition;/* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<S26>/Delay'
                                    */
  boolean_T Constant_Value_lk;         /* Computed Parameter: Constant_Value_lk
                                        * Referenced by: '<S26>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_STM_SIMULINK_BLDC_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_STM_SIMULINK_BLDC_T STM_SIMULINK_BLDC_P;

/* Block signals (default storage) */
extern B_STM_SIMULINK_BLDC_T STM_SIMULINK_BLDC_B;

/* Block states (default storage) */
extern DW_STM_SIMULINK_BLDC_T STM_SIMULINK_BLDC_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_STM_SIMULINK_BLDC_T STM_SIMULINK_BLDC_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_STM_SIMULINK_BLDC_T STM_SIMULINK_BLDC_Y;

/* Model entry point functions */
extern void STM_SIMULINK_BLDC_initialize(void);
extern void STM_SIMULINK_BLDC_step(void);
extern void STM_SIMULINK_BLDC_terminate(void);

/* Real-time Model object */
extern RT_MODEL_STM_SIMULINK_BLDC_T *const STM_SIMULINK_BLDC_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Scope' : Unused code path elimination
 * Block '<S3>/Constant' : Unused code path elimination
 * Block '<S3>/Scope' : Unused code path elimination
 * Block '<S10>/Scope' : Unused code path elimination
 * Block '<S6>/Constant' : Unused code path elimination
 * Block '<S6>/Scope' : Unused code path elimination
 * Block '<S13>/Scope' : Unused code path elimination
 * Block '<S14>/Data Type Duplicate' : Unused code path elimination
 * Block '<S17>/Data Type Duplicate' : Unused code path elimination
 * Block '<S18>/Data Type Duplicate' : Unused code path elimination
 * Block '<S19>/Data Type Duplicate' : Unused code path elimination
 * Block '<S19>/Data Type Propagation' : Unused code path elimination
 * Block '<S24>/Data Type Duplicate' : Unused code path elimination
 * Block '<S25>/Data Type Duplicate' : Unused code path elimination
 * Block '<S26>/Data Type Duplicate' : Unused code path elimination
 * Block '<S15>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S7>/Scope' : Unused code path elimination
 * Block '<S8>/Gain' : Unused code path elimination
 * Block '<S8>/Multiply' : Unused code path elimination
 * Block '<S8>/Product' : Unused code path elimination
 * Block '<S8>/Scope' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<S19>/Get_FractionVal' : Eliminate redundant data type conversion
 * Block '<S15>/Data Type Conversion' : Eliminate redundant data type conversion
 */

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
 * '<Root>' : 'STM_SIMULINK_BLDC'
 * '<S1>'   : 'STM_SIMULINK_BLDC/Communication'
 * '<S2>'   : 'STM_SIMULINK_BLDC/Open Loop Control'
 * '<S3>'   : 'STM_SIMULINK_BLDC/Communication/Start and Stop Motor'
 * '<S4>'   : 'STM_SIMULINK_BLDC/Communication/Start and Stop Motor/Enabled Subsystem'
 * '<S5>'   : 'STM_SIMULINK_BLDC/Open Loop Control/Codegen'
 * '<S6>'   : 'STM_SIMULINK_BLDC/Open Loop Control/Control_System'
 * '<S7>'   : 'STM_SIMULINK_BLDC/Open Loop Control/Output Scaling'
 * '<S8>'   : 'STM_SIMULINK_BLDC/Open Loop Control/Sim'
 * '<S9>'   : 'STM_SIMULINK_BLDC/Open Loop Control/Codegen/Hardware Initialization'
 * '<S10>'  : 'STM_SIMULINK_BLDC/Open Loop Control/Codegen/PWM Output'
 * '<S11>'  : 'STM_SIMULINK_BLDC/Open Loop Control/Control_System/SpeedRefToFreq'
 * '<S12>'  : 'STM_SIMULINK_BLDC/Open Loop Control/Control_System/VabcCalc'
 * '<S13>'  : 'STM_SIMULINK_BLDC/Open Loop Control/Control_System/SpeedRefToFreq/Ramp Generator'
 * '<S14>'  : 'STM_SIMULINK_BLDC/Open Loop Control/Control_System/VabcCalc/3-Phase Sine Voltage Generator'
 * '<S15>'  : 'STM_SIMULINK_BLDC/Open Loop Control/Control_System/VabcCalc/Position Generator'
 * '<S16>'  : 'STM_SIMULINK_BLDC/Open Loop Control/Control_System/VabcCalc/Saturate output to limits'
 * '<S17>'  : 'STM_SIMULINK_BLDC/Open Loop Control/Control_System/VabcCalc/3-Phase Sine Voltage Generator/Inverse Clarke Transform'
 * '<S18>'  : 'STM_SIMULINK_BLDC/Open Loop Control/Control_System/VabcCalc/3-Phase Sine Voltage Generator/Inverse Park Transform'
 * '<S19>'  : 'STM_SIMULINK_BLDC/Open Loop Control/Control_System/VabcCalc/3-Phase Sine Voltage Generator/Sine-Cosine Lookup'
 * '<S20>'  : 'STM_SIMULINK_BLDC/Open Loop Control/Control_System/VabcCalc/3-Phase Sine Voltage Generator/Inverse Park Transform/Switch_Axis'
 * '<S21>'  : 'STM_SIMULINK_BLDC/Open Loop Control/Control_System/VabcCalc/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/Interpolation'
 * '<S22>'  : 'STM_SIMULINK_BLDC/Open Loop Control/Control_System/VabcCalc/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/WrapUp'
 * '<S23>'  : 'STM_SIMULINK_BLDC/Open Loop Control/Control_System/VabcCalc/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S24>'  : 'STM_SIMULINK_BLDC/Open Loop Control/Control_System/VabcCalc/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S25>'  : 'STM_SIMULINK_BLDC/Open Loop Control/Control_System/VabcCalc/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S26>'  : 'STM_SIMULINK_BLDC/Open Loop Control/Control_System/VabcCalc/Position Generator/Accumulate'
 * '<S27>'  : 'STM_SIMULINK_BLDC/Open Loop Control/Control_System/VabcCalc/Position Generator/Accumulate/Subsystem'
 */
#endif                                 /* RTW_HEADER_STM_SIMULINK_BLDC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
