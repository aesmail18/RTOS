/*
 *===========================================================================================
 *	@project	RTOS
 *	@platform	ARM
 *	@module		STM32F401ccub
 *	@driver		MSYSTICK_config.h
 *	@version	1.0.0
 *	@brief		Pre-build configuration
 *  @layer      MCAL
 *	@fun		functions: .......................................................
 *	@create		3 Mar 2024		6:00
 *	@author		Ahmed Esmail
 *	@last		Last change: write the macro  @ 4 Mar 2024		23:00
 *===========================================================================================
 */
#ifndef MSYSTICK_CONFIG_H_
#define MSYSTICK_CONFIG_H_


/**
 * Options: Choose
 * SYSTICK_AHB or
 * SYSTICK_AHB_DIVIDE_8
 */
#define SYSTICK_SOURCE	SYSTICK_AHB_DIVIDE_8

#endif /* MSYSTICK_CONFIG_H_ */
