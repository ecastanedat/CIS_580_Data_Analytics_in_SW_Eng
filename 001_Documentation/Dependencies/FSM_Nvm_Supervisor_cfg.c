/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: FSM_Nvm_Supervisor_cfg.c $
 * $Revision: 1.3 $
 * $Author: Robles-EXT, Jorge02 (uie46352) (uie46352) $
 * $Date: 2022/09/09 22:18:21CEST $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    Configuration parameters for supporting FSM Nvm Supervisor logic.
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
 * $Log: FSM_Nvm_Supervisor_cfg.c  $
 * Revision 1.3 2022/09/09 22:18:21CEST Robles-EXT, Jorge02 (uie46352) (uie46352) 
 * Adding the Circular Buffer Register Monitor for NvM
 * Revision 1.2 2022/07/29 20:55:42CEST Cruz-EXT, Romanov (uie43239) (uie43239) 
 * Port of NVM Supervisor Code
 * Revision 1.4 2022/04/30 00:59:36CEST Opiola, Thaddeus (uidu9036) 
 * Add all code recview comment fixes  and QTOOLS Justification corerctions for QTOOLS for correct format and clean out old QTOOLS comments which do NOT apply.
 * Revision 1.3 2022/04/28 15:42:23CEST Opiola, Thaddeus (uidu9036) 
 * Fix all QTOOLS errors.  Most of errors are becuase QTOOLS QTOOLS ANALYSIS_REPORT_JUSTIFICATION fronm ideas does not match QTOOLS format so K2 metrics are showing high.
 * Revision 1.2 2022/02/21 22:26:16CET Opiola, Thaddeus (uidu9036) 
 * Add other changes from SW Dev directory for FSM changes that were tested for NO RESET
 * Revision 1.1 2022/01/13 21:45:26CET Opiola, Thaddeus (uidu9036) 
 * Initial revision
 * Member added to project /BS/FCA_XX_21_DCU_ATL/Software/mc_sw/appl/f_fsm/f_fsm_nvm_supervisor/project.pj
 * Revision 1.2 2021/09/15 08:37:31CEST Opiola, Thaddeus (uidu9036) 
 * Add corrections to Error Reaction for FSM Faults
 * Revision 1.1 2021/08/02 06:59:45CEST Tellez-EXT, Fernando02 (uie27682) (uie27682) 
 * Initial revision
 * Member added to project /BS/FCA_XXXX_21_TCM/Software/mc_sw/appl/FaultManager/src/project.pj
 * Revision 1.1.1.2 2021/08/01 21:24:09CEST Tellez-EXT, Fernando02 (uie27682) (uie27682) 
 * Initial revision
 * Member added to project /BS/FCA_XXXX_21_TCM/Software/mc_sw/appl/AdditionalSafetyMeasures/ErrorReactionManager/Source/project.pj
 * Revision 1.1 2021/07/30 17:47:24CEST Tellez-EXT, Fernando02 (uie27682) (uie27682) 
 * Initial revision
 * Member added to project /BS/FCA_XXXX_21_TCM/Software/mc_sw/appl/AdditionalSafetyMeasures/ErrorReactionManager/Source/project.pj
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "FSM_Nvm_Supervisor_cfg.h"
#include "FSM_Nvm_Supervisor.h"
#include "FSM_Error_Reaction_Manager_Nvm.h"
#include "Nvm_Cfg.h"
#include "FSM_Register_Monitor.h"
#include "FSM_Exception_Handlers.h"
#include "FSM_WdgMApp_Task_Monitor.h"

#ifndef FSM_REGISTER_MONITOR_TYPE_H      /* To avoid double inclusion */
#include "FSM_Register_Monitor_type.h"
#endif  /* FSM_REGISTER_MONITOR_TYPE_H */



/* Constants and types  */
/*============================================================================*/
const FS_Nvm_Commit_Instance_Type FS_Nvm_Commit_Instance[FSM_NUM_OF_INSTANCES_COMMITTED_TO_NVM_STATUS] =
{//update shad ram 1st 2 col
    /* Block_ID                                        Shadow_Address                                         On_Commit Function                   Init_Shadow RAM from Functon                        */
    {  (uint8)NvMBlock_FSM_Error_ReactionErrorBits         ,&FSM_Error_Reaction_NVMShadowRam_Error                   ,FSM_NvmSupv_Do_Nothing             ,FSM_Error_Reaction_Update_NVMShadowRam                },
    {  (uint8)NvMBlock_FSM_Error_Reaction_History_Counters ,&FSM_Error_Reaction_NVMShadowRam_Error_History_Count[0]  ,FSM_NvmSupv_Do_Nothing             ,FSM_Error_Reaction_Update_NVMShadowRam_History_Count  },
    {  (uint8)NvMBlock_FSM_RegMon_Error_Data               ,&rs_block_RegMon_Error_Data                              ,FSM_RegMon_ClearNoInitRAM          ,RegMon_Update_Rs_Block          },
    {  (uint8)NvMBlock_FSM_Exception_Status                ,&rs_block_Exception_Status_Data                          ,ExceptionHandler_Reset_noinit_RAM  ,ExceptionHandler_Update_Rs_Block  },
    {  (uint8)WdgM_EntityStatus                            ,&rs_block_WdgM_EntityStatus                              ,WdgMApp_Reset_Non_Init_Ram         ,WdgMApp_Update_Rs_Block                                },
};

/* Variables */
/*============================================================================*/



/* Private functions prototypes */
/*============================================================================*/



/* Inline functions */
/*============================================================================*/




/* Private functions */
/*============================================================================*/




/* Exported functions */
/*============================================================================*/
