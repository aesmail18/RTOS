/*
 *===========================================================================================
 *	@project	RTOS
 *	@platform	ARM
 *	@module		STM32F401ccub
 *	@driver		BIT_Math.h
 *	@version	1.0.0
 *	@brief		public functions like a macros
 *  @layer      LIBRARY
 *	@fun		functions: .......................................................
 *	@create		3 Mar 2024		6:00
 *	@author		Ahmed Esmail
 *	@last		Last change: write the macros  @ 4 Mar 2024		23:00
 *===========================================================================================
 */
#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/*Bit-Math macros*/
#define SET_BIT(REG , BIT)     REG |= 1<<BIT
#define CLR_BIT(REG , BIT)     REG &= ~(1<<BIT)
#define TOG_BIT(REG , BIT)     REG ^= 1<<BIT
#define GET_BIT(REG , BIT)     ((REG >> BIT) & 1)

#define WRITE_BIT(REG , BIT, VAL)    CLR_BIT(REG,BIT) | (val << BIT)

#endif 
