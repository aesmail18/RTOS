/*
 *===========================================================================================
 *	@project	RTOS
 *	@platform	ARM
 *	@module		STM32F401ccub
 *	@driver		MRCC_private.h
 *	@version	1.0.0
 *	@brief		Registers and private macros
 *  @layer      MCAL
 *	@fun		functions: .......................................................
 *	@create		3 Mar 2024		6:00
 *	@author		Ahmed Esmail
 *	@last		Last change: write the macro  @ 4 Mar 2024		23:00
 *===========================================================================================
 */
#ifndef MRCC_PRIVATE_H_
#define MRCC_PRIVATE_H_

#define RCC_BASE_ADDRESS 		0x40023800

typedef struct{
	uint32 CR;
	uint32 PLLCFGR;
	uint32 CFGR;
	uint32 CIR;
	uint32 AHB1RSTR;
	uint32 AHB2RSTR;
	uint32 reserved0;
	uint32 reserved1;
	uint32 APB1RSTR;
	uint32 APB2RSTR;
	uint32 reserved2;
	uint32 reserved3;
	uint32 AHB1ENR;
	uint32 AHB2ENR;
	uint32 reserved4;
	uint32 reserved5;
	uint32 APB1ENR;
	uint32 APB2ENR;
	uint32 reserved6;
	uint32 reserved7;
	uint32 AHB1LPENR;
	uint32 AHB2LPENR;
	uint32 reserved8;
	uint32 reserved9;
	uint32 APB1LPENR;
	uint32 APB2LPENR;
	uint32 reserved10;
	uint32 reserved11;
	uint32 BDCR;
	uint32 CSR;
	uint32 reserved12;
	uint32 reserved13;
	uint32 SSCGR;
	uint32 PLLI2SCFGR;
	uint32 reserved14;
	uint32 DCKCFGR;
}RCC_t;

#define RCC_BYP			18
#define RCC_HSERDY 		17
#define RCC_HSEON 		16
#define RCC_HSIRDY		1
#define RCC_HSION		0
#define SWITCH_MASK 	0xFFFFFFFC
#define RCC_HSE			1
#define RCC_HSI			0

#define RCC ((volatile RCC_t*)(RCC_BASE_ADDRESS))

#endif /* MRCC_PRIVATE_H_ */
