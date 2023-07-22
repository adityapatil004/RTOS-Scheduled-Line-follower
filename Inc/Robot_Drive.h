/*
 * Motor_drive.h
 *
 *  Created on: May 28, 2023
 *      Author: Aditya
 */

#ifndef ROBOT_DRIVE_H_
#define ROBOT_DRIVE_H_
#include "Motor_Driver.h"

#define LEFT 2
#define RIGHT 3


void Robot_Drive_Init();
void Robot_Drive(int dir, int DC);

#endif /* MOTOR_DRIVE_H_ */
