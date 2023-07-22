

#include "stm32f4xx.h"
#include "Sensor_driver.h"
#include "Robot_Drive.h"
#include "Line_Detection.h"
#include "freertos.h"
#include "semphr.h"
#include "task.h"
#include "queue.h"



TaskHandle_t Linear;
TaskHandle_t READ;
TaskHandle_t Curve;

QueueHandle_t L_Queue;
QueueHandle_t C_Queue;


void vCurvilinear_drive(void *pvParameters);
void vLinear_drive(void *pvParameters);
void vRead_Task(void *pvParameters);

//struct Line_detection_stat L;


void vCurvilinear_drive(void *pvParameters)
	{

	  int32_t valueReceived;
	  const TickType_t xTicksToWait = pdMS_TO_TICKS(100);
while(1)                                                                //Without these while loops the tasks/threads don't work as desired. The defining characteristic of a task/thread has to be that it will be performed cyclically
{
	  xQueueReceive(C_Queue, &valueReceived, xTicksToWait);
	  if (valueReceived==1)
	  {
		  Robot_Drive(RIGHT,70);
	    }
	  else if (valueReceived==0)
	  {
		  Robot_Drive(LEFT,70);
	    }
	  vTaskPrioritySet(Curve,1);
}
	}


void vLinear_drive(void *pvParameters)
	{

	  int32_t valueReceived;
	  const TickType_t xTicksToWait = pdMS_TO_TICKS(100);
while(1)
{
	  xQueueReceive(L_Queue, &valueReceived, xTicksToWait);
	  if (valueReceived==1)
	  {
		  Robot_Drive(FORWARD,70);
	    }
	  else if (valueReceived==0)
	  {
		  Robot_Drive(STOP,70);
	    }

	vTaskPrioritySet(Linear,1);
}
	}


void vRead_Task(void *pvParameters)
	{

	struct Line_detection_stat L;
	int i;
	 BaseType_t qStatus_l;
	  BaseType_t qStatus_c;
	  int32_t drive_L;
	  int32_t drive_C;

	  while(1)
	  {
	  L=Line_Detect();

	  //If none of the sensors detects black line, then go straight
	  if ((L.Line_Left==FALSE)&&(L.Line_Right==FALSE))
	  {
	   drive_L=1;
	   qStatus_l=xQueueSend(L_Queue,&drive_L,0);
	   vTaskPrioritySet(Linear,3);
	  }

	  //If right sensor detects black line, then turn right
	  else if ((L.Line_Left==FALSE)&&(L.Line_Right==TRUE))
	  {
	   drive_C=1;
	   qStatus_c=xQueueSend(C_Queue,&drive_C,0);
	   vTaskPrioritySet(Curve,3);
	  }

	  //If left sensor detects black line, then turn left
	  else if ((L.Line_Left==TRUE)&&(L.Line_Right==FALSE))
	  {
	   drive_C=0;
	   qStatus_c=xQueueSend(C_Queue,&drive_C,0);
	   vTaskPrioritySet(Curve,3);
	  }

	  else
	  {
		  Robot_Drive(STOP,70);
	  }
	  }

	}



void main()
{

	Line_Detection_init();
	Robot_Drive_Init();
	  xTaskCreate(vRead_Task,"Input read Task",128,NULL,2,&READ);
	  xTaskCreate(vCurvilinear_drive,"Curvilinear driving task",128,NULL,1,&Curve);
	  xTaskCreate(vLinear_drive,"Linear driving Task",128,NULL,1,&Linear);

	  L_Queue= xQueueCreate(5,sizeof(int32_t));   //These Queues if not defined properly will lead to data not being transferred well.
	  C_Queue= xQueueCreate(5,sizeof(int32_t));


	  vTaskStartScheduler();
}
