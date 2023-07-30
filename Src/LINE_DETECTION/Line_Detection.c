/*
 * IR_Sense.c
 *
 *  Created on: Jun 4, 2023
 *      Author: Aditya
 */


#include "stm32f4xx.h"
#include "Sensor_Driver.h"
#include "Line_Detection.h"

void Line_Detection_init()
{
	Sensor_Driver_Init();
}

struct Line_detection_stat Line_Detect()
{
	struct Line_detection_stat status;
	status.Line_Left=LEFT_SENSOR_STAT();
	status.Line_Right=RIGHT_SENSOR_STAT();
	return status;
}

