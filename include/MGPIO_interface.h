/*
 *===========================================================================================
 *	@project	RTOS
 *	@platform	ARM
 *	@module		STM32F401ccub
 *	@driver		MGPIO_interface.h
 *	@version	1.0.0
 *	@brief		Public functions prototypes and macros
 *  @layer      MCAL
 *	@fun		functions: .......................................................
 *	@create		3 Mar 2024		6:00
 *	@author		Ahmed Esmail
 *	@last		Last change: write the prototypes  @ 4 Mar 2024		23:00
 *===========================================================================================
 */
#ifndef MGPIO_INTERFACE_H_
#define MGPIO_INTERFACE_H_

typedef enum
{
	PORT_A = 0,
	PORT_B,
	PORT_C
}PORT_NAME_t;

typedef enum
{
	PIN_0 = 0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7,
	PIN_8,
	PIN_9,
	PIN_10,
	PIN_11,
	PIN_12,
	PIN_13,
	PIN_14,
	PIN_15
}PIN_NUM_t;

typedef enum
{
	PIN_INPUT = 0,
	PIN_OUTPUT,
	PIN_ALT,
	PIN_ANALOG
}PIN_MODE_t;

typedef enum
{
	PUSH_PULL = 0,
	OPEN_DRAIN
}PIN_OUTPUT_MODE_t;

typedef enum
{
	LOW_SPEED = 0,
	MID_SPEED,
	HI_SPEED,
	V_HI_SPEED
}PIN_SPEED_t;

typedef enum
{
	NO_PULLUP_PULLDOWN = 0,
	PULLUP,
	PULLDOWN
}PIN_INPUT_MODE_t;

typedef enum
{
	OUTPUT_LOW = 0,
	OUTPUT_HIGH,
}PIN_OUTPUT_t;

typedef enum
{
	PIN_RESET = 0,
	PIN_SET,
}PIN_SETRESET_t;

void MGPIO_voidSetMode(PORT_NAME_t enumPortName, PIN_NUM_t enumPinNum, PIN_MODE_t enumPinMode);
void MGPIO_voidSetOutputMode(PORT_NAME_t enumPortName, PIN_NUM_t enumPinNum, PIN_OUTPUT_MODE_t enumOutMode, PIN_SPEED_t enumPinSpeed);
void MGPIO_voidSetInputMode(PORT_NAME_t enumPortName, PIN_NUM_t enumPinNum, PIN_INPUT_MODE_t enumInputMode, PIN_SPEED_t enumPinSpeed);
void MGPIO_voidWritePin(PORT_NAME_t enumPortName, PIN_NUM_t enumPinNum, PIN_OUTPUT_t u8Data);
void MGPIO_voidTogglePin(PORT_NAME_t enumPortName, PIN_NUM_t enumPinNum);
void MGPIO_voidReadPin(PORT_NAME_t enumPortName, PIN_NUM_t enumPinNum, uint8* u8Data);
void MGPIO_voidSetResetPin(PORT_NAME_t enumPortName, PIN_NUM_t enumPinNum, PIN_SETRESET_t u8Data);

#endif /* MGPIO_INTERFACE_H_ */
