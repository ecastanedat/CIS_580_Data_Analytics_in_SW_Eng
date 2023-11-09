/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: FSM_Nvm_Supervisor.c $
 * $Revision: 1.2 $
 * $Author: Cruz-EXT, Romanov (uie43239) (uie43239) $
 * $Date: 2022/07/29 20:55:43CEST $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    This file contains main FSM Nvm Supervisor logic.
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
 * $Log: FSM_Nvm_Supervisor.c  $
 * Revision 1.2 2022/07/29 20:55:43CEST Cruz-EXT, Romanov (uie43239) (uie43239) 
 * Port of NVM Supervisor Code
 * Revision 1.5 2022/04/28 15:42:23CEST Opiola, Thaddeus (uidu9036)
 * Fix all QTOOLS errors.  Most of errors are becuase QTOOLS QTOOLS ANALYSIS_REPORT_JUSTIFICATION fronm ideas does not match QTOOLS format so K2 metrics are showing high.
 * Revision 1.4 2022/04/05 16:19:05CEST Opiola, Thaddeus (uidu9036)
 * Check in reviewed changes
 * Revision 1.3 2022/03/30 04:01:28CEST Opiola, Thaddeus (uidu9036)
 * Add code changs need for SWATT updates plus some SW integration bug fixes.
 * Revision 1.2 2022/02/21 22:26:16CET Opiola, Thaddeus (uidu9036)
 * Add other changes from SW Dev directory for FSM changes that were tested for NO RESET
 * Revision 1.1 2022/01/13 21:45:25CET Opiola, Thaddeus (uidu9036)
 * Initial revision
 * Member added to project /BS/FCA_XX_21_DCU_ATL/Software/mc_sw/appl/f_fsm/f_fsm_nvm_supervisor/project.pj
 * Revision 1.1.1.2 2021/10/11 18:22:48CEST Opiola, Thaddeus (uidu9036)
 * Make code review comments.
 * Revision 1.1.1.1 2021/09/15 08:37:30CEST Opiola, Thaddeus (uidu9036)
 * Add corrections to Error Reaction for FSM Faults
 * Revision 1.1 2021/08/02 06:59:44CEST Tellez-EXT, Fernando02 (uie27682) (uie27682)
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
#include "stddef.h"
#include "Std_Types.h"         /* Standard types definitions, contains also Platform Types and Compiler abstraction */
#include "Os.h"
#include "Nvm.h"
#include "FSM_Nvm_Supervisor.h"
#include "FSM_Nvm_Supervisor_cfg.h"
#include "FSM_Error_Reaction_Manager_Types.h"
#include "WdgM.h"

#ifndef SWATT_BYPASS
/* ANALYSIS_REPORT_JUSTIFICATION (2022/09/28 : uie46352) !-->
   TOOL_NUMBER(PCLINT:9026) GUIDELINE(MISRA_2012:DIRECTIVE:4.9) This macro is used only by SWATT, no issue. RISK(No risk) RACT(Can't be improved) RESP(Thaddeus Opiola/2022/04/18) NoC(N/A)
 <--! */
#define SWATT_BYPASS(a,b)
#endif

/* Constants and types  */
/*============================================================================*/

/* Variables */
/*============================================================================*/
/* non initialized RAM */
#pragma ghs section bss=".fsm_no_init"

static FSM_Uint8 Committed_To_NVM_Status[FSM_NUM_OF_INSTANCES_COMMITTED_TO_NVM_STATUS];

#pragma ghs section bss = default

static FSM_Uint8 Nvm_Commit_Retry_Count[FSM_NUM_OF_INSTANCES_COMMITTED_TO_NVM_STATUS] = {{0U,(uint8)~((uint8)0U)}, {0U,(uint8)~((uint8)0U)}, {0U,(uint8)~((uint8)0U)},{0U,(uint8)~((uint8)0U)},{0U,(uint8)~((uint8)0U)}};



/* Private functions prototypes */
/*============================================================================*/


/* Inline functions */
/*============================================================================*/


/* Private functions */
/*============================================================================*/
static void FSM_NvmSupv_CheckDataIntegrity(void);
static uint8 FSM_NvmSupv_Being_Committed_to_NVM(uint8 Committed_To_NVM_Status_Instance);
static void FSM_NvmSupv_Clear_Commit_to_NVM(uint8 Committed_To_NVM_Status_Instance);

/* Exported functions */
/*============================================================================*/
/************************************************************************
 *  Description          : This function on initialization will check the Non Init RAM Commmit flags for FuSa NVM Blocks.
 *                         If  Non Init RAM Commmit flag is PENDING then this function shall write FuSa Non Init RAM data to
 *                         NVM Shadow RAM before issueing a call to rewrite the NVM BLock on SW initialization while normal
 *                         processing shall be accomplshed at task level..
 *  Parameters           : FS_NVM_BlockId - Block ID to write
 *  Return               : None
 **************************************************************************/
void FSM_NvmSupv_Commit_to_NVM_Init(void)
{
    uint8 nvm_instances_idx;
    uint8 nvm_commit_instance_index;

    SuspendAllInterrupts();

    /* Clear NVM Rety Counters for this RESET Cycle  */
    for (nvm_instances_idx = 0U; (uint8)FSM_NUM_OF_INSTANCES_COMMITTED_TO_NVM_STATUS > nvm_instances_idx; nvm_instances_idx++)
    {
        /* Initialize Variables */
        Nvm_Commit_Retry_Count[nvm_instances_idx].ValDTU8 = 0U;
        Nvm_Commit_Retry_Count[nvm_instances_idx].InvDTU8 = (uint8)~Nvm_Commit_Retry_Count[nvm_instances_idx].ValDTU8;
    }

    /* Re-Queue NVM Rquests */
    for(nvm_commit_instance_index = 0U; nvm_commit_instance_index < (uint8)FSM_NUM_OF_INSTANCES_COMMITTED_TO_NVM_STATUS; nvm_commit_instance_index++ )
    {
        if(FS_NVM_COMMIT_PENDING == FSM_NvmSupv_Being_Committed_to_NVM(nvm_commit_instance_index))
        {
            FS_Nvm_Commit_Instance[nvm_commit_instance_index].Init_Shadow();
            (void)NvM_WriteBlock(FS_Nvm_Commit_Instance[nvm_commit_instance_index].Block_ID,(void *)FS_Nvm_Commit_Instance[nvm_commit_instance_index].Shadow_Address);
        }
    }

    ResumeAllInterrupts();
}

/************************************************************************
 *  Name                 : ReinitializeNVMCommitStatus
 *  TAG                  :
 *  Description          : This function will reinitialize Non Init RAM (PRAM)
 *                         Committed_To_NVM_Status[] variable if NON INIT RAM
 *                         is corrupt on POR or Inition Cycle
 *  Parameters           : None
 *  Return               : None
 **************************************************************************/
void ReinitializeNVMCommitStatus(void)
{
    uint8 nvm_instances_idx;


    SuspendAllInterrupts();

    for (nvm_instances_idx = 0U; (uint8)FSM_NUM_OF_INSTANCES_COMMITTED_TO_NVM_STATUS > nvm_instances_idx; nvm_instances_idx++)
    {
        Committed_To_NVM_Status[nvm_instances_idx].ValDTU8 =  FS_NVM_COMMIT_NOT_PENDING;
        Committed_To_NVM_Status[nvm_instances_idx].InvDTU8 = (uint8)~Committed_To_NVM_Status[nvm_instances_idx].ValDTU8;
    }

    ResumeAllInterrupts();
}


/************************************************************************
 *  Description          : This function sets the PRAM (Non Init RAM) dirty to indicate, by the passed parameter, to make
 *                         sure PRAM data makes it to NVM during NORMAL operation of SW and if there a RESETS.
 *  Parameters           : FS_NVM_BlockId - Block ID to write
 *  Return               : None
 **************************************************************************/
void FSM_NvmSupv_Commit_to_NVM(uint8 Committed_To_NVM_Status_Instance)
{
    SuspendAllInterrupts();

    if ((uint8)FSM_NUM_OF_INSTANCES_COMMITTED_TO_NVM_STATUS > Committed_To_NVM_Status_Instance)
    {
       /* Set the Pram Committed_To_NVM_Status of the NVM BLOCK ID to assure write to NVM */
       /* Note this PRAM indication serves as dirty bit over MPU RESETS */
       Committed_To_NVM_Status[Committed_To_NVM_Status_Instance].ValDTU8 =  FS_NVM_COMMIT_PENDING;
       Committed_To_NVM_Status[Committed_To_NVM_Status_Instance].InvDTU8 = (uint8)~Committed_To_NVM_Status[Committed_To_NVM_Status_Instance].ValDTU8;
    }


    ResumeAllInterrupts();
}


/************************************************************************
 *  Description          : This function commits the data to the NVM block indicated by the passed parameters.
 *  Parameters           : FS_NVM_BlockId - Block ID to write
 *  Return               : None
 **************************************************************************/
void FSM_NvmSupv_Check_NVM_Commit_Task_10ms(void)
{
    uint8 NvM_Write_Status_lcl;
    uint8 nvm_commit_instance_index;

    SuspendAllInterrupts();

    FSM_NvmSupv_CheckDataIntegrity();

    for(nvm_commit_instance_index = 0; nvm_commit_instance_index < (uint8)FSM_NUM_OF_INSTANCES_COMMITTED_TO_NVM_STATUS; nvm_commit_instance_index++ )
    {
        NvM_Write_Status_lcl = (uint8)NVM_REQ_PENDING;

        if(FS_NVM_COMMIT_PENDING == FSM_NvmSupv_Being_Committed_to_NVM(nvm_commit_instance_index))
        {
            (void)NvM_GetErrorStatus(FS_Nvm_Commit_Instance[nvm_commit_instance_index].Block_ID, &NvM_Write_Status_lcl);

            if(NVM_REQ_OK == NvM_Write_Status_lcl)
            {
                FSM_NvmSupv_Clear_Commit_to_NVM(nvm_commit_instance_index);
                FS_Nvm_Commit_Instance[nvm_commit_instance_index].On_Commit();
                Nvm_Commit_Retry_Count[nvm_commit_instance_index].ValDTU8 = 0U;
                Nvm_Commit_Retry_Count[nvm_commit_instance_index].InvDTU8 = (uint8)~Nvm_Commit_Retry_Count[nvm_commit_instance_index].ValDTU8;
            }

            else if (NVM_REQ_NOT_OK == NvM_Write_Status_lcl)
            {
                if(FS_NVM_COMMIT_MAX_RETRY >= Nvm_Commit_Retry_Count[nvm_commit_instance_index].ValDTU8)
                {
                    (void)NvM_WriteBlock(FS_Nvm_Commit_Instance[nvm_commit_instance_index].Block_ID,(const void*)FS_Nvm_Commit_Instance[nvm_commit_instance_index].Shadow_Address);

                    Nvm_Commit_Retry_Count[nvm_commit_instance_index].ValDTU8++;
                    Nvm_Commit_Retry_Count[nvm_commit_instance_index].InvDTU8 = (uint8)~Nvm_Commit_Retry_Count[nvm_commit_instance_index].ValDTU8;
                }
            }
            else
            {
                /* Status is PENDING - Wait for NVM write to finish */
            }
        }
    }

    /* Adding call to task supervision module */
    (void)WdgM_UpdateAliveCounter((WdgM_SupervisedEntityIdType) SE_FSM_NVMSUPV_CHECK_NVM_COMMIT_TASK);

    /* Re-enabling interrupts as we are done with this function */
    ResumeAllInterrupts();
}


/************************************************************************
 *  Description          : This function is a stub for instanciation of SW where functin call is not needed.
 *  Parameters           : FS_NVM_BlockId - Block ID to write
 *  Return               : Status of commit
 **************************************************************************/
void FSM_NvmSupv_Do_Nothing(void)
{
    /* Do Nothing */
    /* SWATT test bypass do not delete */
    SWATT_BYPASS(FSM_NvmSupv_Do_Nothing, m_FSM_NvmSupv_Do_Nothing());
}


/************************************************************************
 *  Description          : This function determines if the passed BlockId is being written to NVM
 *  Parameters           : FS_NVM_BlockId - Block ID to write
 *  Return               : Status of commit
 **************************************************************************/
static uint8 FSM_NvmSupv_Being_Committed_to_NVM(uint8 Committed_To_NVM_Status_Instance)
{
    uint8 Committed_To_NVM_Status_lcl;

    /* SWATT test bypass do not delete */
    SWATT_BYPASS(FSM_NvmSupv_Being_Committed_to_NVM, m_FSM_NvmSupv_Being_Committed_to_NVM(Committed_To_NVM_Status_Instance));

    SuspendAllInterrupts();

    Committed_To_NVM_Status_lcl = FS_NVM_COMMIT_NOT_PENDING;

    /* Perform Data Integrity Check */
    DataIntegrityCheck_Array_FSM_Uint8(Committed_To_NVM_Status,(uint32)FSM_NUM_OF_INSTANCES_COMMITTED_TO_NVM_STATUS);
    DataIntegrityCheck_Array_FSM_Uint8(Nvm_Commit_Retry_Count,(uint32)FSM_NUM_OF_INSTANCES_COMMITTED_TO_NVM_STATUS);

    /* Get Committed_To_NVM_Status Instance Value */
    if ((uint8)FSM_NUM_OF_INSTANCES_COMMITTED_TO_NVM_STATUS > Committed_To_NVM_Status_Instance)
    {
        Committed_To_NVM_Status_lcl = Committed_To_NVM_Status[Committed_To_NVM_Status_Instance].ValDTU8;
    }


    ResumeAllInterrupts();

    return Committed_To_NVM_Status_lcl;
}


/************************************************************************
 *  Description          : This function shall remove the indication that FS data is being committed to NVM, by setting the indication to ID Reserve0.
 *  Parameters           : FS_NVM_BlockId - Block ID to write
 *  Return               : None
 **************************************************************************/
static void FSM_NvmSupv_Clear_Commit_to_NVM(uint8 Committed_To_NVM_Status_Instance)
{
    /* SWATT test bypass do not delete */
    SWATT_BYPASS(FSM_NvmSupv_Clear_Commit_to_NVM, m_FSM_NvmSupv_Clear_Commit_to_NVM(Committed_To_NVM_Status_Instance));

    SuspendAllInterrupts();

    if ((uint8)FSM_NUM_OF_INSTANCES_COMMITTED_TO_NVM_STATUS > Committed_To_NVM_Status_Instance)
    {
        /* Clear the Pram Committed_To_NVM_Status to Reserved0 to discable NVM update over NORMAL Operation and RESET Cycles */
        Committed_To_NVM_Status[Committed_To_NVM_Status_Instance].ValDTU8 = FS_NVM_COMMIT_NOT_PENDING;
        Committed_To_NVM_Status[Committed_To_NVM_Status_Instance].InvDTU8 = (uint8)~Committed_To_NVM_Status[Committed_To_NVM_Status_Instance].ValDTU8;
    }


    ResumeAllInterrupts();
}

/*********************************************************************************************
*  Description              :  Checks the integrity of all FSM types used in the file
*  Parameters               :  None
*  Return                   :  None
**********************************************************************************************/
static void FSM_NvmSupv_CheckDataIntegrity(void)
{
    /* SWATT test bypass do not delete */
    SWATT_BYPASS(FSM_NvmSupv_CheckDataIntegrity, m_FSM_NvmSupv_CheckDataIntegrity());

    SuspendAllInterrupts();

    DataIntegrityCheck_Array_FSM_Uint8(Committed_To_NVM_Status, (uint32)FSM_NUM_OF_INSTANCES_COMMITTED_TO_NVM_STATUS);
    DataIntegrityCheck_Array_FSM_Uint8(Nvm_Commit_Retry_Count, (uint32)FSM_NUM_OF_INSTANCES_COMMITTED_TO_NVM_STATUS);

    ResumeAllInterrupts();
}
