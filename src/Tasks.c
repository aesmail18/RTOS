/*
 *===========================================================================================
 *	@project	RTOS
 *	@platform	ARM
 *	@module		STM32F401ccub
 *	@driver		Task.c
 *	@version	1.0.0
 *	@brief		public functions body
 *  @layer      Application
 *	@fun		functions: .......................................................
 *	@create		3 Mar 2024		6:00
 *	@author		Ahmed Esmail
 *	@last		Last change: write the body  @ 4 Mar 2024		23:00
 *===========================================================================================
 */
#include "STD_Types.h"
#include "BIT_Math.h"

#include "OS_int.h"

#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MSYSTICK_interface.h"

#include "Tasks.h"


void app_LED0(void)
{
	MGPIO_voidTogglePin(PORT_A, PIN_0);
}

void app_LED1(void)
{
	MGPIO_voidTogglePin(PORT_A, PIN_1);
}
void app_LED2(void)
{
	MGPIO_voidTogglePin(PORT_A, PIN_2);
}
void app_LED3(void)
{
	MGPIO_voidTogglePin(PORT_A, PIN_3);
}
void app_LED4(void)
{
	MGPIO_voidTogglePin(PORT_A, PIN_4);
}
void app_LED5(void)
{
	MGPIO_voidTogglePin(PORT_A, PIN_5);
}
void app_LED6(void)
{
	MGPIO_voidTogglePin(PORT_A, PIN_6);
}
void app_LED7(void)
{
	MGPIO_voidTogglePin(PORT_A, PIN_7);
}
