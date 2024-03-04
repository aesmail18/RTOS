/*
 *===========================================================================================
 *	@project	RTOS
 *	@platform	ARM
 *	@module		STM32F401ccub
 *	@driver		MGPIO_program.c
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

#include "MGPIO_private.h"
#include "MGPIO_config.h"
#include "MGPIO_interface.h"



void MGPIO_voidSetMode(PORT_NAME_t enumPortName, PIN_NUM_t enumPinNum, PIN_MODE_t enumPinMode)
{
	switch (enumPortName)
	{
	case PORT_A:
		if (enumPinNum < PIN_13)
		{
			GPIOA->MODER &= ~(TWO_BIT_MASK << enumPinNum * 2);
			GPIOA->MODER |= (enumPinMode << enumPinNum * 2);
		}
		else
		{
			// Do Nothing: JTAG Protection

		}
		break;
	case PORT_B:
		if (enumPinNum < PIN_2 || enumPinNum > PIN_4)
		{
			GPIOB->MODER &= ~(TWO_BIT_MASK << enumPinNum * 2);
			GPIOB->MODER |= (enumPinMode << enumPinNum * 2);
		}
		else
		{
			// Do Nothing: JTAG Protection
		}
		break;
	case PORT_C:
		GPIOC->MODER &= ~(TWO_BIT_MASK << enumPinNum*2);
		GPIOC->MODER |= (enumPinMode << enumPinNum * 2);
		break;
	}
}
void MGPIO_voidSetOutputMode(PORT_NAME_t enumPortName, PIN_NUM_t enumPinNum, PIN_OUTPUT_MODE_t enumOutMode, PIN_SPEED_t enumPinSpeed)
{
	switch (enumPortName)
	{
	case PORT_A:
		if (enumPinNum < PIN_13)
		{
			switch (enumOutMode)
			{
			case PUSH_PULL:
				GPIOA->OTYPER &= ~(1 << enumPinNum);
				break;
			case OPEN_DRAIN:
				GPIOA->OTYPER |= (1 << enumPinNum);
				break;
			}
			GPIOA->OSPEEDR &= ~(TWO_BIT_MASK << enumPinNum * 2);
			GPIOA->OSPEEDR |= (enumPinSpeed << enumPinNum * 2);
		}
		else
		{
			// Do Nothing: JTAG Protection

		}
		break;
	case PORT_B:
		if (enumPinNum < PIN_2 || enumPinNum > PIN_4)
		{
			switch (enumOutMode)
			{
			case PUSH_PULL:
				GPIOB->OTYPER &= ~(1 << enumPinNum);
				break;
			case OPEN_DRAIN:
				GPIOB->OTYPER |= (1 << enumPinNum);
				break;
			}
			GPIOB->OSPEEDR &= ~(TWO_BIT_MASK << enumPinNum * 2);
			GPIOB->OSPEEDR |= (enumPinSpeed << enumPinNum * 2);
		}
		else
		{
			// Do Nothing: JTAG Protection
		}
		break;
	case PORT_C:
		switch (enumOutMode)
		{
		case PUSH_PULL:
			GPIOB->OTYPER &= ~(1 << enumPinNum);
			break;
		case OPEN_DRAIN:
			GPIOB->OTYPER |= (1 << enumPinNum);
			break;
		}
		GPIOC->OSPEEDR &= ~(TWO_BIT_MASK << enumPinNum * 2);
		GPIOC->OSPEEDR |= (enumPinSpeed << enumPinNum * 2);
		break;
	}
}
void MGPIO_voidSetInputMode(PORT_NAME_t enumPortName, PIN_NUM_t enumPinNum, PIN_INPUT_MODE_t enumInputMode, PIN_SPEED_t enumPinSpeed)
{
	switch (enumPortName)
	{
	case PORT_A:
		if (enumPinNum < PIN_13)
		{
			GPIOA->PUPDR &= ~(TWO_BIT_MASK << enumPinNum * 2);
			GPIOA->PUPDR |= (enumInputMode << enumPinNum * 2);
			GPIOA->OSPEEDR &= ~(TWO_BIT_MASK << enumPinNum * 2);
			GPIOA->OSPEEDR |= (enumPinSpeed << enumPinNum * 2);
		}
		else
		{
			// Do Nothing: JTAG Protection
		}
		break;
	case PORT_B:
		if (enumPinNum < PIN_2 || enumPinNum > PIN_4)
		{
			GPIOB->PUPDR &= ~(TWO_BIT_MASK << enumPinNum * 2);
			GPIOB->PUPDR |= (enumInputMode << enumPinNum * 2);
			GPIOB->OSPEEDR &= ~(TWO_BIT_MASK << enumPinNum * 2);
			GPIOB->OSPEEDR |= (enumPinSpeed << enumPinNum * 2);
		}

		break;
	case PORT_C:
		GPIOA->PUPDR &= ~(TWO_BIT_MASK << enumPinNum * 2);
		GPIOA->PUPDR |= (enumInputMode << enumPinNum * 2);
		GPIOC->OSPEEDR &= ~(TWO_BIT_MASK << enumPinNum * 2);
		GPIOC->OSPEEDR |= (enumPinSpeed << enumPinNum * 2);
		break;
	}
}
void MGPIO_voidWritePin(PORT_NAME_t enumPortName, PIN_NUM_t enumPinNum, PIN_OUTPUT_t u8Data)
{
	switch (enumPortName)
	{
	case PORT_A:
		if (enumPinNum < PIN_13)
		{
			switch (u8Data)
			{
			case OUTPUT_HIGH: GPIOA->ODR |= (1 << enumPinNum);
			break;
			case OUTPUT_LOW: GPIOA->ODR &= ~(1 << enumPinNum);
			break;
			}
		}
		else
		{
			// Do Nothing: JTAG Protection
		}
		break;
	case PORT_B:
		if (enumPinNum < PIN_2 || enumPinNum > PIN_4)
		{
			switch (u8Data)
			{
			case OUTPUT_HIGH: GPIOB->ODR |= (1 << enumPinNum);
			break;
			case OUTPUT_LOW: GPIOB->ODR &= ~(1 << enumPinNum);
			break;
			}
		}
		else
		{
			// Do Nothing: JTAG Protection
		}
		break;
	case PORT_C:
		switch (u8Data)
		{
		case OUTPUT_HIGH: GPIOC->ODR |= (1 << enumPinNum);
		break;
		case OUTPUT_LOW: GPIOC->ODR &= ~(1 << enumPinNum);
		break;
		}
		break;
	}
}
void MGPIO_voidTogglePin(PORT_NAME_t enumPortName, PIN_NUM_t enumPinNum)
{
	switch (enumPortName)
	{
	case PORT_A:
		if (enumPinNum < PIN_13)
		{
			GPIOA->ODR ^= (1 << enumPinNum);
		}
		else
		{
			// Do Nothing: JTAG Protection
		}
		break;
	case PORT_B:
		if (enumPinNum < PIN_2 || enumPinNum > PIN_4)
		{
			 GPIOB->ODR ^= (1 << enumPinNum);
		}
		else
		{
			// Do Nothing: JTAG Protection
		}
		break;
	case PORT_C:
		GPIOC->ODR ^= (1 << enumPinNum);
		break;
	}
}

void MGPIO_voidReadPin(PORT_NAME_t enumPortName, PIN_NUM_t enumPinNum, uint8* u8Data)
{
	switch (enumPortName)
	{
	case PORT_A:
		if (enumPinNum < PIN_13)
		{
			*u8Data = GET_BIT(GPIOA->IDR, enumPinNum);
		}
		else
		{
			// Do Nothing: JTAG Protection
		}
		break;
	case PORT_B:
		if (enumPinNum < PIN_2 || enumPinNum > PIN_4)
		{
			*u8Data = GET_BIT(GPIOB->IDR, enumPinNum);
		}
		else
		{
			// Do Nothing: JTAG Protection
		}
		break;
	case PORT_C:
		*u8Data = GET_BIT(GPIOC->IDR, enumPinNum);
		break;
	}
}

void MGPIO_voidSetResetPin(PORT_NAME_t enumPortName, PIN_NUM_t enumPinNum, PIN_SETRESET_t u8Data)
{
	switch (enumPortName)
	{
	case PORT_A:
		if (enumPinNum < PIN_13)
		{
			switch (u8Data)
			{
			case PIN_SET: GPIOA->BSRR |= (1 << enumPinNum);
			break;
			case PIN_RESET: GPIOA->BSRR |= (1 << (enumPinNum + SKIP_TO_BIT_16));
			break;
			}
		}
		else
		{
			// Do Nothing: JTAG Protection
		}
		break;
	case PORT_B:
		if (enumPinNum < PIN_2 || enumPinNum > PIN_4)
		{
			switch (u8Data)
			{
			case PIN_SET: GPIOB->BSRR |= (1 << enumPinNum);
			break;
			case PIN_RESET: GPIOB->BSRR |= (1 << (enumPinNum + SKIP_TO_BIT_16));
			break;
			}
		}
		else
		{
			// Do Nothing: JTAG Protection
		}
		break;
	case PORT_C:
		switch (u8Data)
		{
		case PIN_SET: GPIOC->BSRR |= (1 << enumPinNum);
		break;
		case PIN_RESET: GPIOC->BSRR |= (1 << (enumPinNum + SKIP_TO_BIT_16));
		break;
		}
		break;
	}
}
