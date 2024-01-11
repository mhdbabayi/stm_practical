/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: STM_SIMULINK_BLDC.c
 *
 * Code generated for Simulink model 'STM_SIMULINK_BLDC'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Jan  9 11:25:46 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "STM_SIMULINK_BLDC.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "STM_SIMULINK_BLDC_private.h"

/* Block signals (default storage) */
B_STM_SIMULINK_BLDC_T STM_SIMULINK_BLDC_B;

/* Block states (default storage) */
DW_STM_SIMULINK_BLDC_T STM_SIMULINK_BLDC_DW;

/* External inputs (root inport signals with default storage) */
ExtU_STM_SIMULINK_BLDC_T STM_SIMULINK_BLDC_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_STM_SIMULINK_BLDC_T STM_SIMULINK_BLDC_Y;

/* Real-time model */
static RT_MODEL_STM_SIMULINK_BLDC_T STM_SIMULINK_BLDC_M_;
RT_MODEL_STM_SIMULINK_BLDC_T *const STM_SIMULINK_BLDC_M = &STM_SIMULINK_BLDC_M_;

/* Model step function */
void STM_SIMULINK_BLDC_step(void)
{
  real32_T rtb_Product_k;
  real32_T rtb_Sum4;
  real32_T rtb_Switch_idx_0;
  real32_T rtb_sum_beta;
  uint16_T rtb_Get_Integer;
  boolean_T rtb_NOT_g2;

  /* Outputs for Atomic SubSystem: '<S1>/Start and Stop Motor' */
  /* Logic: '<S3>/NOT' incorporates:
   *  Inport: '<Root>/push_button'
   */
  rtb_NOT_g2 = !STM_SIMULINK_BLDC_U.push_button;

  /* Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  /* Logic: '<S3>/AND' incorporates:
   *  Logic: '<S3>/NOT2'
   *  UnitDelay: '<S3>/Unit Delay'
   */
  if (rtb_NOT_g2 && (!STM_SIMULINK_BLDC_DW.UnitDelay_DSTATE_e)) {
    /* UnitDelay: '<S4>/Unit Delay' */
    STM_SIMULINK_BLDC_B.UnitDelay = STM_SIMULINK_BLDC_DW.UnitDelay_DSTATE_n;

    /* Logic: '<S4>/NOT' incorporates:
     *  UnitDelay: '<S4>/Unit Delay'
     */
    STM_SIMULINK_BLDC_DW.UnitDelay_DSTATE_n = !STM_SIMULINK_BLDC_B.UnitDelay;
  }

  /* End of Logic: '<S3>/AND' */
  /* End of Outputs for SubSystem: '<S3>/Enabled Subsystem' */

  /* Update for UnitDelay: '<S3>/Unit Delay' */
  STM_SIMULINK_BLDC_DW.UnitDelay_DSTATE_e = rtb_NOT_g2;

  /* End of Outputs for SubSystem: '<S1>/Start and Stop Motor' */

  /* Logic: '<S13>/NOT' incorporates:
   *  Logic: '<S9>/NOT'
   *  Switch: '<S9>/Switch'
   */
  rtb_NOT_g2 = !STM_SIMULINK_BLDC_B.UnitDelay;

  /* DiscreteIntegrator: '<S13>/Ramp Generator' incorporates:
   *  Logic: '<S13>/NOT'
   */
  if ((rtb_NOT_g2 && (STM_SIMULINK_BLDC_DW.RampGenerator_PrevResetState <= 0)) ||
      ((!rtb_NOT_g2) && (STM_SIMULINK_BLDC_DW.RampGenerator_PrevResetState == 1)))
  {
    STM_SIMULINK_BLDC_DW.RampGenerator_DSTATE =
      STM_SIMULINK_BLDC_P.RampGenerator_IC;
  }

  if (STM_SIMULINK_BLDC_DW.RampGenerator_DSTATE >=
      STM_SIMULINK_BLDC_P.RampGenerator_UpperSat) {
    STM_SIMULINK_BLDC_DW.RampGenerator_DSTATE =
      STM_SIMULINK_BLDC_P.RampGenerator_UpperSat;
  } else if (STM_SIMULINK_BLDC_DW.RampGenerator_DSTATE <=
             STM_SIMULINK_BLDC_P.RampGenerator_LowerSat) {
    STM_SIMULINK_BLDC_DW.RampGenerator_DSTATE =
      STM_SIMULINK_BLDC_P.RampGenerator_LowerSat;
  }

  /* Saturate: '<Root>/Saturation' incorporates:
   *  Inport: '<Root>/speed'
   */
  if (STM_SIMULINK_BLDC_U.speed > STM_SIMULINK_BLDC_P.Saturation_UpperSat_h) {
    rtb_Get_Integer = STM_SIMULINK_BLDC_P.Saturation_UpperSat_h;
  } else if (STM_SIMULINK_BLDC_U.speed <
             STM_SIMULINK_BLDC_P.Saturation_LowerSat_e) {
    rtb_Get_Integer = STM_SIMULINK_BLDC_P.Saturation_LowerSat_e;
  } else {
    rtb_Get_Integer = STM_SIMULINK_BLDC_U.speed;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Product: '<S11>/Product' incorporates:
   *  DiscreteIntegrator: '<S13>/Ramp Generator'
   *  Gain: '<Root>/Gain'
   *  Gain: '<S11>/rpm2freq'
   */
  rtb_Product_k = (real32_T)((uint32_T)STM_SIMULINK_BLDC_P.Gain_Gain_d *
    rtb_Get_Integer) * 0.000244140625F * ((real32_T)
    STM_SIMULINK_BLDC_P.rpm2freq_Gain * 2.91038305E-11F) *
    STM_SIMULINK_BLDC_DW.RampGenerator_DSTATE;

  /* Outputs for Enabled SubSystem: '<S15>/Accumulate' incorporates:
   *  EnablePort: '<S26>/Enable'
   */
  STM_SIMULINK_BLDC_DW.Accumulate_MODE = true;

  /* Outputs for Enabled SubSystem: '<S26>/Subsystem' incorporates:
   *  EnablePort: '<S27>/Enable'
   */
  /* Delay: '<S26>/Delay' */
  if (STM_SIMULINK_BLDC_DW.Delay_DSTATE) {
    /* SignalConversion generated from: '<S27>/Input' incorporates:
     *  Gain: '<S12>/position_increment'
     *  Gain: '<S15>/scaleIn'
     */
    STM_SIMULINK_BLDC_B.Input = STM_SIMULINK_BLDC_P.position_increment_Gain *
      rtb_Product_k * STM_SIMULINK_BLDC_P.scaleIn_Gain;
  }

  /* End of Delay: '<S26>/Delay' */
  /* End of Outputs for SubSystem: '<S26>/Subsystem' */

  /* Sum: '<S26>/Add' incorporates:
   *  UnitDelay: '<S15>/Unit Delay'
   */
  rtb_sum_beta = STM_SIMULINK_BLDC_B.Input + STM_SIMULINK_BLDC_B.Add1;

  /* DataTypeConversion: '<S26>/Data Type Conversion' */
  rtb_Switch_idx_0 = (real32_T)floor(rtb_sum_beta);
  if (rtIsNaNF(rtb_Switch_idx_0) || rtIsInfF(rtb_Switch_idx_0)) {
    rtb_Switch_idx_0 = 0.0F;
  } else {
    rtb_Switch_idx_0 = (real32_T)fmod(rtb_Switch_idx_0, 65536.0);
  }

  /* Sum: '<S26>/Add1' incorporates:
   *  DataTypeConversion: '<S26>/Data Type Conversion'
   *  DataTypeConversion: '<S26>/Data Type Conversion1'
   */
  STM_SIMULINK_BLDC_B.Add1 = rtb_sum_beta - (real32_T)(rtb_Switch_idx_0 < 0.0F ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-rtb_Switch_idx_0 : (int32_T)(int16_T)
    (uint16_T)rtb_Switch_idx_0);

  /* Update for Delay: '<S26>/Delay' incorporates:
   *  Constant: '<S26>/Constant'
   */
  STM_SIMULINK_BLDC_DW.Delay_DSTATE = STM_SIMULINK_BLDC_P.Constant_Value_lk;

  /* End of Outputs for SubSystem: '<S15>/Accumulate' */

  /* Gain: '<S22>/convert_pu' incorporates:
   *  Gain: '<S15>/scaleOut'
   */
  rtb_sum_beta = STM_SIMULINK_BLDC_P.scaleOut_Gain * STM_SIMULINK_BLDC_B.Add1 *
    STM_SIMULINK_BLDC_P.convert_pu_Gain;

  /* If: '<S22>/If' incorporates:
   *  Constant: '<S23>/Constant'
   *  DataTypeConversion: '<S25>/Convert_uint16'
   *  RelationalOperator: '<S23>/Compare'
   */
  if (rtb_sum_beta < STM_SIMULINK_BLDC_P.Constant_Value_l) {
    /* Outputs for IfAction SubSystem: '<S22>/If Action Subsystem' incorporates:
     *  ActionPort: '<S24>/Action Port'
     */
    /* DataTypeConversion: '<S24>/Convert_uint16' */
    rtb_Switch_idx_0 = (real32_T)floor(rtb_sum_beta);
    if (rtIsInfF(rtb_Switch_idx_0)) {
      rtb_Switch_idx_0 = 0.0F;
    } else {
      rtb_Switch_idx_0 = (real32_T)fmod(rtb_Switch_idx_0, 65536.0);
    }

    /* Sum: '<S24>/Sum' incorporates:
     *  DataTypeConversion: '<S24>/Convert_back'
     *  DataTypeConversion: '<S24>/Convert_uint16'
     */
    rtb_sum_beta -= (real32_T)(rtb_Switch_idx_0 < 0.0F ? (int32_T)(int16_T)
      -(int16_T)(uint16_T)-rtb_Switch_idx_0 : (int32_T)(int16_T)(uint16_T)
      rtb_Switch_idx_0);

    /* End of Outputs for SubSystem: '<S22>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S22>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S25>/Action Port'
     */
    if (rtb_sum_beta < 0.0F) {
      /* DataTypeConversion: '<S25>/Convert_uint16' */
      rtb_Switch_idx_0 = (real32_T)ceil(rtb_sum_beta);
    } else {
      /* DataTypeConversion: '<S25>/Convert_uint16' */
      rtb_Switch_idx_0 = (real32_T)floor(rtb_sum_beta);
    }

    /* DataTypeConversion: '<S25>/Convert_uint16' */
    if (rtIsNaNF(rtb_Switch_idx_0) || rtIsInfF(rtb_Switch_idx_0)) {
      rtb_Switch_idx_0 = 0.0F;
    } else {
      rtb_Switch_idx_0 = (real32_T)fmod(rtb_Switch_idx_0, 65536.0);
    }

    /* Sum: '<S25>/Sum' incorporates:
     *  DataTypeConversion: '<S25>/Convert_back'
     *  DataTypeConversion: '<S25>/Convert_uint16'
     */
    rtb_sum_beta -= (real32_T)(rtb_Switch_idx_0 < 0.0F ? (int32_T)(int16_T)
      -(int16_T)(uint16_T)-rtb_Switch_idx_0 : (int32_T)(int16_T)(uint16_T)
      rtb_Switch_idx_0);

    /* End of Outputs for SubSystem: '<S22>/If Action Subsystem1' */
  }

  /* End of If: '<S22>/If' */

  /* Gain: '<S19>/indexing' */
  rtb_sum_beta *= STM_SIMULINK_BLDC_P.indexing_Gain;

  /* DataTypeConversion: '<S19>/Get_Integer' */
  if (rtb_sum_beta < 0.0F) {
    rtb_Switch_idx_0 = (real32_T)ceil(rtb_sum_beta);
  } else {
    rtb_Switch_idx_0 = (real32_T)floor(rtb_sum_beta);
  }

  if (rtIsNaNF(rtb_Switch_idx_0) || rtIsInfF(rtb_Switch_idx_0)) {
    rtb_Switch_idx_0 = 0.0F;
  } else {
    rtb_Switch_idx_0 = (real32_T)fmod(rtb_Switch_idx_0, 65536.0);
  }

  rtb_Get_Integer = (uint16_T)(rtb_Switch_idx_0 < 0.0F ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-rtb_Switch_idx_0 : (int32_T)(uint16_T)rtb_Switch_idx_0);

  /* End of DataTypeConversion: '<S19>/Get_Integer' */

  /* Gain: '<S12>/Correction_Factor_sinePWM' incorporates:
   *  Abs: '<S12>/Abs'
   *  Gain: '<S12>/V-by-f'
   */
  rtb_Product_k = STM_SIMULINK_BLDC_P.Vbyf_Gain * (real32_T)fabs(rtb_Product_k) *
    STM_SIMULINK_BLDC_P.Correction_Factor_sinePWM_Gain;

  /* Switch: '<S16>/Switch' incorporates:
   *  Constant: '<S2>/Boost Voltage'
   *  RelationalOperator: '<S16>/Relational Operator'
   */
  if (!(rtb_Product_k > STM_SIMULINK_BLDC_P.BoostVoltage_Value)) {
    rtb_Product_k = STM_SIMULINK_BLDC_P.BoostVoltage_Value;
  }

  /* End of Switch: '<S16>/Switch' */

  /* Saturate: '<S16>/Saturation' */
  if (rtb_Product_k > STM_SIMULINK_BLDC_P.Saturation_UpperSat) {
    rtb_Product_k = STM_SIMULINK_BLDC_P.Saturation_UpperSat;
  } else if (rtb_Product_k < STM_SIMULINK_BLDC_P.Saturation_LowerSat) {
    rtb_Product_k = STM_SIMULINK_BLDC_P.Saturation_LowerSat;
  }

  /* End of Saturate: '<S16>/Saturation' */

  /* Sum: '<S19>/Sum2' incorporates:
   *  DataTypeConversion: '<S19>/Data Type Conversion1'
   */
  rtb_sum_beta -= (real32_T)rtb_Get_Integer;

  /* Selector: '<S19>/Lookup' incorporates:
   *  Constant: '<S19>/offset'
   *  Constant: '<S19>/sine_table_values'
   *  Sum: '<S19>/Sum'
   *  Sum: '<S21>/Sum3'
   */
  rtb_Switch_idx_0 = STM_SIMULINK_BLDC_P.sine_table_values_Value[(int32_T)
    ((uint32_T)STM_SIMULINK_BLDC_P.offset_Value[1] + rtb_Get_Integer)];

  /* Sum: '<S21>/Sum4' incorporates:
   *  Constant: '<S19>/offset'
   *  Constant: '<S19>/sine_table_values'
   *  Product: '<S21>/Product'
   *  Selector: '<S19>/Lookup'
   *  Sum: '<S19>/Sum'
   *  Sum: '<S21>/Sum3'
   */
  rtb_Sum4 = (STM_SIMULINK_BLDC_P.sine_table_values_Value[(int32_T)((uint32_T)
    STM_SIMULINK_BLDC_P.offset_Value[0] + rtb_Get_Integer)] - rtb_Switch_idx_0) *
    rtb_sum_beta + rtb_Switch_idx_0;

  /* Selector: '<S19>/Lookup' incorporates:
   *  Constant: '<S19>/offset'
   *  Constant: '<S19>/sine_table_values'
   *  Sum: '<S19>/Sum'
   *  Sum: '<S21>/Sum5'
   */
  rtb_Switch_idx_0 = STM_SIMULINK_BLDC_P.sine_table_values_Value[(int32_T)
    ((uint32_T)STM_SIMULINK_BLDC_P.offset_Value[3] + rtb_Get_Integer)];

  /* Sum: '<S21>/Sum6' incorporates:
   *  Constant: '<S19>/offset'
   *  Constant: '<S19>/sine_table_values'
   *  Product: '<S21>/Product1'
   *  Selector: '<S19>/Lookup'
   *  Sum: '<S19>/Sum'
   *  Sum: '<S21>/Sum5'
   */
  rtb_sum_beta = (STM_SIMULINK_BLDC_P.sine_table_values_Value[(int32_T)
                  ((uint32_T)STM_SIMULINK_BLDC_P.offset_Value[2] +
                   rtb_Get_Integer)] - rtb_Switch_idx_0) * rtb_sum_beta +
    rtb_Switch_idx_0;

  /* Outputs for Atomic SubSystem: '<S14>/Inverse Park Transform' */
  /* Switch: '<S20>/Switch' incorporates:
   *  Constant: '<S14>/Constant'
   *  Constant: '<S20>/Offset'
   *  Product: '<S18>/dcos'
   *  Product: '<S18>/dsin'
   *  Product: '<S18>/qcos'
   *  Product: '<S18>/qsin'
   *  Sum: '<S18>/sum_alpha'
   *  Sum: '<S18>/sum_beta'
   *  UnaryMinus: '<S14>/Unary Minus'
   *  UnaryMinus: '<S20>/Unary_Minus'
   */
  if (STM_SIMULINK_BLDC_P.Offset_Value > STM_SIMULINK_BLDC_P.Switch_Threshold) {
    rtb_Switch_idx_0 = -rtb_Product_k * rtb_sum_beta +
      STM_SIMULINK_BLDC_P.Constant_Value_i * rtb_Sum4;
    rtb_Product_k = -(STM_SIMULINK_BLDC_P.Constant_Value_i * rtb_sum_beta -
                      -rtb_Product_k * rtb_Sum4);
  } else {
    rtb_Switch_idx_0 = STM_SIMULINK_BLDC_P.Constant_Value_i * rtb_sum_beta -
      -rtb_Product_k * rtb_Sum4;
    rtb_Product_k = -rtb_Product_k * rtb_sum_beta +
      STM_SIMULINK_BLDC_P.Constant_Value_i * rtb_Sum4;
  }

  /* End of Switch: '<S20>/Switch' */
  /* End of Outputs for SubSystem: '<S14>/Inverse Park Transform' */

  /* Switch: '<S10>/Switch4' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S18>/a16'
   *  Constant: '<S10>/stop'
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/Constant1'
   *  Gain: '<S7>/Gain'
   *  Product: '<S7>/Product'
   *  Sum: '<S17>/add_b'
   *  Sum: '<S17>/add_c'
   *  Sum: '<S7>/Sum'
   */
  if (STM_SIMULINK_BLDC_B.UnitDelay) {
    /* Outputs for Atomic SubSystem: '<S14>/Inverse Park Transform' */
    /* Gain: '<S17>/sqrt3_by_two' incorporates:
     *  AlgorithmDescriptorDelegate generated from: '<S18>/a16'
     */
    rtb_sum_beta = STM_SIMULINK_BLDC_P.sqrt3_by_two_Gain * rtb_Product_k;

    /* Gain: '<S17>/one_by_two' incorporates:
     *  AlgorithmDescriptorDelegate generated from: '<S18>/a16'
     */
    rtb_Sum4 = STM_SIMULINK_BLDC_P.one_by_two_Gain * rtb_Switch_idx_0;
    rtb_Switch_idx_0 = (rtb_Switch_idx_0 + STM_SIMULINK_BLDC_P.Constant_Value) *
      STM_SIMULINK_BLDC_P.Gain_Gain * STM_SIMULINK_BLDC_P.Constant1_Value;

    /* End of Outputs for SubSystem: '<S14>/Inverse Park Transform' */
    rtb_Product_k = ((rtb_sum_beta - rtb_Sum4) +
                     STM_SIMULINK_BLDC_P.Constant_Value) *
      STM_SIMULINK_BLDC_P.Gain_Gain * STM_SIMULINK_BLDC_P.Constant1_Value;
    rtb_sum_beta = (((0.0F - rtb_Sum4) - rtb_sum_beta) +
                    STM_SIMULINK_BLDC_P.Constant_Value) *
      STM_SIMULINK_BLDC_P.Gain_Gain * STM_SIMULINK_BLDC_P.Constant1_Value;
  } else {
    rtb_Switch_idx_0 = STM_SIMULINK_BLDC_P.stop_Value;
    rtb_Product_k = STM_SIMULINK_BLDC_P.stop_Value;
    rtb_sum_beta = STM_SIMULINK_BLDC_P.stop_Value;
  }

  /* End of Switch: '<S10>/Switch4' */

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  rtb_Switch_idx_0 = (real32_T)floor(rtb_Switch_idx_0);
  if (rtIsNaNF(rtb_Switch_idx_0) || rtIsInfF(rtb_Switch_idx_0)) {
    rtb_Switch_idx_0 = 0.0F;
  } else {
    rtb_Switch_idx_0 = (real32_T)fmod(rtb_Switch_idx_0, 4.294967296E+9);
  }

  rtb_Product_k = (real32_T)floor(rtb_Product_k);
  if (rtIsNaNF(rtb_Product_k) || rtIsInfF(rtb_Product_k)) {
    rtb_Product_k = 0.0F;
  } else {
    rtb_Product_k = (real32_T)fmod(rtb_Product_k, 4.294967296E+9);
  }

  rtb_sum_beta = (real32_T)floor(rtb_sum_beta);
  if (rtIsNaNF(rtb_sum_beta) || rtIsInfF(rtb_sum_beta)) {
    rtb_sum_beta = 0.0F;
  } else {
    rtb_sum_beta = (real32_T)fmod(rtb_sum_beta, 4.294967296E+9);
  }

  /* Outport: '<Root>/pwm_1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   */
  STM_SIMULINK_BLDC_Y.pwm_1 = rtb_Switch_idx_0 < 0.0F ? (uint32_T)-(int32_T)
    (uint32_T)-rtb_Switch_idx_0 : (uint32_T)rtb_Switch_idx_0;

  /* Outport: '<Root>/pwm_2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   */
  STM_SIMULINK_BLDC_Y.pwm_2 = rtb_Product_k < 0.0F ? (uint32_T)-(int32_T)
    (uint32_T)-rtb_Product_k : (uint32_T)rtb_Product_k;

  /* Outport: '<Root>/pwm_3' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   */
  STM_SIMULINK_BLDC_Y.pwm_3 = rtb_sum_beta < 0.0F ? (uint32_T)-(int32_T)
    (uint32_T)-rtb_sum_beta : (uint32_T)rtb_sum_beta;

  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S9>/Constant1'
   */
  if (STM_SIMULINK_BLDC_P.Constant1_Value_b >
      STM_SIMULINK_BLDC_P.Switch_Threshold_n) {
    /* Outport: '<Root>/enable_out' */
    STM_SIMULINK_BLDC_Y.enable_out = STM_SIMULINK_BLDC_B.UnitDelay;
  } else {
    /* Outport: '<Root>/enable_out' */
    STM_SIMULINK_BLDC_Y.enable_out = rtb_NOT_g2;
  }

  /* Update for DiscreteIntegrator: '<S13>/Ramp Generator' incorporates:
   *  Constant: '<S11>/Ramp_Time (sec)'
   *  Constant: '<S13>/One'
   *  Gain: '<S13>/Sample_Time'
   *  Logic: '<S13>/NOT'
   *  Product: '<S13>/Divide'
   */
  STM_SIMULINK_BLDC_DW.RampGenerator_DSTATE += STM_SIMULINK_BLDC_P.One_Value /
    STM_SIMULINK_BLDC_P.Ramp_Timesec_Value * STM_SIMULINK_BLDC_P.Ts *
    STM_SIMULINK_BLDC_P.RampGenerator_gainval;
  if (STM_SIMULINK_BLDC_DW.RampGenerator_DSTATE >=
      STM_SIMULINK_BLDC_P.RampGenerator_UpperSat) {
    STM_SIMULINK_BLDC_DW.RampGenerator_DSTATE =
      STM_SIMULINK_BLDC_P.RampGenerator_UpperSat;
  } else if (STM_SIMULINK_BLDC_DW.RampGenerator_DSTATE <=
             STM_SIMULINK_BLDC_P.RampGenerator_LowerSat) {
    STM_SIMULINK_BLDC_DW.RampGenerator_DSTATE =
      STM_SIMULINK_BLDC_P.RampGenerator_LowerSat;
  }

  STM_SIMULINK_BLDC_DW.RampGenerator_PrevResetState = (int8_T)rtb_NOT_g2;

  /* End of Update for DiscreteIntegrator: '<S13>/Ramp Generator' */
}

/* Model initialize function */
void STM_SIMULINK_BLDC_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* InitializeConditions for DiscreteIntegrator: '<S13>/Ramp Generator' */
  STM_SIMULINK_BLDC_DW.RampGenerator_DSTATE =
    STM_SIMULINK_BLDC_P.RampGenerator_IC;
  STM_SIMULINK_BLDC_DW.RampGenerator_PrevResetState = 2;

  /* SystemInitialize for Atomic SubSystem: '<S1>/Start and Stop Motor' */
  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay' */
  STM_SIMULINK_BLDC_DW.UnitDelay_DSTATE_e =
    STM_SIMULINK_BLDC_P.UnitDelay_InitialCondition_m;

  /* SystemInitialize for Enabled SubSystem: '<S3>/Enabled Subsystem' */
  /* InitializeConditions for UnitDelay: '<S4>/Unit Delay' */
  STM_SIMULINK_BLDC_DW.UnitDelay_DSTATE_n =
    STM_SIMULINK_BLDC_P.UnitDelay_InitialCondition_n;

  /* SystemInitialize for UnitDelay: '<S4>/Unit Delay' incorporates:
   *  Outport: '<S4>/Out1'
   */
  STM_SIMULINK_BLDC_B.UnitDelay = STM_SIMULINK_BLDC_P.Out1_Y0_g;

  /* End of SystemInitialize for SubSystem: '<S3>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<S1>/Start and Stop Motor' */

  /* SystemInitialize for Enabled SubSystem: '<S15>/Accumulate' */
  /* InitializeConditions for Delay: '<S26>/Delay' */
  STM_SIMULINK_BLDC_DW.Delay_DSTATE = STM_SIMULINK_BLDC_P.Delay_InitialCondition;

  /* SystemInitialize for Enabled SubSystem: '<S26>/Subsystem' */
  /* SystemInitialize for SignalConversion generated from: '<S27>/Input' incorporates:
   *  Outport: '<S27>/Out1'
   */
  STM_SIMULINK_BLDC_B.Input = STM_SIMULINK_BLDC_P.Out1_Y0;

  /* End of SystemInitialize for SubSystem: '<S26>/Subsystem' */

  /* SystemInitialize for Sum: '<S26>/Add1' incorporates:
   *  Outport: '<S26>/theta_e'
   */
  STM_SIMULINK_BLDC_B.Add1 = STM_SIMULINK_BLDC_P.theta_e_Y0;

  /* End of SystemInitialize for SubSystem: '<S15>/Accumulate' */
}

/* Model terminate function */
void STM_SIMULINK_BLDC_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
