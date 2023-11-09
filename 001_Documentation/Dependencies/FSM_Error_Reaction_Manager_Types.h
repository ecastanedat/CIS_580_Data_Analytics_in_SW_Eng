/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: FSM_Error_Reaction_Manager_Types.h $
 * $Revision: 1.2 $
 * $Author: Flores-EXT, Christian0202 (uie43236) (uie43236) $
 * $Date: 2022/07/29 20:05:52CEST $
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
 * $Log: FSM_Error_Reaction_Manager_Types.h  $
 * Revision 1.2 2022/07/29 20:05:52CEST Flores-EXT, Christian0202 (uie43236) (uie43236) 
 * Update files FSM Error Reaction Manager
 * Revision 1.5 2022/04/27 16:09:07CEST Opiola, Thaddeus (uidu9036) 
 * Add Updated review comments and QTOOLS fixes
 * Revision 1.4 2022/04/08 21:33:04CEST Opiola, Thaddeus (uidu9036) 
 * Add code review comments to FSM_Task_Monitor.c/.h and other files.
 * Revision 1.3 2022/04/05 16:18:03CEST Opiola, Thaddeus (uidu9036) 
 * Add reviewed chenaged
 * Revision 1.2 2022/03/30 04:01:26CEST Opiola, Thaddeus (uidu9036) 
 * Add code changs need for SWATT updates plus some SW integration bug fixes.
 * Revision 1.1 2022/01/13 21:43:09CET Opiola, Thaddeus (uidu9036) 
 * Initial revision
 * Member added to project /BS/FCA_XX_21_DCU_ATL/Software/mc_sw/appl/f_fsm/f_fsm_error_reaction_manager/project.pj
 * Revision 1.2.1.2 2021/09/15 08:37:32CEST Opiola, Thaddeus (uidu9036) 
 * Add corrections to Error Reaction for FSM Faults
 * Revision 1.2.1.1 2021/08/02 07:01:56CEST Tellez-EXT, Fernando02 (uie27682) (uie27682) 
 * Adding two new Nvm blocks for Error Reaction Manager and FD05 updates to retrieve error codes.
 * Revision 1.2 2021/07/22 13:55:59CEST Fraustro-EXT, David (uid32234) 
 * Merge with FSM branch
 * Revision 1.1.1.1 2021/07/09 00:07:56CEST Adukkathayar-EXT, Sreedevi (uie30029) (uie30029) 
 * check in: FSM Error Reaction Manager Changes to the type header
 * Revision 1.1 2021/05/16 00:07:06CEST Opiola, Thaddeus (uidu9036) 
 * Initial revision
 * Member added to project /BS/FCA_XXXX_21_TCM/Software/mc_sw/appl/FaultManager/src/project.pj
  ============================================================================*/
#ifndef FSM_ERROR_REACTION_MANAGER_TYPES_H
#define FSM_ERROR_REACTION_MANAGER_TYPES_H

/* Includes */
/*============================================================================*/
#ifndef FSM_TYPES_H
#include "FSM_Types.h"
#endif /* FSM_TYPES_H */

/* Constants and types */
/*============================================================================*/

typedef FSM_Uint32 Fsm_Error_Type;


typedef enum
{
    REACTION_RECOVERABLE,
    REACTION_RECOVERABLE_NORESET,
    REACTION_RECOVERABLE_SWP_RESET
} FSM_Error_Reaction_Type;

typedef struct
{
        Fsm_Error_Mask_Type Error_Mask;
        FSM_Error_Reaction_Type Reaction_Type;
} FSM_Error_Reaction_Struct_Type;

/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/


#endif  
