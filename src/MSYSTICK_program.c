/*
 *===========================================================================================
 *	@project	RTOS
 *	@platform	ARM
 *	@module		STM32F401ccub
 *	@driver		MSYSTICK_program.c
 *	@version	1.0.0
 *	@brief		public functions body
 *  @layer      MCAL
 *	@fun		functions: .......................................................
 *	@create		3 Mar 2024		6:00
 *	@author		Ahmed Esmail
 *	@last		Last change: write the body  @ 4 Mar 2024		23:00
 *===========================================================================================
 */
#include "STD_Types.h"
#include "BIT_Math.h"

#include "MSYSTICK_private.h"
#include "MSYSTICK_config.h"
#include "MSYSTICK_interface.h"

void (*SYSTICK_SET_CALLBACK_SINGLE)(void) = NULL_PTR;
void (*SYSTICK_SET_CALLBACK_PERIODIC)(void) = NULL_PTR;

void MSYSTICK_voidInit(void)
{
#if SYSTICK_SOURCE == SYSTICK_AHB_DIVIDE_8
	SYSTICK->CTRL &= ~(1<<CLKSOURCE);
#elif SYSTICK_SOURCE == SYSTICK_AHB
	SYSTICK->CTRL |= (1<<CLKSOURCE);
#endif
}
void MSYSTICK_voidStart(uint32 Copy_uint32Loadvalue)
{
	SYSTICK->LOAD = Copy_uint32Loadvalue;
	SYSTICK->VAL = 0;
	SYSTICK->CTRL |= (1 << SYSTICK_ENABLE);
}

uint8 MSYSTICK_voidReadFlag(void)
{
	return GET_BIT(SYSTICK->CTRL, COUNTFLAG);
}
void MSYSTICK_voidCtrlIntState(SYSTICKState Copy_State)
{
	switch (Copy_State)
	{
	case SYSTICKEnable:
		SYSTICK->CTRL |= (1 << TICKINT);
		break;
	case SYSTICKDisable:
		SYSTICK->CTRL &= ~(1 << TICKINT);
		break;
	}
}

void MSYSTICK_voidDelayUs(uint32 Copy_uint32Delayvalue)
{
	MSYSTICK_voidStart(Copy_uint32Delayvalue*2);
	while(MSYSTICK_voidReadFlag() == 0);
	MSYSTICK_voidCtrlIntState(SYSTICKDisable);
}

void MSYSTICK_voidDelayms(uint32 Copy_uint32Delayvalue)
{
	MSYSTICK_voidCtrlIntState(SYSTICKDisable);
	MSYSTICK_voidStart(Copy_uint32Delayvalue*2000);
	while(MSYSTICK_voidReadFlag() == 0);
}
uint32  MSYSTICK_uint32GetElapsedTime(void)
{
	return (SYSTICK->LOAD - SYSTICK->VAL);
}

uint32  MSYSTICK_uint32GetRemainingTime(void)
{
	return (SYSTICK->VAL);
}
void MSYSTICK_voidSetInterval_single(uint32 Copy_uint32Loadvalue, void (*CallbackFunction)(void))
{
	MSYSTICK_voidCtrlIntState(SYSTICKEnable);
	MSYSTICK_voidStart(Copy_uint32Loadvalue * 2000);
	SYSTICK_SET_CALLBACK_SINGLE = CallbackFunction;
}
void MSYSTICK_voidSetInterval_periodic(uint32 Copy_uint32Loadvalue, void (*CallbackFunction)(void))
{
	MSYSTICK_voidCtrlIntState(SYSTICKEnable);
	MSYSTICK_voidStart(Copy_uint32Loadvalue * 2000);
	SYSTICK_SET_CALLBACK_PERIODIC = CallbackFunction;
}
void SysTick_Handler(void)
{
	if (SYSTICK_SET_CALLBACK_SINGLE != NULL_PTR)
	{
		/* Disable SYSTICK */
		SYSTICK->CTRL &= ~(1 << SYSTICK_ENABLE);
		SYSTICK_SET_CALLBACK_SINGLE();
	}
	else
	{
		SYSTICK_SET_CALLBACK_PERIODIC();
	}
}
