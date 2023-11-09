/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: FSM_Nvm_Supervisor.h $
 * $Revision: 1.3 $
 * $Author: Cruz-EXT, Romanov (uie43239) (uie43239) $
 * $Date: 2022/08/24 19:29:49CEST $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    This file contains common functions for FSM Nvm Supervisor.
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
 * $Log: FSM_Nvm_Supervisor.h  $
 * Revision 1.3 2022/08/24 19:29:49CEST Cruz-EXT, Romanov (uie43239) (uie43239) 
 * Latest changes to NVM Supervisor
 * Revision 1.2 2022/07/29 20:55:43CEST Cruz-EXT, Romanov (uie43239) (uie43239) 
 * Port of NVM Supervisor Code
 * Revision 1.1 2022/01/13 21:45:26CET Opiola, Thaddeus (uidu9036) 
 * Initial revision
 * Member added to project /BS/FCA_XX_21_DCU_ATL/Software/mc_sw/appl/f_fsm/f_fsm_nvm_supervisor/project.pj
 * Revision 1.2 2021/09/15 08:37:31CEST Opiola, Thaddeus (uidu9036) 
 * Add corrections to Error Reaction for FSM Faults
 * Revision 1.1 2021/08/02 06:59:44CEST Tellez-EXT, Fernando02 (uie27682) (uie27682) 
 * Initial revision
 * Member added to project /BS/FCA_XXXX_21_TCM/Software/mc_sw/appl/FaultManager/src/project.pj
 * Revision 1.1.1.2 2021/08/01 21:23:27CEST Tellez-EXT, Fernando02 (uie27682) (uie27682) 
 * Initial revision
 * Member added to project /BS/FCA_XXXX_21_TCM/Software/mc_sw/appl/AdditionalSafetyMeasures/ErrorReactionManager/Include/project.pj
 * Revision 1.1 2021/07/30 17:46:14CEST Tellez-EXT, Fernando02 (uie27682) (uie27682) 
 * Initial revision
 * Member added to project /BS/FCA_XXXX_21_TCM/Software/mc_sw/appl/AdditionalSafetyMeasures/ErrorReactionManager/Include/project.pj
  ============================================================================*/
#ifndef FSM_NVM_SUPV_H
#define FSM_NVM_SUPV_H

/* Includes */
/*============================================================================*/

//#include "eep_data.h"
/* ANALYSIS_REPORT_JUSTIFICATION (2021/07/29 : uie27682) !-->
   TOOL_NUMBER(PCLINT:537) GUIDELINE(N/A:N/A:N/A) Include has preprocessor definitions.
 <--! */
#include "FSM_Nvm_Supervisor_Types.h"


/* Constants and types */
/*============================================================================*/
#define FS_NVM_COMMIT_NOT_PENDING  (uint8)(0x37u)
#define FS_NVM_COMMIT_PENDING      (uint8)(0xA5u)
#define FS_NVM_COMMIT_MAX_RETRY    (2u)    /* With the initial write in init this gives us a total of 3 tries */

/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/
extern void FSM_NvmSupv_Commit_to_NVM_Init(void);
extern void FSM_NvmSupv_Commit_to_NVM (uint8 Committed_To_NVM_Status_Instance);
extern void FSM_NvmSupv_Check_NVM_Commit_Task_10ms (void);
extern void FSM_NvmSupv_Do_Nothing(void);
extern void ReinitializeNVMCommitStatus(void);

#endif
