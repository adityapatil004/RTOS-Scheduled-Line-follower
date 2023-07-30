/*
 * Motor_drive.h
 *
 *  Created on: May 28, 2023
 *      Author: Aditya
 */

#ifndef MOTOR_DRIVER_H_
#define MOTOR_DRIVER_H_
#include "DIO.h"

void Motor_Driver_Init();
void RIGHT_MOTOR_DRIVE(int dir, int DC);
void LEFT_MOTOR_DRIVE(int dir, int DC);

#define FORWARD 1
#define BACKWARD 0
#define STOP -1

#endif /* MOTOR_DRIVER_H_ */
