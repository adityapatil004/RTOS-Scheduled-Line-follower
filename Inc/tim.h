/*
 * tim.h
 *
 *  Created on: May 22, 2023
 *      Author: Aditya
 */
//#include "stm32f4xx.h"
#ifndef TIMER_TIM_H_
#define TIMER_TIM_H_

#define CHANNEL1 1
#define CHANNEL2 2
#define CHANNEL3 3
#define CHANNEL4 4


void TIMx_init_PWM(TIM_TypeDef* TIMx,uint32_t ch, uint32_t DC );
void TIMx_write_PWM(TIM_TypeDef* TIMx, uint32_t ch, uint32_t DC );
void TIMx_init_PWM_freq(TIM_TypeDef* TIMx, uint32_t ch, uint32_t Presc, uint32_t ARR);
void TIMx_init(TIM_TypeDef* TIMx,uint32_t Presc, uint32_t ARR);

#define SR_UIF 0
#define GPIOAEN 0
#endif /* TIMER_TIM_H_ */
