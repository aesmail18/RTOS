#include "STD_Types.h"
#include "BIT_Math.h"

#include "MSYSTICK_interface.h"

#include "OS_prv.h"
#include "OS_int.h"
#include "OS_cfg.h"


Task  SystemTask[Max_num_Of_Tasks]={0};
uint8 TaskTiming[Max_num_Of_Tasks];
Task  Empty={0};


void StartOS(void)
{
	// setintervalPeriodic(ticktime,scheduler);
	MSYSTICK_voidSetInterval_periodic(TICK_TIME, &Scheduler);
}


uint8 OS_u8CreateTask(void(*copy_Handler)(void),uint8 Copy_u8Periodicty,uint8 Copy_u8Periority,uint8 Copy_u8FirstDelay)
{
	uint8 Local_errorState=0;
	
	if(Copy_u8Periority < Max_num_Of_Tasks)
	{
		if(SystemTask[Copy_u8Periority].TaskHandler==0)
		{
			SystemTask[Copy_u8Periority].TaskHandler =copy_Handler;
			SystemTask[Copy_u8Periority].periodicty =Copy_u8Periodicty;
			TaskTiming[Copy_u8Periority]            =Copy_u8FirstDelay;
			SystemTask[Copy_u8Periority].RunState   =Ready;
		}
		else
		{
			Local_errorState=2;
			
		}
		
		
		
		
	}
	else
	{
	Local_errorState=1;	
	}
	return Local_errorState;
	
	
}





void Scheduler(void)
{
	
	uint8 Local_u8Counter=0;
	
	for(Local_u8Counter=0;Local_u8Counter<Max_num_Of_Tasks;Local_u8Counter++)
	{
		// is there task ?
		if(SystemTask[Local_u8Counter].TaskHandler !=0)
		{
			if(SystemTask[Local_u8Counter].RunState==Ready)
			{
				if(TaskTiming[Local_u8Counter]==0)
				{
					//RUN the Task
					SystemTask[Local_u8Counter].TaskHandler();
				
					// Reload periodicity
					TaskTiming[Local_u8Counter]= SystemTask[Local_u8Counter].periodicty;
				
				
				}
				else
				{
					TaskTiming[Local_u8Counter]--;
				}
			}
		}
	}
}

void OS_DeleteTask(uint8 Copy_u8Periority)
{
	if(SystemTask[Copy_u8Periority].TaskHandler !=0)
	{
		
		SystemTask[Copy_u8Periority]=Empty;
		
	}
	
}

void SuspendTask(uint8 Copy_u8Periority)
{
	if(SystemTask[Copy_u8Periority].TaskHandler !=0)
	{
		
		SystemTask[Copy_u8Periority].RunState=Suspended;
		
	}
	
	
}

void ResumeTask(uint8 Copy_u8Periority)
{
	if(SystemTask[Copy_u8Periority].TaskHandler !=0)
	{
		
		SystemTask[Copy_u8Periority].RunState=Ready;
		
	}
	
	
}




