/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: FSM_Error_Reaction_Manager.c $
 * $Revision: 1.7 $
 * $Author: Cruz-EXT, Romanov (uie43239) (uie43239) $
 * $Date: 2022/09/02 21:14:19CEST $
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
/* COPYRIGHT (C) CONTINENTAL AUTOMOTIVE 2016                                  */
/* AUTOMOTIVE GROUP, Interior Division, Body and Security                     */
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
 * $Log: FSM_Error_Reaction_Manager.c  $
 * Revision 1.7 2022/09/02 21:14:19CEST Cruz-EXT, Romanov (uie43239) (uie43239) 
 * FSM Error Reaction Manager & PDR changes
 * Revision 1.6 2022/08/23 23:48:21CEST Flores-EXT, Christian0202 (uie43236) (uie43236) 
 * Update FSM Error Reaction Manager according to review comments
 * Revision 1.5 2022/08/02 20:57:04CEST Opiola, Thaddeus (uidu9036) 
 * Add code updastes that are needed in the Safety Arbitrator and code fixes for a build.
 * Revision 1.4 2022/08/01 20:38:12CEST Flores-EXT, Christian0202 (uie43236) (uie43236) 
 * Update for FSM Error Reaction Manager code
 * Revision 1.3 2022/07/29 21:20:07CEST Flores-EXT, Christian0202 (uie43236) (uie43236) 
 * Update FSM Error Reaction Manager to fit with Safety Arbitrator
 * Revision 1.13 2022/05/13 14:10:12CEST Opiola, Thaddeus (uidu9036) 
 * Check in fix for INIT RAM and other quaity improvements that were found in code review.
 * Revision 1.12 2022/05/05 06:32:08CEST Opiola, Thaddeus (uidu9036) 
 * Add correction for NON INIT RAM and fix Typo for FSM_SAFETY_GUARD_PLAUS_ERROR name
 * Revision 1.9 2022/04/30 00:59:55CEST Opiola, Thaddeus (uidu9036) 
 * Add all code review comments for FSM_Micro_Faults thus far.  Also some Qtools clean up from code reveiw comments on justifications and old ATOOL commest which don't belong.
 * Revision 1.8 2022/04/27 16:09:07CEST Opiola, Thaddeus (uidu9036) 
 * Add Updated review comments and QTOOLS fixes
 * Revision 1.7 2022/04/19 20:56:19CEST Mendez-EXT, Raul (uids3454) 
 * Updated FSM Safety Guard names
 * Revision 1.6 2022/04/08 21:33:04CEST Opiola, Thaddeus (uidu9036) 
 * Add code review comments to FSM_Task_Monitor.c/.h and other files.
 * Revision 1.5 2022/04/05 16:18:03CEST Opiola, Thaddeus (uidu9036) 
 * Add reviewed chenaged
 * Revision 1.4 2022/03/30 04:01:27CEST Opiola, Thaddeus (uidu9036) 
 * Add code changs need for SWATT updates plus some SW integration bug fixes.
 * Revision 1.3 2022/02/21 23:04:48CET Opiola, Thaddeus (uidu9036) 
 * Add final changes for RESET issue plus code review items for FSM Error Reaction manager.
 * Revision 1.2 2022/02/21 22:26:14CET Opiola, Thaddeus (uidu9036) 
 * Add other changes from SW Dev directory for FSM changes that were tested for NO RESET
 * Revision 1.1 2022/01/13 21:43:08CET Opiola, Thaddeus (uidu9036) 
 * Initial revision
 * Member added to project /BS/FCA_XX_21_DCU_ATL/Software/mc_sw/appl/f_fsm/f_fsm_error_reaction_manager/project.pj
 * Revision 1.7.1.4 2021/09/24 19:28:28CEST Opiola, Thaddeus (uidu9036) 
 * Check in SW Integration testing and improvements
 * Revision 1.7.1.3 2021/09/22 23:55:47CEST Fraustro-EXT, David (uid32234) 
 * Minor fix for an issue inducing a reset. 
 * Removed while trap since it doesn't provide much redundancy in safety
 * Revision 1.7.1.2 2021/09/15 08:37:31CEST Opiola, Thaddeus (uidu9036) 
 * Add corrections to Error Reaction for FSM Faults
 * Revision 1.7.1.1 2021/08/02 07:01:56CEST Tellez-EXT, Fernando02 (uie27682) (uie27682) 
 * Adding two new Nvm blocks for Error Reaction Manager and FD05 updates to retrieve error codes.
 * Revision 1.7 2021/07/22 13:55:59CEST Fraustro-EXT, David (uid32234) 
 * Merge with FSM branch
 * Revision 1.6.2.3 2021/07/10 06:17:34CEST Opiola, Thaddeus (uidu9036) 
 * Make neecessary debug updates from testing and review.
 * Revision 1.6.2.2 2021/07/09 07:56:00CEST Opiola, Thaddeus (uidu9036) 
 * More Inverse Ram Fixes for Error Reaction plus one Task Mon fix.
 * Revision 1.6.2.1 2021/07/09 00:09:16CEST Adukkathayar-EXT, Sreedevi (uie30029) (uie30029) 
 * check in: FSM Error Reaction implementation
 * Revision 1.6 2021/06/01 16:47:01CEST Opiola, Thaddeus (uidu9036) 
 * Fix build warning
 * Revision 1.5 2021/05/31 02:26:34CEST Opiola, Thaddeus (uidu9036) 
 * Add SW integration Changes for future improvements for FSM_Types.h and other SW integration changes.
 * Revision 1.4 2021/05/27 05:42:53CEST Opiola, Thaddeus (uidu9036) 
 * Add final chnages to the code updates based on code review comments and general improvements based on Conti Process.
 * Revision 1.3 2021/05/18 01:45:27CEST Delgadillo, Sergio (uidr3241) 
 * FSM Validate Brake
 * Revision 1.2 2021/05/17 18:23:30CEST Opiola, Thaddeus (uidu9036) 
 * Remove uneeded stubs
 * Revision 1.1 2021/05/16 00:07:05CEST Opiola, Thaddeus (uidu9036) 
 * Initial revision
 * Member added to project /BS/FCA_XXXX_21_TCM/Software/mc_sw/appl/FaultManager/src/project.pj
  ============================================================================*/
/* Includes */
/*============================================================================*/
/* ANALYSIS_REPORT_JUSTIFICATION (2022/10/04 : uie46352) !-->
   TOOL_NUMBER(PCLINT:537) GUIDELINE(N/A:N/A:N/A) Not an issue for quality project
 <--! */
#include "FSM_Error_Reaction_Manager.h"
#include "FSM_Error_Reaction_Manager_Nvm.h"
#include "FSM_Nvm_Supervisor.h"
#include "FSM_Nvm_Supervisor_cfg.h"
#include "FsmSafetyArbitrator.h"
#include "stdtypedef.h"
#include "NvM_Callbacks.h"
#include "FSM_Clock_PLL_Error.h"
#include "SchM_Mcu.h"
/* ANALYSIS_REPORT_JUSTIFICATION (2022/10/04 : uie46352) !-->
   TOOL_NUMBER(PCLINT:537) GUIDELINE(N/A:N/A:N/A) Not an issue for quality project
 <--! */
#include "WdgM.h"
#include "FSM_Unintended_Interrupts.h"

#ifndef SWATT_BYPASS
    /* ANALYSIS_REPORT_JUSTIFICATION (2022/10/02 : uie46352) !-->
   TOOL_NUMBER(PCLINT:9026) GUIDELINE(MISRA_2012:DIRECTIVE:4.9) This macro is used only by SWATT, no issue. RISK(No risk) RACT(Can't be improved)
   TOOL_NUMBER(PCLINT:961) GUIDELINE(MISRA_2004:RULE:19.7) This macro is used only by SWATT, no issue.          *
   TOOL_NUMBER(N/A:N/A) GUIDELINE(N/A:N/A:N/A) TOOL_NUMBER(*
 <--! */
#define SWATT_BYPASS(a,b)
#endif


/* Constants and types  */
/*============================================================================*/
/* Max number of possible FSM Faults */
#define FSM_MAX_NUMBER_ERRORS                           (33u)
/* All Fault bits that are used in the 32 bits of the error reaction data 32 bit word */
#define FSM_USED_ERROR_MASK ((uint32)                   \
((uint32)FSM_REDUNDANT_RAM_ERROR)|                      \
((uint32)FSM_ECC_DATA_FLASH_ERROR)|                     \
((uint32)FSM_ECC_PROGRAM_FLASH_ERROR)|                  \
((uint32)FSM_ECC_RAM_ERROR)|                            \
((uint32)FSM_REGMON_STACK_ERROR)|                       \
((uint32)FSM_REGMON_SYSREG_ERROR)|                      \
((uint32)FSM_REGMON_SAFETYREG_ERROR)|                   \
((uint32)FSM_REGMON_IO_REG_ERROR)|                      \
((uint32)FSM_WDGM_TASKSUPV_ERROR)|                      \
((uint32)FSM_CLOCK_ERROR)|                              \
((uint32)FSM_PLL_ERROR)|                                \
((uint32)FSM_IMPLAUSIBLE_VALUE)|                        \
((uint32)FSM_NVM_DATA_ERROR)|                           \
((uint32)FSM_UNUSED_INTERRUPT)|                         \
((uint32)FSM_MICRO_EXCEPTION)|                          \
((uint32)FSM_SBC_INIT_ERR)|                             \
((uint32)FSM_A2D_SELF_TEST_ERR)|                        \
((uint32)FSM_SG2_ANTI_PINCH_PLAUS_ERROR)|               \
((uint32)FSM_SG1_LIFGATE_AJAR_W_SPEED_PLAUS_ERROR)|     \
((uint32)FSM_CAN_COMM_VEH_SP_ERROR)|                    \
((uint32)FSM_CAN_COMM_CRANK_ERROR)|                     \
((uint32)FSM_CAN_COMM_CMD_ERROR)|                       \
((uint32)FSM_VOLTAGE_RANGE_ERR)|                        \
((uint32)FSM_ALU_CHECK_ERR)|                            \
((uint32)FSM_CANARY_STACK_ERROR)|                       \
((uint32)FSM_RAM_MARCH_TEST_ERR)|                       \
((uint32)FSM_HALL_SENSORS_FAILED)|                      \
((uint32)FSM_DIAG_STUCK_ERROR)                          )

/* All Fault bits that are unused  - for this program */
/* ANALYSIS_REPORT_START_JUSTIFICATION (2022/10/04 : uie46352) !-->
   TOOL_NUMBER(PCLINT:750) GUIDELINE(MISRA_2012:RULE:2.5) Not used at the moment, to be used later
 <--! */
#define FSM_UN_USED_ERROR_MASK ((uint32)                \
((uint32)FSM_ECC_PERIPHERAL_RAM_ERROR)|                 \
((uint32)FSM_UNUSED_30)|                                \
((uint32)FSM_UNUSED_31)|                                \
((uint32)FSM_RAM_TEST)                                  )
/* ANALYSIS_REPORT_END_JUSTIFICATION */

/* All Fault bits that have recoverable fault reaction - i.e. SW RESET */
#define FSM_REACTION_RECOVERABLE_MASK ((uint32)         \
((uint32)FSM_REDUNDANT_RAM_ERROR)|                       \
((uint32)FSM_REGMON_SYSREG_ERROR)|                       \
((uint32)FSM_REGMON_STACK_ERROR)|                        \
((uint32)FSM_REGMON_SAFETYREG_ERROR)|                    \
((uint32)FSM_REGMON_IO_REG_ERROR)|                       \
((uint32)FSM_WDGM_TASKSUPV_ERROR)|                       \
((uint32)FSM_IMPLAUSIBLE_VALUE)|                         \
((uint32)FSM_NVM_DATA_ERROR)|                            \
((uint32)FSM_UNUSED_INTERRUPT)|                          \
((uint32)FSM_SBC_INIT_ERR)|                              \
((uint32)FSM_A2D_SELF_TEST_ERR)|                         \
((uint32)FSM_ALU_CHECK_ERR)|                             \
((uint32)FSM_CANARY_STACK_ERROR)|                        \
((uint32)FSM_RAM_MARCH_TEST_ERR)                         )

/* All Fault bits that have NO RESET fault reaction - i.e. NO SW RESET */
#define FSM_REACTION_RECOVERABLE_NORESET_MASK ((uint32)  \
((uint32)FSM_SG2_ANTI_PINCH_PLAUS_ERROR)|                \
((uint32)FSM_SG1_LIFGATE_AJAR_W_SPEED_PLAUS_ERROR)|      \
((uint32)FSM_CAN_COMM_VEH_SP_ERROR)|                     \
((uint32)FSM_CAN_COMM_CRANK_ERROR)|                      \
((uint32)FSM_CAN_COMM_CMD_ERROR)|                        \
((uint32)FSM_VOLTAGE_RANGE_ERR)|                         \
((uint32)FSM_HALL_SENSORS_FAILED)|                       \
((uint32)FSM_DIAG_STUCK_ERROR)                           )

/* All Fault bits that have SWP RESET fault reaction - i.e. SW RESET performed by SWP */
#define FSM_REACTION_RECOVERABLE_SWP_RESET_MASK ((uint32)  \
((uint32)FSM_ECC_DATA_FLASH_ERROR)|                        \
((uint32)FSM_ECC_PROGRAM_FLASH_ERROR)|                     \
((uint32)FSM_ECC_RAM_ERROR)|                               \
((uint32)FSM_CLOCK_ERROR)|                                 \
((uint32)FSM_PLL_ERROR)|                                   \
((uint32)FSM_MICRO_EXCEPTION)                              )

/* Max count for FSM Error Frequency for each fault count stored in NVM - i.e. 65535 */
#define FSM_MAX_ERROR_COUNT                               (uint16)(0xFFFFU)
/* Reaction logic run in 10 ms Task so 2 Sec timer decremented by 10 ms */
#define FSM_ERROR_REACTION_TIMEOUT_DECREMENT              (10u) /* Milliseconds - note Decrement 10 since it runs in 10 ms task */
/* SW Reaction Hold time after FSM Safe State is held after RESET for any fault  */
#define FSM_ERROR_REACTION_TIMEOUT_SECONDS                (2u)  /* Reaction Timeout in seconds */
/* See definition above - SW Reaction Hold time after FSM Safe State is held after RESET for any fault  */
#define FSM_ERROR_REACTION_TIMEOUT_CFG                    (FSM_ERROR_REACTION_TIMEOUT_SECONDS * 1000u) /* 2s timeout */
/* NO INIT RAM CHECK pattern for Power Drop Out of POR  */
#define FSM_NO_INIT_RAM_HEADER_PATTERN                    ((uint32)0xAA55CC33U)



/* Variables */
/*============================================================================*/


#pragma ghs section bss=".fsm_no_init"
static Fsm_Error_Type FSM_Error_Reaction_NonInitRAM_Error;

/* Note FSM_Error_Reaction_NonInitRAM_Error_History_Count is QM and is only for Production Metric Data and analysis
 *      to be read out in a FD05 DID */

static uint16 FSM_Error_Reaction_NonInitRAM_Error_History_Count[RAM_FSM_ERROR_COUNT_DATA_SIZE];

static FSM_Uint32 NonInitRamPatternCheckValue;

#pragma ghs section bss = default

uint32 FSM_Error_Reaction_NVMShadowRam_Error;
uint16 FSM_Error_Reaction_NVMShadowRam_Error_History_Count[RAM_FSM_ERROR_COUNT_DATA_SIZE];

static FSM_Uint32 FSM_Error_Reaction_Reaction_Timeout = {0u, 0xFFFFFFFFu};
/* Private functions prototypes */
/*============================================================================*/
static void FSM_Update_NonInitRam_ShadowRam_Error_Count(Fsm_Error_Mask_Type Fsm_Error_Mask);
static void FSM_Update_NonInitRam_ShadowRam_Error ( const uint32 Fsm_Error_Update );
static void FSM_Set_Safe_State ( void );
static void FSM_Clear_Safe_State ( void );
static void FSM_Error_Reaction_Reset ( void );
static FSM_Error_Reaction_Type FSM_Get_Reaction_Cfg ( Fsm_Error_Mask_Type Error_Mask ); /*SWR_ERM_88*/
static void FSM_Clock_PLL_Reset_Determination (void);
static void FSM_Error_Reaction_Action_On_Init(void);
static void FSM_Error_Reaction_Recovery_Task_10ms(void);
static uint32 FSM_Get_Error_Reaction(void);



/* Inline functions */
/*============================================================================*/




/* Private functions */
/*============================================================================*/
/************************************************************************
 *  Name                 : FSM_Update_NonInitRam_Error_Count
 *  TAG                  :
 *  Description          : This function increments the error counter for the
 *                          passed error mask up to the maximum value
 *  Parameters           : Fsm_Error_Mask - index of error
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************************/
static void FSM_Update_NonInitRam_ShadowRam_Error_Count(Fsm_Error_Mask_Type Fsm_Error_Mask)
{
    uint8 Fsm_mask_position = 0U;

    uint32 Fsm_Error_Mask_Lcl;
    uint32 Fsm_Error_Mask_shift;

    /* SWATT test bypass do not delete */
    SWATT_BYPASS(FSM_Update_NonInitRam_ShadowRam_Error_Count, m_FSM_Update_NonInitRam_ShadowRam_Error_Count(Fsm_Error_Mask));

    SuspendAllInterrupts();


    /* ANALYSIS_REPORT_JUSTIFICATION (2022/01/09 : uidu9036) !-->
       TOOL_NUMBER(lint:960) MISRA(12.7) Bitwise operator is not be used with a type of signed.
       TOOL_NUMBER(lint:655) MISRA(N/A) This bit-wise operation is to remove unused faults, No Issue
     <--! */
    Fsm_Error_Mask_Lcl = (uint32)(((uint32)Fsm_Error_Mask) & ((uint32)FSM_USED_ERROR_MASK));
    Fsm_Error_Mask_shift = Fsm_Error_Mask_Lcl;

    Fsm_Error_Mask_shift >>= 1;
    while (Fsm_Error_Mask_shift > 0U) {
        Fsm_mask_position++;
        Fsm_Error_Mask_shift >>= 1;
    }

    if ( (0u < Fsm_Error_Mask_Lcl) &&
          (FSM_MAX_ERROR_COUNT > FSM_Error_Reaction_NVMShadowRam_Error_History_Count[Fsm_mask_position]) )
    {

        FSM_Error_Reaction_NVMShadowRam_Error_History_Count[Fsm_mask_position]++;

        FSM_Error_Reaction_NonInitRAM_Error_History_Count[Fsm_mask_position]++;

    }

    (void)NvM_WriteBlock(NvMBlock_FSM_Error_Reaction_History_Counters, &FSM_Error_Reaction_NVMShadowRam_Error_History_Count[0]);
    FSM_NvmSupv_Commit_to_NVM((uint8)FSM_ERROR_REACTION_FAULT_HISTORY_COUNT_INSTANCE);


    ResumeAllInterrupts();
}

/************************************************************************
 *  Name                 : FSM_Update_NonInitRam_Error
 *  TAG                  :
 *  Description          : This function updates the FSM Error and its
 *                          ones complement in NonInitRAM.
 *  Parameters           : Fsm_Error_Update - value to update to
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************************/
static void FSM_Update_NonInitRam_ShadowRam_Error ( const uint32 Fsm_Error_Update )
{

    /* SWATT test bypass do not delete */
    SWATT_BYPASS(FSM_Update_NonInitRam_ShadowRam_Error,m_FSM_Update_NonInitRam_ShadowRam_Error(Fsm_Error_Update));

    SuspendAllInterrupts();

    FSM_Error_Reaction_NVMShadowRam_Error = Fsm_Error_Update;

    FSM_Error_Reaction_NonInitRAM_Error.ValDTU32 = Fsm_Error_Update;
    FSM_Error_Reaction_NonInitRAM_Error.InvDTU32 = (uint32)~(FSM_Error_Reaction_NonInitRAM_Error.ValDTU32);

    ResumeAllInterrupts();
}

/************************************************************************
 *  Name                 : FSM_Set_Safe_State
 *  TAG                  :
 *  Description          : This function will send a SPI message to the SBC chip to place it into limp-home.
 *  Parameters           : none
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************************/
static void FSM_Set_Safe_State ( void )
{
    /* SWATT test bypass do not delete */
    SWATT_BYPASS(FSM_Set_Safe_State,m_FSM_Set_Safe_State());

#if SAFE_STATE_DEFINED_WITH_SBC_FO_LINE
    /* Note PCU serves as the SBC if used in the future
     * check interface from SWP
     */
    boolean FO_State;





#endif
    SuspendAllInterrupts();

    FsmSafetyGuard1F_Latch_Ghost_Driver_Cmd(E_FSMSAFETYGUARD1_FSM_MICRO_CHECKS_ERROR_CMD, E_FSMSAFETYGUARD_GHOST_DRIVER_CMD_RESET);
    FsmSafetyGuard2F_Spindle_Ghost_Driver_Cmd(E_FSMSAFETYGUARD2_FSM_MICRO_CHECKS_ERROR_CMD, E_FSMSAFETYGUARD_GHOST_DRIVER_CMD_RESET);

#if SAFE_STATE_DEFINED_WITH_SBC_FO_LINE
    /* Note PCU serves as the SBC if used in the future
         * check interface from SWP
         */
    boolean FO_State = TRUE;

    /* Set FO1 H/W pin to inactive */
    (void)Sbc_ChangeFOState(&FO_State);
#endif

    ResumeAllInterrupts();
}

/************************************************************************
 *  Name                 : FSM_Clear_Safe_State
 *  TAG                  :
 *  Description          : This function will send a SPI message to the SBC chip to clear limp-home.
 *  Parameters           : none
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************************/
static void FSM_Clear_Safe_State ( void )
{

#if SAFE_STATE_DEFINED_WITH_SBC_FO_LINE
    /* Note PCU serves as the SBC if used in the future
         * check interface from SWP
         */
    boolean FO_State = FALSE;
#endif

    /* SWATT test bypass do not delete */
    SWATT_BYPASS(FSM_Clear_Safe_State,m_FSM_Clear_Safe_State());

    SuspendAllInterrupts();

    FsmSafetyGuard1F_Latch_Ghost_Driver_Cmd(E_FSMSAFETYGUARD1_FSM_MICRO_CHECKS_ERROR_CMD, E_FSMSAFETYGUARD_GHOST_DRIVER_CMD_NORMAL_OPERATION);  /*SWR_ERM_46*/
    FsmSafetyGuard2F_Spindle_Ghost_Driver_Cmd(E_FSMSAFETYGUARD2_FSM_MICRO_CHECKS_ERROR_CMD, E_FSMSAFETYGUARD_GHOST_DRIVER_CMD_NORMAL_OPERATION);

#if SAFE_STATE_DEFINED_WITH_SBC_FO_LINE


    /* Note PCU serves as the SBC if used in the future
         * check interface from SWP
         */
    (void)Sbc_ChangeFOState(&FO_State);

#endif


    ResumeAllInterrupts();

}

/************************************************************************
 *  Name                 : FSM_Error_Reaction_Reset
 *  TAG                  :
 *  Description          : This function will force the system to the safe state and call Mcu_PerformReset to perform a RESET.
 *                         The Mcu_PerformReset function call has an infinite while loop call after if it,
 *                         so if it fails to reset the micro a watchdog time out will occur based off an infinite while call � added for extra safety.
 *  Parameters           : none
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************************/
static void FSM_Error_Reaction_Reset ( void )
{

    /* SWATT test bypass do not delete */
    SWATT_BYPASS(FSM_Error_Reaction_Reset,m_FSM_Error_Reaction_Reset());

    SuspendAllInterrupts();

    FSM_Set_Safe_State();
    /* Generate Reset */

    Mcu_PerformReset();

    /* force a watchdog reset if the above function doesn't cause a reset. - REMOVE SINCE WON't COMPILE wiyh ICA Compiler */


    ResumeAllInterrupts();
}

/************************************************************************
 *  Name                 : FSM_Get_Reaction_Cfg
 *  TAG                  :
 *  Description          : This function returns the value of the reaction configuration
 *                          for the mask passed.
 *  Parameters           : Error_Mask
 *  Return               : FSM_Error_Reaction_Type
 *  Critical/explanation : no
 **************************************************************************/
static FSM_Error_Reaction_Type FSM_Get_Reaction_Cfg ( Fsm_Error_Mask_Type Error_Mask )
{
    uint8 indx;
    FSM_Error_Reaction_Type Error_Reaction_lcl;

    const FSM_Error_Reaction_Struct_Type Error_Reaction_Lookup_Table[FSM_MAX_NUMBER_ERRORS] = {
                    {FSM_REDUNDANT_RAM_ERROR,                  REACTION_RECOVERABLE            },
                    {FSM_ECC_DATA_FLASH_ERROR,                 REACTION_RECOVERABLE_SWP_RESET  },
                    {FSM_ECC_PROGRAM_FLASH_ERROR,              REACTION_RECOVERABLE_SWP_RESET  },
                    {FSM_ECC_RAM_ERROR,                        REACTION_RECOVERABLE_SWP_RESET  },
                    {FSM_ECC_PERIPHERAL_RAM_ERROR,             REACTION_RECOVERABLE_SWP_RESET  },
                    {FSM_REGMON_STACK_ERROR,                   REACTION_RECOVERABLE            },
                    {FSM_REGMON_SYSREG_ERROR,                  REACTION_RECOVERABLE            },
                    {FSM_REGMON_SAFETYREG_ERROR,               REACTION_RECOVERABLE            },
                    {FSM_REGMON_IO_REG_ERROR,                  REACTION_RECOVERABLE            },
                    {FSM_WDGM_TASKSUPV_ERROR,                  REACTION_RECOVERABLE            },
                    {FSM_CLOCK_ERROR,                          REACTION_RECOVERABLE_SWP_RESET  },
                    {FSM_PLL_ERROR,                            REACTION_RECOVERABLE_SWP_RESET  },
                    {FSM_IMPLAUSIBLE_VALUE,                    REACTION_RECOVERABLE            },
                    {FSM_NVM_DATA_ERROR,                       REACTION_RECOVERABLE            },
                    {FSM_UNUSED_INTERRUPT,                     REACTION_RECOVERABLE            },
                    {FSM_MICRO_EXCEPTION,                      REACTION_RECOVERABLE_SWP_RESET  },
                    {FSM_RAM_TEST,                             REACTION_RECOVERABLE            },
                    {FSM_SBC_INIT_ERR,                         REACTION_RECOVERABLE            },
                    {FSM_A2D_SELF_TEST_ERR,                    REACTION_RECOVERABLE            },
                    {FSM_SG2_ANTI_PINCH_PLAUS_ERROR,           REACTION_RECOVERABLE_NORESET    },
                    {FSM_SG1_LIFGATE_AJAR_W_SPEED_PLAUS_ERROR, REACTION_RECOVERABLE_NORESET    },
                    {FSM_CAN_COMM_VEH_SP_ERROR,                REACTION_RECOVERABLE_NORESET    },
                    {FSM_CAN_COMM_CRANK_ERROR,                 REACTION_RECOVERABLE_NORESET    },
                    {FSM_CAN_COMM_CMD_ERROR,                   REACTION_RECOVERABLE_NORESET    },
                    {FSM_VOLTAGE_RANGE_ERR,                    REACTION_RECOVERABLE_NORESET    },
                    {FSM_ALU_CHECK_ERR,                        REACTION_RECOVERABLE            },
                    {FSM_CANARY_STACK_ERROR,                   REACTION_RECOVERABLE            },
                    {FSM_RAM_MARCH_TEST_ERR,                   REACTION_RECOVERABLE            },
                    {FSM_HALL_SENSORS_FAILED,                  REACTION_RECOVERABLE_NORESET    },
                    {FSM_DIAG_STUCK_ERROR,                     REACTION_RECOVERABLE_NORESET    },
                    {FSM_UNUSED_30,                            REACTION_RECOVERABLE_NORESET    },
                    {FSM_UNUSED_31,                            REACTION_RECOVERABLE_NORESET    },
                    {FSM_NO_ERROR,                             REACTION_RECOVERABLE_NORESET    } };

    /* SWATT test bypass do not delete */
    SWATT_BYPASS(FSM_Get_Reaction_Cfg,m_FSM_Get_Reaction_Cfg(Error_Mask));


    SuspendAllInterrupts();

    Error_Reaction_lcl = REACTION_RECOVERABLE_NORESET;

    for( indx = 0U; indx < (uint8)FSM_MAX_NUMBER_ERRORS; indx++ )
    {

        if ( Error_Reaction_Lookup_Table[indx].Error_Mask == Error_Mask)
        {
            break;
        }
    }
    if ( indx < FSM_MAX_NUMBER_ERRORS)
    {
        Error_Reaction_lcl = Error_Reaction_Lookup_Table[indx].Reaction_Type;
    }

    ResumeAllInterrupts();

    return Error_Reaction_lcl;
}

/************************************************************************
 *  Name                 : FSM_Clock_PLL_Reset_Determination
 *  TAG                  :
 *  Description          : This function determines if the reset was caused
 *                          by one of the Clocks or the PLL and set the
 *                          corresponding error in the FSM_Error
 *  Parameters           : none
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************************/
static void FSM_Clock_PLL_Reset_Determination (void)
{

    /* TODO: Update proper reset reason function case elements */
    SWATT_BYPASS(FSM_Clock_PLL_Reset_Determination, m_FSM_Clock_PLL_Reset_Determination());

    SuspendAllInterrupts();

    FS_Clock_PLL_Reset_Determination();/*SWR_ERM_46*/
    /* NOTE AT MOMENT NOT SUPPORTED IN BASIC SW - SWP Task Monitoring is being used instead */

    ResumeAllInterrupts();
}

/************************************************************************
 *  Name                 : FSM_Error_Reaction_Action_On_Init
 *  TAG                  :
 *  Description          : This function gets called once during ITCM initialization.
 *                          It checks if any FSM Errors are present.
 *                          If the errors that are present are Recoverable, Recoverable-NoReset,
 *                          and Recoverable-SWP-Reset the system is left in Limp-Home
 *                          and the count down counter is initialized.
 *  Parameters           : none
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************************/
static void FSM_Error_Reaction_Action_On_Init(void)
{
    uint32 Errors;

    /* SWATT test bypass do not delete */
    SWATT_BYPASS(FSM_Error_Reaction_Action_On_Init, m_FSM_Error_Reaction_Action_On_Init());
    SuspendAllInterrupts();

    Errors = FSM_Get_Error_Reaction();


    /* ANALYSIS_REPORT_JUSTIFICATION (2022/01/09 : uidu9036) !-->
       TOOL_NUMBER(lint:655) MISRA(N/A) This bit-wise operation is to remove unused faults, No Issue
       TOOL_NUMBER(lint:960) MISRA(12.7) Bitwise operator is not be used with a type of signed
     <--! */
    if ( ( ( Errors & (uint32)FSM_USED_ERROR_MASK )  != 0u ) )
    {
        /* ANALYSIS_REPORT_JUSTIFICATION (2022/01/09 : uidu9036) !-->
           TOOL_NUMBER(lint:522) MISRA(14.2) No side effects from null statement.
         <--! */
        FSM_Set_Safe_State();
        FSM_Error_Reaction_Reaction_Timeout.ValDTU32 = (uint32)FSM_ERROR_REACTION_TIMEOUT_CFG;
        FSM_Error_Reaction_Reaction_Timeout.InvDTU32 = (uint32) ~(FSM_Error_Reaction_Reaction_Timeout.ValDTU32);
    }
    else
    {
        FSM_Error_Reaction_Reaction_Timeout.ValDTU32 = 0u;
        FSM_Error_Reaction_Reaction_Timeout.InvDTU32 = (uint32) ~(FSM_Error_Reaction_Reaction_Timeout.ValDTU32);
    }

    ResumeAllInterrupts();
}


/* Exported functions */
/*============================================================================*/
/************************************************************************
 *  Description          : This function updates updates the NVMShadowRam_Block with NonInitRam data
 *  Parameters           : none
 *  Return               : none
 **************************************************************************/
void FSM_Error_Reaction_Update_NVMShadowRam(void)
{
    SuspendAllInterrupts();
    FSM_Error_Reaction_NVMShadowRam_Error = FSM_Get_Error_Reaction();
    ResumeAllInterrupts();
}


/************************************************************************
 *  Description          : This function updates updates the NVMShadowRam_Block for 
 *                         the History Count with  the NonInitRam data
 *  Parameters           : none
 *  Return               : none
 **************************************************************************/
void FSM_Error_Reaction_Update_NVMShadowRam_History_Count(void)
{
    uint8 history_index;

    SuspendAllInterrupts();

    for(history_index = 0u; history_index < (uint8)FSM_MAX_NUMBER_ERRORS; history_index++)
    {
        FSM_Error_Reaction_NVMShadowRam_Error_History_Count[history_index] = 
		                        FSM_Error_Reaction_NonInitRAM_Error_History_Count[history_index];
    }

    ResumeAllInterrupts();
}

/************************************************************************
 *  Name                 : FSM_Get_Error_Reaction
 *  TAG                  :
 *  Description          : This function returns the Microprocessor FSM Error,
 *                          If the data in NonInit RAM is correct it will use it from NonInit RAM,
 *                          else it checks the values in NVM if correct it use it from NVM,
 *                          Otherwise it sets the Error to FSM_REDUNDANT_RAM_ERROR. It then updates
 *                          the values in NonInit RAM and NVM and returns the FSM_Error.
 *  Parameters           : none
 *  Return               : uint32 Valid FSM Error
 *  Critical/explanation : no
 **************************************************************************/
static uint32 FSM_Get_Error_Reaction (void)
{
    uint32 Fsm_Error_lcl;
    uint8 history_index;

    /* SWATT test bypass do not delete */
    SWATT_BYPASS(FSM_Get_Error_Reaction, m_FSM_Get_Error_Reaction());

    SuspendAllInterrupts();

    /* Note DataIntegrityCheck_FSM_Uint32(&NonInitRamPatternCheckValue) must be done at RUN TIME
     * NOT INIT because varible is used to check if NO INIT RAM is corrupt by POR
     */
    Fsm_Error_lcl = (uint32)FSM_NO_ERROR;


    /* NON INIT RAM is Corrupt due to Power Cycle */
    if( (FSM_NO_INIT_RAM_HEADER_PATTERN != NonInitRamPatternCheckValue.ValDTU32) ||
        ( (uint32)~(FSM_NO_INIT_RAM_HEADER_PATTERN) != NonInitRamPatternCheckValue.InvDTU32) )
    {
        /* RESET Pattern Check */
        NonInitRamPatternCheckValue.ValDTU32 = FSM_NO_INIT_RAM_HEADER_PATTERN;
        NonInitRamPatternCheckValue.InvDTU32 = (uint32)~(NonInitRamPatternCheckValue.ValDTU32);

        /* Clear Error Bit Memory */
        FSM_Error_Reaction_NonInitRAM_Error.ValDTU32 = 0U;
        FSM_Error_Reaction_NonInitRAM_Error.InvDTU32 = (uint32)~(FSM_Error_Reaction_NonInitRAM_Error.ValDTU32);

        /* Clear Error History Count */
        for(history_index = 0u; history_index < (uint8)RAM_FSM_ERROR_COUNT_DATA_SIZE; history_index++)
        {
           FSM_Error_Reaction_NonInitRAM_Error_History_Count[history_index] = 0U;
        }

        ReinitializeNVMCommitStatus();
        ReinitializeUnintentdedInterrupts();
/*         FSM_RegMon_ClearNoInitRAM();  TODO - Integrate Register Monitoring */
        FsmSafetyGuardF_Reinitialize_Ghost_Driver_Commmand_Arbitration_Info();

        Fsm_Error_lcl = FSM_Error_Reaction_NonInitRAM_Error.ValDTU32;
    }
    /* FSM_Error_Reaction_NonInitRAM_Error is NOT CORRUPT - ERROR is what is SET or NO ERROR */
    else if (FSM_Error_Reaction_NonInitRAM_Error.ValDTU32 == (uint32)~( FSM_Error_Reaction_NonInitRAM_Error.InvDTU32 ) )
    {
        /* This IF statement makes debugging eaiser and code a bit more readable. */
        if ((uint32)FSM_NO_ERROR != FSM_Error_Reaction_NonInitRAM_Error.ValDTU32 )
        {
            Fsm_Error_lcl = FSM_Error_Reaction_NonInitRAM_Error.ValDTU32;
        }
        else
        {
            /*  No error detected */
            Fsm_Error_lcl = (uint32)FSM_NO_ERROR;
        }
    }

    /* If all checks fail - then NO INIT FSM  VARIABLE CORRUPT set INVERVER RAM ERROR */
    else
    {
        Fsm_Error_lcl = (uint32)FSM_REDUNDANT_RAM_ERROR;
    }

    FSM_Update_NonInitRam_ShadowRam_Error ( Fsm_Error_lcl );

    ResumeAllInterrupts();

    return Fsm_Error_lcl;
}


/************************************************************************
 *  Name                 : FSM_Set_Error_Reaction
 *  TAG                  :
 *  Description          : This function updates the bit in the Microprocessor
 *                          FSM Error based on the passed mask if the
 *                          error in not disabled. It then will update the error
 *                          count for the passed mask. It then updates the
 *                          FSM Error in NonInitRam and NVM. It then determines
 *                          if the mask passed needs to force the system to go to safe
 *                          state and reset.
 *  Parameters           : Fsm_Error_Mask
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************************/
void FSM_Set_Error_Reaction(const Fsm_Error_Mask_Type Fsm_Error_Mask)
{

    FSM_Error_Reaction_Type Reaction_Config_lcl;

    Fsm_Error_Mask_Type Fsm_Error_Mask_Lcl;

    uint32 Fsm_Error_Lcl;

    SuspendAllInterrupts();

    switch (Fsm_Error_Mask)
    {
        case FSM_REDUNDANT_RAM_ERROR:
        case FSM_ECC_DATA_FLASH_ERROR:
        case FSM_ECC_PROGRAM_FLASH_ERROR:
        case FSM_ECC_RAM_ERROR:
        case FSM_ECC_PERIPHERAL_RAM_ERROR:
        case FSM_REGMON_STACK_ERROR:
        case FSM_REGMON_SYSREG_ERROR:
        case FSM_REGMON_SAFETYREG_ERROR:
        case FSM_REGMON_IO_REG_ERROR:
        case FSM_WDGM_TASKSUPV_ERROR:
        case FSM_CLOCK_ERROR:
        case FSM_PLL_ERROR:
        case FSM_IMPLAUSIBLE_VALUE:
        case FSM_NVM_DATA_ERROR:
        case FSM_UNUSED_INTERRUPT:
        case FSM_MICRO_EXCEPTION:
        case FSM_RAM_TEST:
        case FSM_SBC_INIT_ERR:
        case FSM_A2D_SELF_TEST_ERR:
        case FSM_SG2_ANTI_PINCH_PLAUS_ERROR:
        case FSM_SG1_LIFGATE_AJAR_W_SPEED_PLAUS_ERROR:
        case FSM_CAN_COMM_VEH_SP_ERROR:
        case FSM_CAN_COMM_CRANK_ERROR:
        case FSM_CAN_COMM_CMD_ERROR:
        case FSM_VOLTAGE_RANGE_ERR:
        case FSM_ALU_CHECK_ERR:
        case FSM_CANARY_STACK_ERROR:
        case FSM_RAM_MARCH_TEST_ERR:
        case FSM_HALL_SENSORS_FAILED:
        case FSM_DIAG_STUCK_ERROR:
            Fsm_Error_Mask_Lcl = Fsm_Error_Mask;
            break;
        case FSM_UNUSED_30:
        case FSM_UNUSED_31:
        case FSM_NO_ERROR:
        default:
            Fsm_Error_Mask_Lcl = FSM_IMPLAUSIBLE_VALUE;
            break;
    }

    Fsm_Error_Lcl = (uint32)(FSM_Get_Error_Reaction() | (uint32)Fsm_Error_Mask_Lcl);

    FSM_Update_NonInitRam_ShadowRam_Error_Count(Fsm_Error_Mask_Lcl);

    (void)NvM_WriteBlock(NvMBlock_FSM_Error_Reaction_History_Counters,&FSM_Error_Reaction_NVMShadowRam_Error_History_Count[0]);
    FSM_NvmSupv_Commit_to_NVM((uint8)FSM_ERROR_REACTION_FAULT_HISTORY_COUNT_INSTANCE);

    FSM_Update_NonInitRam_ShadowRam_Error(Fsm_Error_Lcl);

    (void)NvM_WriteBlock(NvMBlock_FSM_Error_ReactionErrorBits,&FSM_Error_Reaction_NVMShadowRam_Error);
    FSM_NvmSupv_Commit_to_NVM((uint8)FSM_ERROR_REACTION_FAULT_INSTANCE);


    Reaction_Config_lcl = FSM_Get_Reaction_Cfg((Fsm_Error_Mask_Type)Fsm_Error_Mask_Lcl);

    if ( ( REACTION_RECOVERABLE == Reaction_Config_lcl ) )
    {
        FSM_Error_Reaction_Reaction_Timeout.ValDTU32 = 0u;
        FSM_Error_Reaction_Reaction_Timeout.InvDTU32 = (uint32) ~(FSM_Error_Reaction_Reaction_Timeout.ValDTU32);

        FSM_Set_Safe_State();
    }

    ResumeAllInterrupts();

}

/************************************************************************
 *  Name                 : FSM_Error_Reaction_Recovery_Task
 *  TAG                  :
 *  Description          : This function gets called every 10ms and check if the
 *                          recoverable error timeout has occured. If the timeout
 *                          has occured, all errors are cleared the FSM Error
 *                          is updated and the limp-home state is exited.
 *  Parameters           : none
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************************/
static void FSM_Error_Reaction_Recovery_Task_10ms(void)
{
    uint32 Fsm_Error_Lcl;
    uint32 Error_2_Clear;

    /* SWATT test bypass do not delete */
    SWATT_BYPASS(FSM_Error_Reaction_Recovery_Task_10ms, m_FSM_Error_Reaction_Recovery_Task_10ms());

    SuspendAllInterrupts();

    Fsm_Error_Lcl = FSM_Get_Error_Reaction();

    /* Check if counter is greater than zero and validity of PRAM */
    /* PRAM is not valid */
    DataIntegrityCheck_FSM_Uint32(&FSM_Error_Reaction_Reaction_Timeout);

    if ( FSM_Error_Reaction_Reaction_Timeout.ValDTU32 != 0u )
    {

        /* PRAM was valid and counter not zero, decrement counter */
        if( FSM_Error_Reaction_Reaction_Timeout.ValDTU32 >= FSM_ERROR_REACTION_TIMEOUT_DECREMENT )
        {
            FSM_Error_Reaction_Reaction_Timeout.ValDTU32 -= FSM_ERROR_REACTION_TIMEOUT_DECREMENT;
            FSM_Error_Reaction_Reaction_Timeout.InvDTU32 += FSM_ERROR_REACTION_TIMEOUT_DECREMENT;
        }
        else
        {
            FSM_Error_Reaction_Reaction_Timeout.ValDTU32 = 0u;
            FSM_Error_Reaction_Reaction_Timeout.InvDTU32 = (uint32)~( FSM_Error_Reaction_Reaction_Timeout.ValDTU32 );
        }
        /* Counter is zero clear Micro_Integrity_Fault, exit safe state */
        if( FSM_Error_Reaction_Reaction_Timeout.ValDTU32 == 0u )
        {
            Error_2_Clear = Fsm_Error_Lcl & FSM_REACTION_RECOVERABLE_NORESET_MASK;
            FSM_Update_NonInitRam_ShadowRam_Error(Error_2_Clear);
            (void)NvM_WriteBlock(NvMBlock_FSM_Error_ReactionErrorBits,&FSM_Error_Reaction_NVMShadowRam_Error);
            FSM_NvmSupv_Commit_to_NVM((uint8)FSM_ERROR_REACTION_FAULT_INSTANCE);

            FSM_Clear_Safe_State();
        }
    }
    else
    {
        if ( ( 0u != ( Fsm_Error_Lcl & (uint32)FSM_REACTION_RECOVERABLE_MASK ) ) )
        {
            (void)NvM_WriteBlock(NvMBlock_FSM_Error_ReactionErrorBits,&FSM_Error_Reaction_NVMShadowRam_Error);
            FSM_NvmSupv_Commit_to_NVM((uint8)FSM_ERROR_REACTION_FAULT_INSTANCE);

            FSM_Error_Reaction_Reset();
        }
        else
        {
            if ( 0u != ( Fsm_Error_Lcl & (uint32)FSM_REACTION_RECOVERABLE_SWP_RESET_MASK  ) )
            {
                FSM_Error_Reaction_Reaction_Timeout.ValDTU32 = (uint32)FSM_ERROR_REACTION_TIMEOUT_CFG;
                FSM_Error_Reaction_Reaction_Timeout.InvDTU32 = (uint32) ~(FSM_Error_Reaction_Reaction_Timeout.ValDTU32);
            }
        }
    }
    /* Adding call to task supervision module */
    ResumeAllInterrupts();
}

/************************************************************************
 *  Name                 : FSM_Clear_Error_Reaction_Recoverable_No_Reset
 *  TAG                  :
 *  Description          : This function clears FSM errors of type
 *                         FSM_REACTION_RECOVERABLE_NORESET_MASK which are usually
 *                         cleared by SW Application or Safety Gaurd code.
 *  Parameters           : Fsm_Error_Mask
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************************/
void FSM_Clear_Error_Reaction_Recoverable_No_Reset(const Fsm_Error_Mask_Type Fsm_Error_Mask)
{


    SuspendAllInterrupts();
    /* Clear FSM_REACTION_RECOVERABLE_NORESET Error */

    if((Fsm_Error_Mask & FSM_REACTION_RECOVERABLE_NORESET_MASK) != 0U)
    {
        FSM_Error_Reaction_NonInitRAM_Error.ValDTU32 &= (uint32)~(Fsm_Error_Mask);
        FSM_Error_Reaction_NonInitRAM_Error.InvDTU32 = (uint32)~(FSM_Error_Reaction_NonInitRAM_Error.ValDTU32);
    }


    ResumeAllInterrupts();
}

/************************************************************************
 *  Name                 : FSM_Error_Reaction_Init
 *  TAG                  :
 *  Description          : This function gets called in initialization and calls necessary functions
 *  Parameters           : None
 *  Return               : None
 *  Critical/explanation : no
 **************************************************************************/
void FSM_Error_Reaction_Init( void )
{
    SuspendAllInterrupts();

    /* make sure Micro_Integrity Fault is valid */
    (void) FSM_Get_Error_Reaction();


    (void)NvM_WriteBlock(NvMBlock_FSM_Error_ReactionErrorBits,&FSM_Error_Reaction_NVMShadowRam_Error);

     FSM_NvmSupv_Commit_to_NVM((uint8)FSM_ERROR_REACTION_FAULT_INSTANCE);

    /* Check if Reset was caused by Clock */
    FSM_Clock_PLL_Reset_Determination();
    /* perform fault reaction */
    FSM_Error_Reaction_Action_On_Init();

    ResumeAllInterrupts();
}

/************************************************************************
 *  Name                 : FSM_Error_Reaction_Task_10ms
 *  TAG                  :
 *  Description          : Main task for calling all the 10ms related functions
 *  Parameters           : void
 *  Return               : void
 *  Critical/explanation : no
 **************************************************************************/
void FSM_Error_Reaction_Task_10ms(void)
{
    SuspendAllInterrupts();


    DataIntegrityCheck_FSM_Uint32(&FSM_Error_Reaction_NonInitRAM_Error);
    DataIntegrityCheck_FSM_Uint32(&NonInitRamPatternCheckValue);
    FSM_Error_Reaction_Recovery_Task_10ms();

   (void)WdgM_UpdateAliveCounter((WdgM_SupervisedEntityIdType) SE_FSM_ERROR_REACTION_RECOVERY_TASK);

    ResumeAllInterrupts();
}
