/*
 *===========================================================================================
 *	@project	RTOS
 *	@platform	ARM
 *	@module		STM32F401ccub
 *	@driver		OS_int.h
 *	@version	1.0.0
 *	@brief		Public functions prototypes
 *  @layer      LIBRARY
 *	@fun		functions: Scheduler and StartOS
 *	@create		3 Mar 2024		6:00
 *	@author		Ahmed Esmail
 *	@last		Last change: Write the prototypes  @ 4 Mar 2024		23:00
 *===========================================================================================
 */
#ifndef _OS_INT_H
#define _OS_INT_H

uint8 OS_u8CreateTask(void(*copy_Handler)(void),uint8 Copy_u8Periodicty,uint8 Copy_u8Periority,uint8 Copy_u8FirstDelay);

void Scheduler(void);

void OS_DeleteTask(uint8 Copy_u8Periority);

void SuspendTask(uint8 Copy_u8Periority);

void ResumeTask(uint8 Copy_u8Periority);

void StartOS(void);


#endif
