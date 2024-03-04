/*
 *===========================================================================================
 *	@project	RTOS
 *	@platform	ARM
 *	@module		STM32F401ccub
 *	@driver		main.c
 *	@version	1.0.0
 *	@brief		public functions body
 *  @layer      Application
 *	@fun		functions: .......................................................
 *	@create		3 Mar 2024		6:00
 *	@author		Ahmed Esmail
 *	@last		Last change: write the application  @ 4 Mar 2024		23:00
 *===========================================================================================
 */
#include "STD_Types.h"
#include "BIT_Math.h"

#include "OS_int.h"

#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MSYSTICK_interface.h"

#include "Tasks.h"

int main(void)
{
	MRCC_voidInit();
	MRCC_voidEnable(AHB1, AHB1_GPIOA);
	MGPIO_voidSetMode(PORT_A, PIN_0, PIN_OUTPUT);
	MGPIO_voidSetMode(PORT_A, PIN_1, PIN_OUTPUT);
	MGPIO_voidSetMode(PORT_A, PIN_2, PIN_OUTPUT);
	MGPIO_voidSetMode(PORT_A, PIN_3, PIN_OUTPUT);
	MGPIO_voidSetMode(PORT_A, PIN_4, PIN_OUTPUT);
	MGPIO_voidSetMode(PORT_A, PIN_5, PIN_OUTPUT);
	MGPIO_voidSetMode(PORT_A, PIN_6, PIN_OUTPUT);
	MGPIO_voidSetMode(PORT_A, PIN_7, PIN_OUTPUT);

	MGPIO_voidSetOutputMode(PORT_A, PIN_0, PUSH_PULL, LOW_SPEED);
	MGPIO_voidSetOutputMode(PORT_A, PIN_1, PUSH_PULL, LOW_SPEED);
	MGPIO_voidSetOutputMode(PORT_A, PIN_2, PUSH_PULL, LOW_SPEED);
	MGPIO_voidSetOutputMode(PORT_A, PIN_3, PUSH_PULL, LOW_SPEED);
	MGPIO_voidSetOutputMode(PORT_A, PIN_4, PUSH_PULL, LOW_SPEED);
	MGPIO_voidSetOutputMode(PORT_A, PIN_5, PUSH_PULL, LOW_SPEED);
	MGPIO_voidSetOutputMode(PORT_A, PIN_6, PUSH_PULL, LOW_SPEED);
	MGPIO_voidSetOutputMode(PORT_A, PIN_7, PUSH_PULL, LOW_SPEED);

	OS_u8CreateTask(&app_LED0, 20, 0, 0);
	OS_u8CreateTask(&app_LED1, 40, 1, 20);
	OS_u8CreateTask(&app_LED2, 80, 2, 40);
	OS_u8CreateTask(&app_LED3, 100, 3, 80);
	OS_u8CreateTask(&app_LED4, 120, 4, 100);
	OS_u8CreateTask(&app_LED5, 140, 5, 120);
	OS_u8CreateTask(&app_LED6, 160, 6, 140);
	OS_u8CreateTask(&app_LED7, 180, 7, 160);

	StartOS();

	while(1)
	{

	}

	return 0;
}
