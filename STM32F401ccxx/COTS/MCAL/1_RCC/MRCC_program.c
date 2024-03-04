/*
 *===========================================================================================
 *	@project	RTOS
 *	@platform	ARM
 *	@module		STM32F401ccub
 *	@driver		MRCC_program.c
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
#include "MRCC_config.h"
#include "MRCC_private.h"
#include "MRCC_interface.h"

void MRCC_voidInit()
{
#if SYS_CLK == RCC_HSE
	// Bypass -> Crystal Oscillator (2 Pins) / RC (1 Pin)
	CLR_BIT(RCC->CR, RCC_BYP);
	RCC->CR &= ~(1 << RCC_BYP);
	RCC->CR |= (1 << RCC_HSEON);
	while(!GET_BIT(RCC->CR, RCC_HSERDY));
	RCC->CFGR &= SWITCH_MASK;
	RCC->CFGR |= RCC_HSE;
#elif SYS_CLK == RCC_HSI
	RCC->CR &= ~(1 << RCC_HSEON);
	RCC->CR |= (1 << RCC_HSION);
	while(!GET_BIT(RCC->CR, RCC_HSIRDY));
	RCC->CFGR &= SWITCH_MASK;
#endif
}
void MRCC_voidEnable(BUS_t copy_bus,uint16 copy_u16peripheral)
{
	switch (copy_bus)
	{
	case AHB1:
		RCC->AHB1ENR |= (1 << copy_u16peripheral);
		break;
	case AHB2:
		RCC->AHB2ENR |= (1 << copy_u16peripheral);
		break;
	case APB1:
		RCC->APB1ENR |= (1 << copy_u16peripheral);
		break;
	case APB2:
		RCC->APB2ENR |= (1 << copy_u16peripheral);
		break;
	default:
		break;
	}
}
void MRCC_voidDisable(BUS_t copy_bus,uint16 copy_u16peripheral)
{
	switch (copy_bus)
		{
		case AHB1:
			RCC->AHB1ENR &= ~(1 << copy_u16peripheral);
			break;
		case AHB2:
			RCC->AHB2ENR &= ~(1 << copy_u16peripheral);
			break;
		case APB1:
			RCC->APB1ENR &= ~(1 << copy_u16peripheral);
			break;
		case APB2:
			RCC->APB2ENR &= ~(1 << copy_u16peripheral);
			break;
		default:
			break;
		}
}


