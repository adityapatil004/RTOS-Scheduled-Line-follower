



#include "stm32f4xx.h"
#include "DIO.h"
#include "tim.h"
#include "Motor_driver.h"
#include "Robot_Drive.h"

void Robot_Drive_Init()
{
	Motor_Driver_Init();
}


static void Rotate_Motor(int Left_Motor_Dir, int Right_Motor_Dir, int DC )
{
	if (Left_Motor_Dir==1)
	{
		LEFT_MOTOR_DRIVE(1, DC);
	}

	else if (Left_Motor_Dir==0)
	{
		LEFT_MOTOR_DRIVE(0, DC);
	}

	else
	{
		LEFT_MOTOR_DRIVE(-1, DC);
	}


	if (Right_Motor_Dir==1)
	{
		RIGHT_MOTOR_DRIVE(1, DC);
	}

	else if (Right_Motor_Dir==0)
	{
		RIGHT_MOTOR_DRIVE(0, DC);
	}

	else
	{
		RIGHT_MOTOR_DRIVE(-1, DC);
	}
}

void Robot_Drive(int dir, int DC)
{
	if (dir==1)
	{
		Rotate_Motor(FORWARD,FORWARD,DC);
	}

	else if(dir==2)
	{
		Rotate_Motor(BACKWARD,FORWARD,DC);
	}

	else if(dir==3)
	{
		Rotate_Motor(FORWARD,BACKWARD,DC);
	}

	else
	{
		Rotate_Motor(STOP,STOP,DC);
	}
}




