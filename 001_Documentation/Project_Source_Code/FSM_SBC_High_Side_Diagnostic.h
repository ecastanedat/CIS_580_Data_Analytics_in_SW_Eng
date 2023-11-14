/*============================================================================*/
/*                        VNI SOFTWARE GROUP                                  */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: FSM_SBC_High_Side_Diagnostic.h $
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
 * $Log: FSM_SBC_High_Side_Diagnostic.h  $
  ============================================================================*/
#ifndef FILENAME_H
#define FILENAME_H

/* Includes */
/*============================================================================*/

/* Constants and types */
/*============================================================================*/


typedef enum
{
    SBC_HS_1,
    SBC_HS_2,
    SBC_HS_4,
    SCB_SUPPORTED_HS
}SBC_HS_ID;


extern uint8 FSM_SBC_High_Side_OCState(SBC_HS_ID HighSideId);
extern FUNC(void,FSM_SBC_High_Side_Diagnostic_CODE) FSM_SBC_High_Side_Diagnostic_Task_5ms (void);
extern FUNC(void,FSM_SBC_High_Side_Diagnostic_CODE) FSM_SBC_High_Side_Diagnostic_Init(void);


/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/

#endif
