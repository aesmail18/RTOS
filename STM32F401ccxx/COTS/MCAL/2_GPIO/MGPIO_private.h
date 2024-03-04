/*
 *===========================================================================================
 *	@project	RTOS
 *	@platform	ARM
 *	@module		STM32F401ccub
 *	@driver		MGPIO_private.h
 *	@version	1.0.0
 *	@brief		Registers
 *  @layer      MCAL
 *	@fun		functions: .......................................................
 *	@create		3 Mar 2024		6:00
 *	@author		Ahmed Esmail
 *	@last		Last change: write the Addresses  @ 4 Mar 2024		23:00
 *===========================================================================================
 */
#ifndef MGPIO_PRIVATE_H_
#define MGPIO_PRIVATE_H_

#define GPIOA_BASE_ADDRESS	0x40020000
#define GPIOB_BASE_ADDRESS	0x40020400
#define GPIOC_BASE_ADDRESS	0x40020800

#define TWO_BIT_MASK 	3
#define SKIP_TO_BIT_16  16
typedef struct
{
	uint32 MODER;
	uint32 OTYPER;
	uint32 OSPEEDR;
	uint32 PUPDR;
	uint32 IDR;
	uint32 ODR;
	uint32 BSRR;
	uint32 LCKR;
	uint32 AFRL;
	uint32 AFRH;
}GPIO_t;

#define GPIOA	((volatile GPIO_t*)(GPIOA_BASE_ADDRESS))
#define GPIOB	((volatile GPIO_t*)(GPIOB_BASE_ADDRESS))
#define GPIOC	((volatile GPIO_t*)(GPIOC_BASE_ADDRESS))

#endif /* MGPIO_PRIVATE_H_ */
