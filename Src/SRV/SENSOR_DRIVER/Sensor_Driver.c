/*
 * Sensor_Driver.c
 *
 *  Created on: May 29, 2023
 *      Author: Aditya
 */
#include "stm32f4xx.h"
#include "DIO.h"
#include "Sensor_Driver.h"

#define PORTB12 12
#define PORTB2 2

#define IRS_L PORTB12
#define IRS_R PORTB2

void Sensor_Driver_Init()
{
	GPIO_clock_enable(GPIOB);
	GPIO_pin_mode(GPIOB, IRS_L, INPUT);
	GPIO_pin_mode(GPIOB, IRS_R, INPUT);
}


int LEFT_SENSOR_STAT()
{
return (GPIO_digital_read(GPIOB, IRS_L));
}

int RIGHT_SENSOR_STAT()
{
return (GPIO_digital_read(GPIOB, IRS_R));
}
