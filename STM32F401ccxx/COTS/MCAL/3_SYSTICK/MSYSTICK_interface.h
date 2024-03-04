/*
 *===========================================================================================
 *	@project	RTOS
 *	@platform	ARM
 *	@module		STM32F401ccub
 *	@driver		MSYSTICK_interface.h
 *	@version	1.0.0
 *	@brief		Public functions
 *  @layer      MCAL
 *	@fun		functions: .......................................................
 *	@create		3 Mar 2024		6:00
 *	@author		Ahmed Esmail
 *	@last		Last change: write the public functions  @ 4 Mar 2024		23:00
 *===========================================================================================
 */
#ifndef MSYSTICK_INT_H
#define MSYSTICK_INT_H

typedef enum
{
	SYSTICKEnable,
	SYSTICKDisable
}SYSTICKState;


// clock -> AHB  ****  AHB/8
void MSYSTICK_voidInit(void);

void MSYSTICK_voidStart(uint32 Copy_uint32Loadvalue);

uint8   MSYSTICK_voidReadFlag(void);

void MSYSTICK_voidCtrlIntState(SYSTICKState Copy_State );

// 16MHZ --> /8 ---> 2MHZ
void MSYSTICK_voidDelayUs(uint32 Copy_uint32Delayvalue);

void MSYSTICK_voidDelayms(uint32 Copy_uint32Delayvalue);



uint32  MSYSTICK_uint32GetElapsedTime(void);

uint32  MSYSTICK_uint32GetRemainingTime(void);

void MSYSTICK_voidSetInterval_single(uint32 Copy_uint32Loadvalue, void (*CallbackFunction)(void));
void MSYSTICK_voidSetInterval_periodic(uint32 Copy_uint32Loadvalue, void (*CallbackFunction)(void));
















#endif
