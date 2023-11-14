/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: FSM_Nvm_Supervisor_Types.h $
 * $Revision: 1.4 $
 * $Author: Robles-EXT, Jorge02 (uie46352) (uie46352) $
 * $Date: 2022/10/20 22:18:21CEST $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    Types used in Nvm Supervisor module.
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
 * $Log: FSM_Nvm_Supervisor_Types.h  $
 * Revision 1.4 2022/10/20 22:18:21CEST Robles-EXT, Jorge02 (uie46352) (uie46352)
 * Adding the Circular Buffer Exception Handler for NvM
 * Revision 1.3 2022/09/09 22:18:21CEST Robles-EXT, Jorge02 (uie46352) (uie46352) 
 * Adding the Circular Buffer Register Monitor for NvM
 * Revision 1.2 2022/07/29 20:55:52CEST Cruz-EXT, Romanov (uie43239) (uie43239) 
 * Port of NVM Supervisor Code
 * Revision 1.1 2022/01/13 21:45:26CET Opiola, Thaddeus (uidu9036) 
 * Initial revision
 * Member added to project /BS/FCA_XX_21_DCU_ATL/Software/mc_sw/appl/f_fsm/f_fsm_nvm_supervisor/project.pj
 * Revision 1.2 2021/09/15 08:37:31CEST Opiola, Thaddeus (uidu9036) 
 * Add corrections to Error Reaction for FSM Faults
 * Revision 1.1 2021/08/02 06:59:45CEST Tellez-EXT, Fernando02 (uie27682) (uie27682) 
 * Initial revision
 * Member added to project /BS/FCA_XXXX_21_TCM/Software/mc_sw/appl/FaultManager/src/project.pj
 * Revision 1.1.1.2 2021/08/01 21:23:28CEST Tellez-EXT, Fernando02 (uie27682) (uie27682) 
 * Initial revision
 * Member added to project /BS/FCA_XXXX_21_TCM/Software/mc_sw/appl/AdditionalSafetyMeasures/ErrorReactionManager/Include/project.pj
 * Revision 1.1 2021/07/30 17:46:14CEST Tellez-EXT, Fernando02 (uie27682) (uie27682) 
 * Initial revision
 * Member added to project /BS/FCA_XXXX_21_TCM/Software/mc_sw/appl/AdditionalSafetyMeasures/ErrorReactionManager/Include/project.pj
  ============================================================================*/
#ifndef FSM_NVM_SUPV_TYPE_H
#define FSM_NVM_SUPV_TYPE_H

/* Includes */
/*============================================================================*/
/* ANALYSIS_REPORT_JUSTIFICATION (2021/07/29 : uie27682) !-->
   TOOL_NUMBER(PCLINT:451) GUIDELINE(MISRA_2004:RULE:19.15) Include has preprocess inclusions inside of the file.
   TOOL_NUMBER(PCLINT:537) GUIDELINE(N/A:N/A:N/A) Include has preprocess inclusions inside of the file.
 <--! */

/* ANALYSIS_REPORT_JUSTIFICATION (2022/10/02 : uie46352) !-->
   TOOL_NUMBER(PCLINT:537) GUIDELINE(N/A:N/A:N/A) Include guards are inside each of the header files.
 <--! */
#include "Std_Types.h"

/* Constants and types */
/*============================================================================*/
typedef enum
{
    FSM_ERROR_REACTION_FAULT_INSTANCE = 0,
    FSM_ERROR_REACTION_FAULT_HISTORY_COUNT_INSTANCE,
    FSM_REGISTER_MONITOR_ERROR,
    FSM_EXCEPTION_STATUS_INSTANCE,
    FSM_WATCHDOG_SUPVERSION_INSTANCE,
    FSM_NUM_OF_INSTANCES_COMMITTED_TO_NVM_STATUS
    /* ANALYSIS_REPORT_JUSTIFICATION (2023/05/31 : 43239) !-->
       TOOL_NUMBER(PCLINT:756) GUIDELINE(MISRA_2012:RULE:2.3) Typdef name can remain unused to avoid warnings.
     <--! */
} pram_committed_to_nvm_status_enum;

typedef struct{
        uint8 Block_ID;
        void *Shadow_Address;
        void (*On_Commit)(void);
        void (*Init_Shadow)(void);
}FS_Nvm_Commit_Instance_Type;

/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/

#endif
