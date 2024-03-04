/*
 *===========================================================================================
 *	@project	RTOS
 *	@platform	ARM
 *	@module		STM32F401ccub
 *	@driver		MSYSTICK_private.h
 *	@version	1.0.0
 *	@brief		Registers
 *  @layer      MCAL
 *	@fun		functions: .......................................................
 *	@create		3 Mar 2024		6:00
 *	@author		Ahmed Esmail
 *	@last		Last change: Registers addresses  @ 4 Mar 2024		23:00
 *===========================================================================================
 */
#ifndef MSYSTICK_PRIVATE_H_
#define MSYSTICK_PRIVATE_H_

#define SYSTICK_BASE_ADDRESS	(0xE000E010)

#define SYSTICK_ENABLE 0
#define TICKINT		1
#define CLKSOURCE	2
#define COUNTFLAG	16


#define SYSTICK_AHB	0
#define SYSTICK_AHB_DIVIDE_8 1

typedef struct
{
	uint32 CTRL;
	uint32 LOAD;
	uint32 VAL;
	uint32 CALIB;
}SYSTICK_t;

#define SYSTICK	((volatile SYSTICK_t*)(SYSTICK_BASE_ADDRESS))


#endif /* MSYSTICK_PRIVATE_H_ */
