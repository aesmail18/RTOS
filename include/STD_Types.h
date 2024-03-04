/*
 *===========================================================================================
 *	@project	RTOS
 *	@platform	ARM
 *	@module		STM32F401ccub
 *	@driver		STD_Types.h
 *	@version	1.0.0
 *	@brief		Redefining of data types
 *  @layer      LIBRARY
 *	@fun		functions: ...................................................
 *	@create		3 Mar 2024		6:00
 *	@author		Ahmed Esmail
 *	@last		Last change: Write the data types @ 4 Mar 2024		23:00
 *===========================================================================================
 */
#ifndef  STD_TYPES_H
#define  STD_TYPES_H


typedef void (*pf)(void);

typedef   unsigned char      uint8  ;
typedef   unsigned short int uint16 ;
typedef   unsigned long  int uint32 ;
typedef   signed char        sint8  ;
typedef   signed short int   sint16 ;
typedef   signed long  int   sint32 ;
typedef   float              float32 ;
typedef   double             float64 ;
typedef   long double        float128 ;


typedef enum  
{
	EOK,
	ENOK,
	PARAMRETER_OUT_RANGE,
	PARAMERTE_NULL_PTR
	
}tenuErrrorStatus;

#define NULL			  0
#define NULL_PTR (void *) 0

#endif



