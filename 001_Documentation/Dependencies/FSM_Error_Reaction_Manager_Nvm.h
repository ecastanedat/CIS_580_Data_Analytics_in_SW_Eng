/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: FSM_Error_Reaction_Manager_Nvm.h $
 * $Revision: 1.3 $
 * $Author: Robles-EXT, Jorge02 (uie46352) (uie46352) $
 * $Date: 2022/09/09 22:18:24CEST $
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
 * $Log: FSM_Error_Reaction_Manager_Nvm.h  $
 * Revision 1.3 2022/09/09 22:18:24CEST Robles-EXT, Jorge02 (uie46352) (uie46352) 
 * Update to accept the Buffer for Register Monitor
 * Revision 1.2 2022/07/29 20:05:51CEST Flores-EXT, Christian0202 (uie43236) (uie43236) 
 * Update files FSM Error Reaction Manager
 * Revision 1.2 2022/05/02 20:53:10CEST Opiola, Thaddeus (uidu9036) 
 * Add changes to C files to fix SWATT issues from Code review.
 * Revision 1.1 2022/01/13 21:43:09CET Opiola, Thaddeus (uidu9036) 
 * Initial revision
 * Member added to project /BS/FCA_XX_21_DCU_ATL/Software/mc_sw/appl/f_fsm/f_fsm_error_reaction_manager/project.pj
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
#ifndef FSM_ERR_REACT_NVM_H
#define FSM_ERR_REACT_NVM_H

/* Includes */
/*============================================================================*/
#ifndef FSM_ERROR_REACTION_MANAGER_H
#include "FSM_Error_Reaction_Manager.h"
#endif /* FSM_ERROR_REACTION_MANAGER_H */

#include "FSM_Error_Reaction_Manager_Types.h"

/* Constants and types */
/*============================================================================*/

extern uint32 FSM_Error_Reaction_NVMShadowRam_Error;
extern uint16 FSM_Error_Reaction_NVMShadowRam_Error_History_Count[RAM_FSM_ERROR_COUNT_DATA_SIZE];



/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/

#endif  
