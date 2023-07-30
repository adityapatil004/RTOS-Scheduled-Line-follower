#include "stm32f4xx.h"
#include "DIO.h"
#include "tim.h"
#include "Motor_driver.h"

#define PORTB13 13
#define PORTB14 14
#define PORTB15 15
#define PORTB1 1
#define PORTB3 3
#define PORTB4 4

#define RM1 PORTB13
#define RM2 PORTB14
#define LM1 PORTB15
#define LM2 PORTB1
#define RMS PORTB4
#define LMS PORTB3

#define LMS_CH CHANNEL2
#define RMS_CH CHANNEL1

#define TIM2_CH2 1
#define TIM3_CH1 2

//static void RIGHT_MOTOR_DRIVE(int dir, int DC);
//static void LEFT_MOTOR_DRIVE(int dir, int DC);

void Motor_Driver_Init()
{
/*Enable clock access to GPIOA and GPIOB*/
	GPIO_clock_enable(GPIOB);
	GPIO_clock_enable(GPIOA);

	/*Set RM1 pin in Output mode*/
	GPIO_pin_mode(GPIOB,RM1,OUTPUT);

	/*Set RM2 pin in Output mode*/
	GPIO_pin_mode(GPIOB,RM2,OUTPUT);

	/*Set LM1 pin in Output mode*/
	GPIO_pin_mode(GPIOB,LM1,OUTPUT);

	/*Set LM2 pin in Output mode*/
	GPIO_pin_mode(GPIOB,LM2,OUTPUT);

	/*Set RMS in ALTERNATE FUNCTION mode*/
	GPIO_pin_mode(GPIOB,RMS,ALTERNATE_FUNCTION);

	/*Set Alternate function type for RMS as TIM2_CH4*/
	GPIO_Alternate_func_select(GPIOB,RMS,TIM3_CH1);

	/*Set LMS in ALTERNATE FUNCTION mode*/
	GPIO_pin_mode(GPIOB,LMS,ALTERNATE_FUNCTION);

	/*Set Alternate function type for LMS as TIM2_CH3*/
	GPIO_Alternate_func_select(GPIOB,LMS,TIM2_CH2);

	/*Initialize RMS_ch PWM*/
	TIMx_init_PWM_freq(TIM3, RMS_CH, 2, 1024);

	/*Initialize LMS_ch PWM*/
	TIMx_init_PWM_freq(TIM2, LMS_CH, 2, 1024);
}



void LEFT_MOTOR_DRIVE(int dir, int DC)
{
    switch(dir)
    {
    case 1:
		GPIO_digital_write(GPIOB,LM1,HIGH);
		GPIO_digital_write(GPIOB,LM2,LOW);
		break;

    case 0:
		GPIO_digital_write(GPIOB,LM1,LOW);
		GPIO_digital_write(GPIOB,LM2,HIGH);
		break;

    case -1:
		GPIO_digital_write(GPIOB,LM1,LOW);
		GPIO_digital_write(GPIOB,LM2,LOW);
		break;
    }
    TIMx_write_PWM(TIM2, LMS_CH, DC);
}


void RIGHT_MOTOR_DRIVE(int dir, int DC)
{
    switch(dir)
    {
    case 1:
		GPIO_digital_write(GPIOB,RM1,HIGH);
		GPIO_digital_write(GPIOB,RM2,LOW);
		break;

    case 0:
		GPIO_digital_write(GPIOB,RM1,LOW);
		GPIO_digital_write(GPIOB,RM2,HIGH);
		break;

    case -1:
		GPIO_digital_write(GPIOB,RM1,LOW);
		GPIO_digital_write(GPIOB,RM2,LOW);
		break;
    }

    TIMx_write_PWM(TIM3, RMS_CH, DC);
}
