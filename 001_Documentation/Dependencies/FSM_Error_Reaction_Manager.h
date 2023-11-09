/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: FSM_Error_Reaction_Manager.h $
 * $Revision: 1.4 $
 * $Author: Flores-EXT, Christian0202 (uie43236) (uie43236) $
 * $Date: 2022/08/01 20:38:13CEST $
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
 * $Log: FSM_Error_Reaction_Manager.h  $
 * Revision 1.4 2022/08/01 20:38:13CEST Flores-EXT, Christian0202 (uie43236) (uie43236) 
 * Update for FSM Error Reaction Manager code
 * Revision 1.3 2022/07/29 21:20:07CEST Flores-EXT, Christian0202 (uie43236) (uie43236) 
 * Update FSM Error Reaction Manager to fit with Safety Arbitrator
 * Revision 1.7 2022/05/05 06:32:08CEST Opiola, Thaddeus (uidu9036) 
 * Add correction for NON INIT RAM and fix Typo for FSM_SAFETY_GUARD_PLAUS_ERROR name
 * Revision 1.6 2022/05/02 20:53:10CEST Opiola, Thaddeus (uidu9036) 
 * Add changes to C files to fix SWATT issues from Code review.
 * Revision 1.5 2022/04/27 16:09:07CEST Opiola, Thaddeus (uidu9036) 
 * Add Updated review comments and QTOOLS fixes
 * Revision 1.4 2022/04/05 16:18:04CEST Opiola, Thaddeus (uidu9036) 
 * Add reviewed chenaged
 * Revision 1.3 2022/03/30 04:01:26CEST Opiola, Thaddeus (uidu9036) 
 * Add code changs need for SWATT updates plus some SW integration bug fixes.
 * Revision 1.2 2022/02/21 23:04:48CET Opiola, Thaddeus (uidu9036) 
 * Add final changes for RESET issue plus code review items for FSM Error Reaction manager.
 * Revision 1.1 2022/01/13 21:43:09CET Opiola, Thaddeus (uidu9036) 
 * Initial revision
 * Member added to project /BS/FCA_XX_21_DCU_ATL/Software/mc_sw/appl/f_fsm/f_fsm_error_reaction_manager/project.pj
 * Revision 1.4.2.3.1.1.1.1 2021/09/24 19:28:33CEST Opiola, Thaddeus (uidu9036) 
 * Check in SW Integration testing and improvements
 * Revision 1.4.2.3.1.1 2021/08/02 07:01:57CEST Tellez-EXT, Fernando02 (uie27682) (uie27682) 
 * Adding two new Nvm blocks for Error Reaction Manager and FD05 updates to retrieve error codes.
 * Revision 1.4.2.3 2021/07/09 07:56:00CEST Opiola, Thaddeus (uidu9036) 
 * More Inverse Ram Fixes for Error Reaction plus one Task Mon fix.
 * Revision 1.4.2.2 2021/07/09 00:09:11CEST Adukkathayar-EXT, Sreedevi (uie30029) (uie30029) 
 * check in: FSM Error Reaction implementation
 * Revision 1.4.1.1 2021/06/25 17:18:49CEST Adukkathayar-EXT, Sreedevi (uie30029) (uie30029) 
 * check in: new changes error reaction and and xdm files
 * Revision 1.4 2021/05/31 02:26:34CEST Opiola, Thaddeus (uidu9036) 
 * Add SW integration Changes for future improvements for FSM_Types.h and other SW integration changes.
 * Revision 1.3 2021/05/18 01:45:27CEST Delgadillo, Sergio (uidr3241) 
 * FSM Validate Brake
 * Revision 1.2 2021/05/17 18:23:30CEST Opiola, Thaddeus (uidu9036) 
 * Remove uneeded stubs
 * Revision 1.1 2021/05/16 00:07:06CEST Opiola, Thaddeus (uidu9036) 
 * Initial revision
 * Member added to project /BS/FCA_XXXX_21_TCM/Software/mc_sw/appl/FaultManager/src/project.pj
  ============================================================================*/
#ifndef FSM_ERROR_REACTION_MANAGER_H
#define FSM_ERROR_REACTION_MANAGER_H

/* Includes */
/*============================================================================*/
#ifndef STD_TYPES_H
#include "Std_Types.h"
#endif  /*STD_TYPES_H*/
/* Constants and types */
/*============================================================================*/

typedef uint32 Fsm_Error_Mask_Type;

#define FSM_NO_ERROR                              (Fsm_Error_Mask_Type)0X00000000U
#define FSM_REDUNDANT_RAM_ERROR                   (Fsm_Error_Mask_Type)0x00000001U
#define FSM_ECC_DATA_FLASH_ERROR                  (Fsm_Error_Mask_Type)0x00000002U
#define FSM_ECC_PROGRAM_FLASH_ERROR               (Fsm_Error_Mask_Type)0x00000004U
#define FSM_ECC_RAM_ERROR                         (Fsm_Error_Mask_Type)0x00000008U
#define FSM_ECC_PERIPHERAL_RAM_ERROR              (Fsm_Error_Mask_Type)0x00000010U    /* NOT Supported by SWP at moment */
#define FSM_REGMON_STACK_ERROR                    (Fsm_Error_Mask_Type)0x00000020U
#define FSM_REGMON_SYSREG_ERROR                   (Fsm_Error_Mask_Type)0x00000040U
#define FSM_REGMON_SAFETYREG_ERROR                (Fsm_Error_Mask_Type)0x00000080U
#define FSM_REGMON_IO_REG_ERROR                   (Fsm_Error_Mask_Type)0x00000100U
#define FSM_WDGM_TASKSUPV_ERROR                   (Fsm_Error_Mask_Type)0x00000200U
#define FSM_CLOCK_ERROR                           (Fsm_Error_Mask_Type)0x00000400U
#define FSM_PLL_ERROR                             (Fsm_Error_Mask_Type)0x00000800U
#define FSM_IMPLAUSIBLE_VALUE                     (Fsm_Error_Mask_Type)0x00001000U
#define FSM_NVM_DATA_ERROR                        (Fsm_Error_Mask_Type)0x00002000U
#define FSM_UNUSED_INTERRUPT                      (Fsm_Error_Mask_Type)0x00004000U
#define FSM_MICRO_EXCEPTION                       (Fsm_Error_Mask_Type)0x00008000U
#define FSM_RAM_TEST                              (Fsm_Error_Mask_Type)0x00010000U    /*Spare not used*/
#define FSM_SBC_INIT_ERR                          (Fsm_Error_Mask_Type)0x00020000U
#define FSM_A2D_SELF_TEST_ERR                     (Fsm_Error_Mask_Type)0x00040000U
#define FSM_SG2_ANTI_PINCH_PLAUS_ERROR            (Fsm_Error_Mask_Type)0x00080000U
#define FSM_SG1_LIFGATE_AJAR_W_SPEED_PLAUS_ERROR  (Fsm_Error_Mask_Type)0x00100000U
#define FSM_CAN_COMM_VEH_SP_ERROR                 (Fsm_Error_Mask_Type)0x00200000U
#define FSM_CAN_COMM_CRANK_ERROR                  (Fsm_Error_Mask_Type)0x00400000U
#define FSM_CAN_COMM_CMD_ERROR                    (Fsm_Error_Mask_Type)0x00800000U
#define FSM_VOLTAGE_RANGE_ERR                     (Fsm_Error_Mask_Type)0x01000000U
#define FSM_ALU_CHECK_ERR                                              0x02000000U
#define FSM_CANARY_STACK_ERROR                    (Fsm_Error_Mask_Type)0x04000000U
#define FSM_RAM_MARCH_TEST_ERR                    (Fsm_Error_Mask_Type)0x08000000U
#define FSM_HALL_SENSORS_FAILED                   (Fsm_Error_Mask_Type)0x10000000U
#define FSM_DIAG_STUCK_ERROR                      (Fsm_Error_Mask_Type)0x20000000U
#define FSM_UNUSED_30                             (Fsm_Error_Mask_Type)0x40000000U
#define FSM_UNUSED_31                             (Fsm_Error_Mask_Type)0x80000000U



#define SAFE_STATE_DEFINED_WITH_SBC_FO_LINE 0
#define RAM_FSM_ERROR_COUNT_DATA_SIZE     (33u)

/* Exported Variables */
/*============================================================================*/

/* Exported functions prototypes */
/*============================================================================*/
extern void FSM_Set_Error_Reaction(const Fsm_Error_Mask_Type Fsm_Error_Mask);
extern void FSM_Error_Reaction_Init(void );
extern void FSM_Error_Reaction_Task_10ms(void);
void FSM_Clear_Error_Reaction_Recoverable_No_Reset(const Fsm_Error_Mask_Type Fsm_Error_Mask);

void FSM_Error_Reaction_Update_NVMShadowRam(void);
void FSM_Error_Reaction_Update_NVMShadowRam_History_Count(void);




#endif  
