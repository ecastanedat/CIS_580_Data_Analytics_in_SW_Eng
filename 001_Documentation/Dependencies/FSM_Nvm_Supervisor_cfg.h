/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: FSM_Nvm_Supervisor_cfg.h $
 * $Revision: 1.4 $
 * $Author: Robles-EXT, Jorge02 (uie46352) (uie46352) $
 * $Date: 2022/10/20 22:18:22CEST $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    Header file for configuration support file for FSM Nvm Supervisor logic.
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
 * $Log: FSM_Nvm_Supervisor_cfg.h  $
 * Revision 1.4 2022/10/20 22:18:22CEST Robles-EXT, Jorge02 (uie46352) (uie46352)
 * Adding the Circular Buffer Exception Handlers for NvM
 * Revision 1.3 2022/09/09 22:18:22CEST Robles-EXT, Jorge02 (uie46352) (uie46352) 
 * Adding the Circular Buffer Register Monitor for NvM
 * Revision 1.2 2022/07/29 20:55:42CEST Cruz-EXT, Romanov (uie43239) (uie43239) 
 * Port of NVM Supervisor Code
 * Revision 1.1 2022/01/13 21:45:26CET Opiola, Thaddeus (uidu9036) 
 * Initial revision
 * Member added to project /BS/FCA_XX_21_DCU_ATL/Software/mc_sw/appl/f_fsm/f_fsm_nvm_supervisor/project.pj
 * Revision 1.1 2021/08/02 06:59:45CEST Tellez-EXT, Fernando02 (uie27682) (uie27682) 
 * Initial revision
 * Member added to project /BS/FCA_XXXX_21_TCM/Software/mc_sw/appl/FaultManager/src/project.pj
 * Revision 1.1.1.2 2021/08/01 21:23:28CEST Tellez-EXT, Fernando02 (uie27682) (uie27682) 
 * Initial revision
 * Member added to project /BS/FCA_XXXX_21_TCM/Software/mc_sw/appl/AdditionalSafetyMeasures/ErrorReactionManager/Include/project.pj
  ============================================================================*/
#ifndef FSM_NVM_SUPV_CFG_H
#define FSM_NVM_SUPV_CFG_H

/* Includes */
/*============================================================================*/
/* ANALYSIS_REPORT_JUSTIFICATION (2021/07/30 : uie27682) !-->
   TOOL_NUMBER(PCLINT:537) GUIDELINE(N/A:N/A:N/A) Include guards are inside each of the header files.
 <--! */
#include "FSM_Nvm_Supervisor_Types.h"


/* Exported Variables */
/*============================================================================*/
extern const FS_Nvm_Commit_Instance_Type FS_Nvm_Commit_Instance[FSM_NUM_OF_INSTANCES_COMMITTED_TO_NVM_STATUS];

/* Exported functions prototypes */
/*============================================================================*/

#endif
