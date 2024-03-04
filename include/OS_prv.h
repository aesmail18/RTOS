/*
 *===========================================================================================
 *	@project	RTOS
 *	@platform	ARM
 *	@module		STM32F401ccub
 *	@driver		OS_prv.h
 *	@version	1.0.0
 *	@brief		Private struct
 *  @layer      LIBRARY
 *	@fun		functions: ...................................................
 *	@create		3 Mar 2024		6:00
 *	@author		Ahmed Esmail
 *	@last		Last change: Write the data types @ 4 Mar 2024		23:00
 *===========================================================================================
 */
#ifndef _OS_PRV_H
#define _OS_PRV_H
typedef enum
{
	Suspended,
	Ready
}TaskState;

typedef struct
{
	void(*TaskHandler)(void);
	uint32 periodicty;
	uint32 FirstDelay;
	TaskState RunState;

}Task;



#endif
