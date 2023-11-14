/*============================================================================*/
/*                        VNI SOFTWARE GROUP                                  */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: FSM_SBC_High_Side_Diagnostic.c $
 * $Revision: version $
 * $Author: uie46352 $
 * $Date: 12 ene. 2023 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    short description in one sentence end with dot.
    detailed
    multiline
    description of the file
*/
/*============================================================================*/
/* COPYRIGHT (C) CONTINENTAL AUTOMOTIVE 2020                                  */
/* AUTOMOTIVE GROUP, VNI                                                      */
/* ALL RIGHTS RESERVED                                                        */
/*                                                                            */
/* The reproduction, transmission, or use of this document or its content is  */
/* not permitted without express written authority. Offenders will be liable  */
/* for damages.                                                               */
/* All rights, including rights created by patent grant or registration of a  */
/* utility model or design, are reserved.                                     */
/*                                                                            */
/*============================================================================*/
/*============================================================================*/
/*                    REUSE HISTORY - taken over from                         */
/*============================================================================*/
/*  DATABASE           |        PROJECT     | FILE VERSION (AND INSTANCE)     */
/*----------------------------------------------------------------------------*/
/*                     |                    |                                 */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: FSM_SBC_High_Side_Diagnostic.c  $
  ============================================================================*/
/* Revision 1.3 2023/03/17 18:50:47CET Robles, Jorge (uie46352)  */
/* Fixes for Qtools */
/* Revision 1.2 2023/02/01 18:50:47CET Robles, Jorge (uie46352)  */
/* Created and compiled with arxml, new swc created just for retry strategy */
/* Revision 1.1 2023/02/01 18:50:47CET Robles, Jorge (uie46352)  */
/* Initial revision */
/* Member added to project /BS/GM_GLB_20_PLGM/Software/mc_sw/_Core/appl/Appl_CAS/manual_src/FSM_SBC_High_Side_Diagnostic/Src/project.pj */



/* Includes */
/*============================================================================*/
#include "EcuM.h"
#include "NvM_Callbacks.h"
#include "FSM_SBC_High_Side_Diagnostic.h"
#include "Sbc.h"
#include "Rte_FSM_SBC_High_Side_Diagnostic.h"




/* Constants and types  */
/*============================================================================*/
#ifndef SWATT_BYPASS
/* ANALYSIS_REPORT_JUSTIFICATION (2023/02/09 : uie46352) !-->
   TOOL_NUMBER(PCLINT:9026) GUIDELINE(MISRA_2012:DIRECTIVE:4.9) This macro is used only by SWATT, no issue.
   TOOL_NUMBER(PCLINT:9026) GUIDELINE(MISRA_2012:DIRECTIVE:4.9)
 <--! */
#define SWATT_BYPASS(a,b)
#endif

#ifdef _lint
#define C_TRUE      (1==1)
#define C_FALSE     (1==0)
#else
#define C_TRUE      TRUE
#define C_FALSE     FALSE
#endif

//SBC Error Bit
/* ANALYSIS_REPORT_START_JUSTIFICATION (2019/07/08:uidn9511) !-->
TOOL_NUMBER(pclint:9026) GUIDELINE(MISRA_2012:directive:4.9) Intended use of function like macro to reduce code complexity.<--! */
#define SBC_REGISTER_HS_OL_STAT(ls_sbcGetError)           ((ls_sbcGetError).Sbc_HS_OL_STAT)
/* ANALYSIS_REPORT_END_JUSTIFICATION */

//SBC Output Control Register
#define SBC_HS_CTRL1_HS1_OUTPUT_MASK                      (0x07u)
#define SBC_HS_CTRL1_HS2_OUTPUT_MASK                      (0x70u)
#define SBC_HS_CTRL2_HS4_OUTPUT_MASK                      (0x70u)

#define SBC_HS_CTRL1_ID     (0x14u)
#define SBC_HS_CTRL2_ID     (0x15u)


#define SBC_HS1_OL_MASK                                (0x01u)
#define SBC_HS2_OL_MASK                                (0x02u)
#define SBC_HS4_OL_MASK                                (0x08u)

#define SBC_HS1_OL_N_BIT_IN_REG                        (0u)
#define SBC_HS2_OL_N_BIT_IN_REG                        (1u)
#define SBC_HS4_OL_N_BIT_IN_REG                        (3u)

/* ANALYSIS_REPORT_START_JUSTIFICATION (2019/07/08:uidn9511) !-->
TOOL_NUMBER(pclint:9026) GUIDELINE(MISRA_2012:directive:4.9) Necessary to shift bit values. Intended use of function like macro to reduce code complexity.<--! */

#define SBC_REGISTER_HS1_OL(x)                         ((x & SBC_HS1_OL_MASK) >> SBC_HS1_OL_N_BIT_IN_REG)
#define SBC_REGISTER_HS2_OL(x)                         ((x & SBC_HS2_OL_MASK) >> SBC_HS2_OL_N_BIT_IN_REG)
#define SBC_REGISTER_HS4_OL(x)                         ((x & SBC_HS4_OL_MASK) >> SBC_HS4_OL_N_BIT_IN_REG)

/* ANALYSIS_REPORT_END_JUSTIFICATION */


#define SBC_BITERROR_HS1_MASK           (0x01u)
#define SBC_BITERROR_HS2_MASK           (0x02u)
#define SBC_BITERROR_HS4_MASK           (0x08u)

#define SBC_HS_RETRY_STRAT_TASK_TIME    (5u)

#define SBC_HS_MAX_NUM_RETRIES        (3600u)
#define SBC_HS_FAIL_RECOVER_TIME      (100u)
#define SBC_HS_REACTIVATION_TIME      (1000u)

#define TRUE_UINT                   (1u)

/* SbcHSStrategyStates */
#define SBC_HS_RET_IDLE                (0u)
#define SBC_HS_RET_REACTIVATION_TIME   (1u)
#define SBC_HS_RET_RETRY               (2u)
#define SBC_HS_RET_FAILED              (3u)
#define SBC_HS_RET_STATES              (4u)



typedef void(* Sbc_HS_RetryStrategy_State)(SBC_HS_ID HighSideId);

typedef struct
{
    FSM_Bool RetryEnabled;
    FSM_Uint8 Sbc_HSOutputId;
    FSM_Uint8 State;
    FSM_Bool OverloadDetected;
    FSM_Bool OutputState;
    FSM_Bool OverloadFaultActive;
    FSM_Uint16 ReactivationTimer;
    FSM_Uint16 RecoveryTimer;
    FSM_Uint16 RetryCounter;
}Sbc_HS_RetryStrategyType;




/* Variables */
/*============================================================================*/
static VAR(SbcStatusInfoType, AUTOMATIC) Sbc_StatusRegister  ;
/* ANALYSIS_REPORT_JUSTIFICATION (2023/02/09 : uie46352) !-->
   TOOL_NUMBER(PCLINT:9003) GUIDELINE(MISRA_2012:RULE:8.9) Defined in this way for futures uses.
 <--! */
static VAR(uint8, AUTOMATIC) Sbc_HS_OL = 0u;
/* ANALYSIS_REPORT_JUSTIFICATION (2023/02/09 : uie46352) !-->
   TOOL_NUMBER(PCLINT:9003) GUIDELINE(MISRA_2012:RULE:8.9) Defined in this way for futures uses.
 <--! */
static VAR(uint8, AUTOMATIC) Sbc_HS1_OL = 0u;
/* ANALYSIS_REPORT_JUSTIFICATION (2023/02/09 : uie46352) !-->
   TOOL_NUMBER(PCLINT:9003) GUIDELINE(MISRA_2012:RULE:8.9) Defined in this way for futures uses.
 <--! */
static VAR(uint8, AUTOMATIC) Sbc_HS2_OL = 0u;
/* ANALYSIS_REPORT_JUSTIFICATION (2023/02/09 : uie46352) !-->
   TOOL_NUMBER(PCLINT:9003) GUIDELINE(MISRA_2012:RULE:8.9) Defined in this way for futures uses.
 <--! */
static VAR(uint8, AUTOMATIC) Sbc_HS4_OL = 0u;

static Sbc_HS_RetryStrategyType Sbc_HS_RetryStrategyData[SCB_SUPPORTED_HS] ;



/* Private functions prototypes */
/*============================================================================*/
static void Diag_SbcHSOverLoadFaultRetry(void);
static void Sbc_HS_RetryStrategy_Idle(SBC_HS_ID HighSideOutput);
static void Sbc_HS_RetryStrategy_ReactivationTime(SBC_HS_ID HighSideOutput);
static void Sbc_HS_RetryStrategy_Retry(SBC_HS_ID HighSideOutput);
static void Sbc_HS_RetryStrategy_Failed(SBC_HS_ID HighSideOutput);

static void Set_Sbc_HS_RetryStrategyData_DefaultValues(void);



/* Inline functions */
/*============================================================================*/




/* Private functions */
/*============================================================================*/




/* Exported functions */
/*============================================================================*/


FUNC(void,FSM_SBC_High_Side_Diagnostic_CODE) FSM_SBC_High_Side_Diagnostic_Init(void)
{
    SuspendAllInterrupts();

    Set_Sbc_HS_RetryStrategyData_DefaultValues();

    ResumeAllInterrupts();


}

FUNC(void,FSM_SBC_High_Side_Diagnostic_CODE) FSM_SBC_High_Side_Diagnostic_Task_5ms (void)
{

    /* SBC Monitoring */
    (void)Sbc_GetStatusInformation(&Sbc_StatusRegister);

    Diag_SbcHSOverLoadFaultRetry();


    Sbc_HS_OL = SBC_REGISTER_HS_OL_STAT(Sbc_StatusRegister);

    /* ANALYSIS_REPORT_JUSTIFICATION (2023/02/02 : uie46352) !-->
       TOOL_NUMBER(PCLINT:835) GUIDELINE(N/A:N/A:N/A) To keep consistency to the other HS
     <--! */
    Sbc_HS1_OL = SBC_REGISTER_HS1_OL(Sbc_HS_OL);
    Sbc_HS2_OL = SBC_REGISTER_HS2_OL(Sbc_HS_OL);
    Sbc_HS4_OL = SBC_REGISTER_HS4_OL(Sbc_HS_OL);


     (void)Rte_Write_P_SBC_HS1_OC_OT_VDT_HS_OC_OT((IDT_HS_OC_OT_Type)Fsm_Bool_To_Bool_uint8(Sbc_HS_RetryStrategyData[SBC_HS_1].OverloadFaultActive));
     (void)Rte_Write_P_SBC_HS2_OC_OT_VDT_HS_OC_OT((IDT_HS_OC_OT_Type)Fsm_Bool_To_Bool_uint8(Sbc_HS_RetryStrategyData[SBC_HS_2].OverloadFaultActive));
     (void)Rte_Write_P_SBC_HS4_OC_OT_VDT_HS_OC_OT((IDT_HS_OC_OT_Type)Fsm_Bool_To_Bool_uint8(Sbc_HS_RetryStrategyData[SBC_HS_4].OverloadFaultActive));

     (void)Rte_Write_P_SBC_HS1_OL_VDT_HS_OL(Sbc_HS1_OL);
     (void)Rte_Write_P_SBC_HS2_OL_VDT_HS_OL(Sbc_HS2_OL);
     (void)Rte_Write_P_SBC_HS4_OL_VDT_HS_OL(Sbc_HS4_OL);


     (void)WdgM_UpdateAliveCounter((WdgM_SupervisedEntityIdType) SE_FSM_SBC_HIGH_SIDE_DIAGNOSTIC_TASK);


}


static void Sbc_HS_RetryStrategy_Idle(SBC_HS_ID HighSideOutput)
{

    SuspendAllInterrupts();

    /* Check if a fault has been detected in specific High Side output */
    DataIntegrityCheck_FSM_Bool(&Sbc_HS_RetryStrategyData[HighSideOutput].OverloadDetected);
    DataIntegrityCheck_FSM_Bool(&Sbc_HS_RetryStrategyData[HighSideOutput].RetryEnabled);

    if(Sbc_HS_RetryStrategyData[HighSideOutput].OverloadDetected == FSM_TRUE)
    {
        /* Set Fault Active flag status as true, this state will remain until a successful reactivation of the output */
        Sbc_HS_RetryStrategyData[HighSideOutput].OverloadFaultActive = FSM_TRUE;


        /* Check if the specific High Side output requires the retry strategy */
        if(Sbc_HS_RetryStrategyData[HighSideOutput].RetryEnabled == FSM_TRUE)
        {
            /* Start retry strategy */

            /* Set initial value for Reactivation Timer and Retry Counter */
            Sbc_HS_RetryStrategyData[HighSideOutput].ReactivationTimer.ValDTU16 = SBC_HS_REACTIVATION_TIME;
            Sbc_HS_RetryStrategyData[HighSideOutput].ReactivationTimer.InvDTU16 = ~Sbc_HS_RetryStrategyData[HighSideOutput].ReactivationTimer.ValDTU16;
            Sbc_HS_RetryStrategyData[HighSideOutput].RetryCounter.ValDTU16 = 0u;
            Sbc_HS_RetryStrategyData[HighSideOutput].RetryCounter.InvDTU16 = (uint16)~Sbc_HS_RetryStrategyData[HighSideOutput].RetryCounter.ValDTU16;
            /* Jump to Reactivation Time state */
            Sbc_HS_RetryStrategyData[HighSideOutput].State.ValDTU8 = (uint8)SBC_HS_RET_REACTIVATION_TIME;
            Sbc_HS_RetryStrategyData[HighSideOutput].State.InvDTU8= (uint8)~Sbc_HS_RetryStrategyData[HighSideOutput].State.ValDTU8;
        }
        else
        {
            /* Retry strategy is not enabled for this HS output, jump directly to failed state */
            Sbc_HS_RetryStrategyData[HighSideOutput].State.ValDTU8 = (uint8)SBC_HS_RET_FAILED;
            Sbc_HS_RetryStrategyData[HighSideOutput].State.InvDTU8= (uint8)~Sbc_HS_RetryStrategyData[HighSideOutput].State.ValDTU8;
            FSM_Set_Error_Reaction(FSM_HALL_SENSORS_FAILED);
        }
    }
    else
    {
        /* No fault has been detected */
    }
    ResumeAllInterrupts();

}


static void Sbc_HS_RetryStrategy_ReactivationTime(SBC_HS_ID HighSideOutput)
{
    Sbc_State_Type OutputState = SBC_OUTPUT_HS_ON;
    Sbc_OutputId_Type OutputId;


    SuspendAllInterrupts();

    DataIntegrityCheck_FSM_Uint16(&Sbc_HS_RetryStrategyData[HighSideOutput].ReactivationTimer);
    DataIntegrityCheck_FSM_Uint16(&Sbc_HS_RetryStrategyData[HighSideOutput].RetryCounter);
    DataIntegrityCheck_FSM_Uint8(&Sbc_HS_RetryStrategyData[HighSideOutput].Sbc_HSOutputId);



    /* Has the reactivation timer has expired? */
    if(Sbc_HS_RetryStrategyData[HighSideOutput].ReactivationTimer.ValDTU16 > SBC_HS_RETRY_STRAT_TASK_TIME)
    {
        /* Maintain Reactivation timer */
        Sbc_HS_RetryStrategyData[HighSideOutput].ReactivationTimer.ValDTU16 -= SBC_HS_RETRY_STRAT_TASK_TIME;
        Sbc_HS_RetryStrategyData[HighSideOutput].ReactivationTimer.InvDTU16 = ~Sbc_HS_RetryStrategyData[HighSideOutput].ReactivationTimer.ValDTU16;

        /* Unused at this condition */
        (void)OutputState;
    }
    else
    {
        /* Timer has expired, trigger a reactivation retry if retry counter has not reached the limit */
        if(Sbc_HS_RetryStrategyData[HighSideOutput].RetryCounter.ValDTU16 < SBC_HS_MAX_NUM_RETRIES)
        {
            OutputId = (Sbc_State_Type)Sbc_HS_RetryStrategyData[HighSideOutput].Sbc_HSOutputId.ValDTU8;
            /* Turn on output */
            (void)Sbc_SetOutputState(&OutputId, &OutputState);

            /* Increase retry counter */
            Sbc_HS_RetryStrategyData[HighSideOutput].RetryCounter.ValDTU16++;
            Sbc_HS_RetryStrategyData[HighSideOutput].RetryCounter.InvDTU16 = ~Sbc_HS_RetryStrategyData[HighSideOutput].RetryCounter.ValDTU16;
            /* Reset recovery timer for retry process */
            Sbc_HS_RetryStrategyData[HighSideOutput].RecoveryTimer.ValDTU16 = SBC_HS_FAIL_RECOVER_TIME;
            Sbc_HS_RetryStrategyData[HighSideOutput].RecoveryTimer.InvDTU16 = ~Sbc_HS_RetryStrategyData[HighSideOutput].RecoveryTimer.ValDTU16;
            /* Jump to Retry state for healing process */
            Sbc_HS_RetryStrategyData[HighSideOutput].State.ValDTU8 = (uint8)SBC_HS_RET_RETRY;
            Sbc_HS_RetryStrategyData[HighSideOutput].State.InvDTU8= (uint8)~Sbc_HS_RetryStrategyData[HighSideOutput].State.ValDTU8;

        }
        else
        {
            /* The retry limit has been reached, failed retry strategy for this HS output */
            Sbc_HS_RetryStrategyData[HighSideOutput].State.ValDTU8 = (uint8)SBC_HS_RET_FAILED;
            Sbc_HS_RetryStrategyData[HighSideOutput].State.InvDTU8= (uint8)~Sbc_HS_RetryStrategyData[HighSideOutput].State.ValDTU8;
            FSM_Set_Error_Reaction(FSM_HALL_SENSORS_FAILED);
            /* Unused at this condition */
            (void)OutputState;
        }
    }
    ResumeAllInterrupts();

}


static void Sbc_HS_RetryStrategy_Retry(SBC_HS_ID HighSideOutput)
{
    SuspendAllInterrupts();

    DataIntegrityCheck_FSM_Bool(&Sbc_HS_RetryStrategyData[HighSideOutput].OutputState);
    DataIntegrityCheck_FSM_Bool(&Sbc_HS_RetryStrategyData[HighSideOutput].OverloadDetected);
    DataIntegrityCheck_FSM_Uint16(&Sbc_HS_RetryStrategyData[HighSideOutput].RecoveryTimer);

    /* Has the reactivation been successful? */
    if((Sbc_HS_RetryStrategyData[HighSideOutput].OutputState == FSM_TRUE) && (Sbc_HS_RetryStrategyData[HighSideOutput].OverloadDetected == FSM_FALSE))
    {
        /* Output error has been healed, and output has turned on */
        Sbc_HS_RetryStrategyData[HighSideOutput].OverloadFaultActive = FSM_FALSE;

        /* Finish with retry strategy, jump to Idle state */
        Sbc_HS_RetryStrategyData[HighSideOutput].State.ValDTU8 = (uint8)SBC_HS_RET_IDLE;
        Sbc_HS_RetryStrategyData[HighSideOutput].State.InvDTU8 = (uint8)~Sbc_HS_RetryStrategyData[HighSideOutput].State.ValDTU8;

    }
    else
    {
        /* Wait for Recovery Time for a successful reactivation */
        if(Sbc_HS_RetryStrategyData[HighSideOutput].RecoveryTimer.ValDTU16 > SBC_HS_RETRY_STRAT_TASK_TIME)
        {
            /* Maintain Recovery timer */
            Sbc_HS_RetryStrategyData[HighSideOutput].RecoveryTimer.ValDTU16 -= SBC_HS_RETRY_STRAT_TASK_TIME;
            Sbc_HS_RetryStrategyData[HighSideOutput].RecoveryTimer.InvDTU16 = ~Sbc_HS_RetryStrategyData[HighSideOutput].RecoveryTimer.ValDTU16;
        }
        else
        {
            /* The HS output has not recovered in the defined SBC_HS_FAIL_RECOVER_TIME, prepare for next retry */
            Sbc_HS_RetryStrategyData[HighSideOutput].ReactivationTimer.ValDTU16 = SBC_HS_REACTIVATION_TIME;
            Sbc_HS_RetryStrategyData[HighSideOutput].ReactivationTimer.InvDTU16 = ~Sbc_HS_RetryStrategyData[HighSideOutput].ReactivationTimer.ValDTU16;
            Sbc_HS_RetryStrategyData[HighSideOutput].State.ValDTU8 = (uint8)SBC_HS_RET_REACTIVATION_TIME;
            Sbc_HS_RetryStrategyData[HighSideOutput].State.InvDTU8 = (uint8)~Sbc_HS_RetryStrategyData[HighSideOutput].State.ValDTU8;

        }
    }
    ResumeAllInterrupts();

}


static void Sbc_HS_RetryStrategy_Failed(SBC_HS_ID HighSideOutput)
{
    SuspendAllInterrupts();

    DataIntegrityCheck_FSM_Bool(&Sbc_HS_RetryStrategyData[HighSideOutput].OutputState);
    DataIntegrityCheck_FSM_Bool(&Sbc_HS_RetryStrategyData[HighSideOutput].OverloadDetected);

    /* Has the previous fault been cleared? */
    if((Sbc_HS_RetryStrategyData[HighSideOutput].OutputState ==FSM_TRUE) && (Sbc_HS_RetryStrategyData[HighSideOutput].OverloadDetected ==FSM_FALSE))
    {
        /* Output error has been healed by an external activation (Not by the retry strategy) */
        Sbc_HS_RetryStrategyData[HighSideOutput].OverloadFaultActive = FSM_FALSE;
        /* Reset retrt strategy */
        Sbc_HS_RetryStrategyData[HighSideOutput].State.ValDTU8 = (uint8)SBC_HS_RET_IDLE;
        Sbc_HS_RetryStrategyData[HighSideOutput].State.InvDTU8 = (uint8)~Sbc_HS_RetryStrategyData[HighSideOutput].State.ValDTU8;

    }
    else
    {
        /* No retry strategy is currently active for this HS output, Fault should be maintained until next successful activation */
    }
    ResumeAllInterrupts();

}


static void Diag_SbcHSOverLoadFaultRetry(void)
{

    /* ANALYSIS_REPORT_START_JUSTIFICATION (2021/05/05: uidp6829) !-->
    TOOL_NUMBER(pclint:546) GUIDELINE(N/A:N/A:N/A) & used for function pointer as intended <--! */
    static const Sbc_HS_RetryStrategy_State Sbc_HS_RetryStrategySM[SBC_HS_RET_STATES] =
    {
        &Sbc_HS_RetryStrategy_Idle,
        &Sbc_HS_RetryStrategy_ReactivationTime,
        &Sbc_HS_RetryStrategy_Retry,
        &Sbc_HS_RetryStrategy_Failed
    };
    /* ANALYSIS_REPORT_END_JUSTIFICATION */

    uint8 lub_SbcHSIndex;

    /* High Side Control Registers variables (required to be static to avoid writing to stack) */
    static uint8 HS_Ctrl1RegVal = 0u;
    static uint8 HS_Ctrl2RegVal = 0u;

    SWATT_BYPASS(Diag_SbcHSOverLoadFaultRetry, m_Diag_SbcHSOverLoadFaultRetry());

    SuspendAllInterrupts();

    DataIntegrityCheck_FSM_Uint8(&Sbc_HS_RetryStrategyData[SBC_HS_1].State);
    DataIntegrityCheck_FSM_Uint8(&Sbc_HS_RetryStrategyData[SBC_HS_2].State);
    DataIntegrityCheck_FSM_Uint8(&Sbc_HS_RetryStrategyData[SBC_HS_4].State);

    /* Read SBC status information */
    (void)Sbc_GetStatusInformation(&Sbc_StatusRegister);

    /* Get High Side Overload Status */
    /* ANALYSIS_REPORT_START_JUSTIFICATION (2021/05/05: uidp6829) !-->
    TOOL_NUMBER(codecheck:S8) GUIDELINE(icr_201411:rule:c141) ? operation used for increasing readability. <--! */
    Sbc_HS_RetryStrategyData[SBC_HS_1].OverloadDetected = Bool_To_Fsm_Bool( ( SBC_BITERROR_HS1_MASK == (Sbc_StatusRegister.Sbc_HS_OC_OT_STAT & SBC_BITERROR_HS1_MASK) ) ? C_TRUE : C_FALSE );
    Sbc_HS_RetryStrategyData[SBC_HS_2].OverloadDetected = Bool_To_Fsm_Bool( ( SBC_BITERROR_HS2_MASK == (Sbc_StatusRegister.Sbc_HS_OC_OT_STAT & SBC_BITERROR_HS2_MASK) ) ? C_TRUE : C_FALSE );
    Sbc_HS_RetryStrategyData[SBC_HS_4].OverloadDetected = Bool_To_Fsm_Bool( ( SBC_BITERROR_HS4_MASK == (Sbc_StatusRegister.Sbc_HS_OC_OT_STAT & SBC_BITERROR_HS4_MASK) ) ? C_TRUE : C_FALSE );

    /* ANALYSIS_REPORT_END_JUSTIFICATION */

    /* Get High Side Activation status*/
    (void)Sbc_GetOutputRegValue(SBC_HS_CTRL1_ID, &HS_Ctrl1RegVal);
    (void)Sbc_GetOutputRegValue(SBC_HS_CTRL2_ID, &HS_Ctrl2RegVal);

    /* ANALYSIS_REPORT_START_JUSTIFICATION (2021/05/05: uidp6829) !-->
    TOOL_NUMBER(codecheck:S8) GUIDELINE(icr_201411:rule:c141) ? operation used for increasing readability. <--! */
    Sbc_HS_RetryStrategyData[SBC_HS_1].OutputState = Bool_To_Fsm_Bool( ( 0u != (HS_Ctrl1RegVal & SBC_HS_CTRL1_HS1_OUTPUT_MASK) ) ? C_TRUE : C_FALSE );
    Sbc_HS_RetryStrategyData[SBC_HS_2].OutputState = Bool_To_Fsm_Bool( ( 0u != (HS_Ctrl1RegVal & SBC_HS_CTRL1_HS2_OUTPUT_MASK) ) ? C_TRUE : C_FALSE );
    Sbc_HS_RetryStrategyData[SBC_HS_4].OutputState = Bool_To_Fsm_Bool( ( 0u != (HS_Ctrl2RegVal & SBC_HS_CTRL2_HS4_OUTPUT_MASK) ) ? C_TRUE : C_FALSE );

    /* ANALYSIS_REPORT_END_JUSTIFICATION */
    for(lub_SbcHSIndex = 0u; lub_SbcHSIndex < (uint8)SCB_SUPPORTED_HS; lub_SbcHSIndex++)
    {
        /* ANALYSIS_REPORT_JUSTIFICATION (2021/05/05: uidp6829) !-->
        TOOL_NUMBER(pclint:9030) GUIDELINE(MISRA_2012:rule:10.5) Cast to enumeration within the range of the enumeration value. Confirmed with condition above.
        TOOL_NUMBER(pclint:9034) GUIDELINE(MISRA_2012:rule:10.3) Cast to enumeration within the range of the enumeration value. Confirmed with condition above. <--! */
        Sbc_HS_RetryStrategySM[Sbc_HS_RetryStrategyData[lub_SbcHSIndex].State.ValDTU8]((SBC_HS_ID)lub_SbcHSIndex);
    }
    ResumeAllInterrupts();

}

static void Set_Sbc_HS_RetryStrategyData_DefaultValues(void)
{

    SuspendAllInterrupts();

    /* Retry enabled init value */
    Sbc_HS_RetryStrategyData[SBC_HS_1].RetryEnabled= FSM_TRUE;
    Sbc_HS_RetryStrategyData[SBC_HS_2].RetryEnabled= FSM_TRUE;
    Sbc_HS_RetryStrategyData[SBC_HS_4].RetryEnabled= FSM_FALSE;

    /* SbcHSId  init value */
    Sbc_HS_RetryStrategyData[SBC_HS_1].Sbc_HSOutputId.ValDTU8= (uint8)SBC_OUTPUT_HS1;
    Sbc_HS_RetryStrategyData[SBC_HS_2].Sbc_HSOutputId.ValDTU8= (uint8)SBC_OUTPUT_HS2;
    Sbc_HS_RetryStrategyData[SBC_HS_4].Sbc_HSOutputId.ValDTU8= (uint8)SBC_OUTPUT_HS4;
    Sbc_HS_RetryStrategyData[SBC_HS_1].Sbc_HSOutputId.InvDTU8= (uint8)~Sbc_HS_RetryStrategyData[SBC_HS_1].Sbc_HSOutputId.ValDTU8;
    Sbc_HS_RetryStrategyData[SBC_HS_2].Sbc_HSOutputId.InvDTU8= (uint8)~Sbc_HS_RetryStrategyData[SBC_HS_2].Sbc_HSOutputId.ValDTU8;
    Sbc_HS_RetryStrategyData[SBC_HS_4].Sbc_HSOutputId.InvDTU8= (uint8)~Sbc_HS_RetryStrategyData[SBC_HS_4].Sbc_HSOutputId.ValDTU8;

    /* State  init value */
    Sbc_HS_RetryStrategyData[SBC_HS_1].State.ValDTU8= (uint8)SBC_HS_RET_IDLE;
    Sbc_HS_RetryStrategyData[SBC_HS_2].State.ValDTU8= (uint8)SBC_HS_RET_IDLE;
    Sbc_HS_RetryStrategyData[SBC_HS_4].State.ValDTU8= (uint8)SBC_HS_RET_IDLE;
    Sbc_HS_RetryStrategyData[SBC_HS_1].State.InvDTU8= (uint8)~Sbc_HS_RetryStrategyData[SBC_HS_1].State.ValDTU8;
    Sbc_HS_RetryStrategyData[SBC_HS_2].State.InvDTU8= (uint8)~Sbc_HS_RetryStrategyData[SBC_HS_2].State.ValDTU8;
    Sbc_HS_RetryStrategyData[SBC_HS_4].State.InvDTU8= (uint8)~Sbc_HS_RetryStrategyData[SBC_HS_4].State.ValDTU8;


    /* OverloadDetected  init value */
    Sbc_HS_RetryStrategyData[SBC_HS_1].OverloadDetected= FSM_FALSE;
    Sbc_HS_RetryStrategyData[SBC_HS_2].OverloadDetected= FSM_FALSE;
    Sbc_HS_RetryStrategyData[SBC_HS_4].OverloadDetected= FSM_FALSE;

    /* OutState  init value */
    Sbc_HS_RetryStrategyData[SBC_HS_1].OutputState= FSM_FALSE;
    Sbc_HS_RetryStrategyData[SBC_HS_2].OutputState= FSM_FALSE;
    Sbc_HS_RetryStrategyData[SBC_HS_4].OutputState= FSM_FALSE;

    /* OvLdFlt  init value */
    Sbc_HS_RetryStrategyData[SBC_HS_1].OverloadFaultActive= FSM_FALSE;
    Sbc_HS_RetryStrategyData[SBC_HS_2].OverloadFaultActive= FSM_FALSE;
    Sbc_HS_RetryStrategyData[SBC_HS_4].OverloadFaultActive= FSM_FALSE;

    /* ReactvTimr  init value  */
    Sbc_HS_RetryStrategyData[SBC_HS_1].ReactivationTimer.ValDTU16= 0u;
    Sbc_HS_RetryStrategyData[SBC_HS_2].ReactivationTimer.ValDTU16= 0u;
    Sbc_HS_RetryStrategyData[SBC_HS_4].ReactivationTimer.ValDTU16= 0u;
    Sbc_HS_RetryStrategyData[SBC_HS_1].ReactivationTimer.InvDTU16= (uint16)~Sbc_HS_RetryStrategyData[SBC_HS_1].ReactivationTimer.ValDTU16;
    Sbc_HS_RetryStrategyData[SBC_HS_2].ReactivationTimer.InvDTU16= (uint16)~Sbc_HS_RetryStrategyData[SBC_HS_2].ReactivationTimer.ValDTU16;
    Sbc_HS_RetryStrategyData[SBC_HS_4].ReactivationTimer.InvDTU16= (uint16)~Sbc_HS_RetryStrategyData[SBC_HS_4].ReactivationTimer.ValDTU16;

    /* RecoveryTimer  init value  */
    Sbc_HS_RetryStrategyData[SBC_HS_1].RecoveryTimer.ValDTU16= 0u;
    Sbc_HS_RetryStrategyData[SBC_HS_2].RecoveryTimer.ValDTU16= 0u;
    Sbc_HS_RetryStrategyData[SBC_HS_4].RecoveryTimer.ValDTU16= 0u;
    Sbc_HS_RetryStrategyData[SBC_HS_1].RecoveryTimer.InvDTU16= (uint16)~Sbc_HS_RetryStrategyData[SBC_HS_1].RecoveryTimer.ValDTU16;
    Sbc_HS_RetryStrategyData[SBC_HS_2].RecoveryTimer.InvDTU16= (uint16)~Sbc_HS_RetryStrategyData[SBC_HS_2].RecoveryTimer.ValDTU16;
    Sbc_HS_RetryStrategyData[SBC_HS_4].RecoveryTimer.InvDTU16= (uint16)~Sbc_HS_RetryStrategyData[SBC_HS_4].RecoveryTimer.ValDTU16;

    /* RecoveryTimer  init value  */
    Sbc_HS_RetryStrategyData[SBC_HS_1].RetryCounter.ValDTU16= 0u;
    Sbc_HS_RetryStrategyData[SBC_HS_2].RetryCounter.ValDTU16= 0u;
    Sbc_HS_RetryStrategyData[SBC_HS_4].RetryCounter.ValDTU16= 0u;
    Sbc_HS_RetryStrategyData[SBC_HS_1].RetryCounter.InvDTU16= (uint16)~Sbc_HS_RetryStrategyData[SBC_HS_1].RetryCounter.ValDTU16;
    Sbc_HS_RetryStrategyData[SBC_HS_2].RetryCounter.InvDTU16= (uint16)~Sbc_HS_RetryStrategyData[SBC_HS_2].RetryCounter.ValDTU16;
    Sbc_HS_RetryStrategyData[SBC_HS_4].RetryCounter.InvDTU16= (uint16)~Sbc_HS_RetryStrategyData[SBC_HS_4].RetryCounter.ValDTU16;

    ResumeAllInterrupts();

}



uint8 FSM_SBC_High_Side_OCState(SBC_HS_ID HighSideId)
{
    uint8 Sbc_OC_OT;
    SuspendAllInterrupts();
    DataIntegrityCheck_FSM_Bool(&Sbc_HS_RetryStrategyData[HighSideId].OverloadFaultActive);

    if ((uint8)HighSideId < (uint8)SCB_SUPPORTED_HS) /* SWATT-coverage-line This condition is meant for development errors. This should never be false. */
    {
        Sbc_OC_OT = (uint8)Fsm_Bool_To_Bool_uint8(Sbc_HS_RetryStrategyData[HighSideId].OverloadFaultActive);
    }
    else
    {
        Sbc_OC_OT = (uint8)TRUE_UINT;
    }
    ResumeAllInterrupts();

    return Sbc_OC_OT;
}


