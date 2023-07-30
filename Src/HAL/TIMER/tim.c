#include "stm32f4xx.h"
#include "tim.h"
#include <stdio.h>

#define TIM2EN 0
#define TIM3EN 1
#define TIM4EN 2
#define TIM5EN 3
#define TIM9EN 16
#define TIM10EN 17
#define TIM11EN 18

#define CR1_CEN 0
#define CC1E 0
#define CC2E 4
#define CC3E 8
#define CC4E 12

/*
void TIMx_clock_enable(TIM_TypeDef* TIMx)
{
    /*Enable clock access to timer 2*/
/*
	switch((uint32_t)(TIMx))
	{
	case (uint32_t)(TIM2):
			RCC->APB1ENR|=1U<<TIM2EN;
	break;

	case (uint32_t)(TIM3):
			RCC->APB1ENR|=1U<<TIM3EN;
	break;

	case (uint32_t)(TIM4):
			RCC->APB1ENR|=1U<<TIM4EN;
	break;

	case (uint32_t)(TIM5):
			RCC->APB1ENR|=1U<<TIM5EN;
	break;

	case (uint32_t)(TIM9):
			RCC->APB2ENR|=1U<<TIM9EN;
	break;

	case (uint32_t)(TIM10):
			RCC->APB2ENR|=1U<<TIM10EN;
	break;

	case (uint32_t)(TIM11):
			RCC->APB2ENR|=1U<<TIM11EN;
	break;

	}
}*/


void TIMx_init_PWM(TIM_TypeDef* TIMx, uint32_t ch, uint32_t DC )
{
    /*Enable clock access to timer 2*/

	switch((uint32_t)(TIMx))
	{
	case (uint32_t)(TIM2):
			RCC->APB1ENR|=1U<<TIM2EN;
	break;

	case (uint32_t)(TIM3):
			RCC->APB1ENR|=1U<<TIM3EN;
	break;

	case (uint32_t)(TIM4):
			RCC->APB1ENR|=1U<<TIM4EN;
	break;

	case (uint32_t)(TIM5):
			RCC->APB1ENR|=1U<<TIM5EN;
	break;

	case (uint32_t)(TIM9):
			RCC->APB2ENR|=1U<<TIM9EN;
	break;

	case (uint32_t)(TIM10):
			RCC->APB2ENR|=1U<<TIM10EN;
	break;

	case (uint32_t)(TIM11):
			RCC->APB2ENR|=1U<<TIM11EN;
	break;

	}
	/*Set the Prescaler value*/
	TIMx->PSC=2-1; //16000000/2=8000000
	/*Set the auto-reload value*/
	TIMx->ARR = 1024-1; // 8000000/1024=1=update event duration

	/*Set PWM mode*/
	TIMx->CCMR1&=~(7U<<4);
	TIMx->CCMR1 |=6U<<4;

	/*Set CCR1 value*/
	TIMx->CCR1= (uint32_t)((TIMx->ARR*DC)/100);

	/*Enable Capture/Compare output at channel1*/
	switch (ch)
	{

	case 1:
		TIMx->CCER|=1U<<CC1E;
		break;

	case 2:
		TIMx->CCER|=1U<<CC2E;
		break;

	case 3:
		TIMx->CCER|=1U<<CC3E;
		break;

	case 4:
		TIMx->CCER|=1U<<CC4E;
		break;

	}

	/*Clear the counter*/
	TIMx->CNT=0;
	/*Enable timer*/
	TIMx->CR1|= 1U<<CR1_CEN;
}


void TIMx_write_PWM(TIM_TypeDef* TIMx, uint32_t ch, uint32_t DC  )
{

	/*Set CCR value*/
	switch (ch)
	{

	case 1:
		TIMx->CCR1= (uint32_t)((TIMx->ARR*DC)/100);
		break;

	case 2:
		TIMx->CCR2= (uint32_t)((TIMx->ARR*DC)/100);
		break;

	case 3:
		TIMx->CCR3= (uint32_t)((TIMx->ARR*DC)/100);
		break;

	case 4:
		TIMx->CCR4= (uint32_t)((TIMx->ARR*DC)/100);
		break;

	}

	/*Enable Capture/Compare output at channel1*/
	switch (ch)
	{

	case 1:
		TIMx->CCER|=1U<<CC1E;
		break;

	case 2:
		TIMx->CCER|=1U<<CC2E;
		break;

	case 3:
		TIMx->CCER|=1U<<CC3E;
		break;

	case 4:
		TIMx->CCER|=1U<<CC4E;
		break;

	}

	/*Clear the counter*/
	//TIMx->CNT=0;
	/*Enable timer*/
	//TIMx->CR1|= 1U<<CR1_CEN;
}


void TIMx_init_PWM_freq(TIM_TypeDef* TIMx, uint32_t ch, uint32_t Presc, uint32_t ARR)
{
    /*Enable clock access to timer 2*/
	switch((uint32_t)(TIMx))
	{
	case (uint32_t)(TIM2):
			RCC->APB1ENR|=1U<<TIM2EN;
	break;

	case (uint32_t)(TIM3):
			RCC->APB1ENR|=1U<<TIM3EN;
	break;

	case (uint32_t)(TIM4):
			RCC->APB1ENR|=1U<<TIM4EN;
	break;

	case (uint32_t)(TIM5):
			RCC->APB1ENR|=1U<<TIM5EN;
	break;

	case (uint32_t)(TIM9):
			RCC->APB2ENR|=1U<<TIM9EN;
	break;

	case (uint32_t)(TIM10):
			RCC->APB2ENR|=1U<<TIM10EN;
	break;

	case (uint32_t)(TIM11):
			RCC->APB2ENR|=1U<<TIM11EN;
	break;

	}
	/*Set the Prescaler value*/
	TIMx->PSC=Presc-1; //16000000/2=8000000
	/*Set the auto-reload value*/
	TIMx->ARR = ARR-1; // 8000000/1024=1=update event duration

	/*Set PWM mode*/

	switch (ch)
	{

	case 1:
		TIMx->CCMR1&=~(7U<<4);
		TIMx->CCMR1 |=6U<<4;
		break;

	case 2:
		TIMx->CCMR1&=~(7U<<12);
		TIMx->CCMR1 |=6U<<12;
		break;

	case 3:
		TIMx->CCMR2&=~(7U<<4);
		TIMx->CCMR2 |=6U<<4;
		break;

	case 4:
		TIMx->CCMR2&=~(7U<<12);
		TIMx->CCMR2 |=6U<<12;
		break;

	}



	/*Set CCR value*/
	switch (ch)
	{

	case 1:
		TIMx->CCR1= 0;
		break;

	case 2:
		TIMx->CCR2= 0;
		break;

	case 3:
		TIMx->CCR3= 0;
		break;

	case 4:
		TIMx->CCR4= 0;
		break;

	}

	/*Enable Capture/Compare output at channel1*/
	switch (ch)
	{

	case 1:
		TIMx->CCER|=1U<<CC1E;
		break;

	case 2:
		TIMx->CCER|=1U<<CC2E;
		break;

	case 3:
		TIMx->CCER|=1U<<CC3E;
		break;

	case 4:
		TIMx->CCER|=1U<<CC4E;
		break;

	}

	/*Clear the counter*/
	TIMx->CNT=0;
	/*Enable timer*/
	TIMx->CR1|= 1U<<CR1_CEN;
}


void TIMx_init(TIM_TypeDef* TIMx,uint32_t Presc, uint32_t ARR)
{
    /*Enable clock access to timer 2*/
	switch((uint32_t)(TIMx))
	{
	case (uint32_t)(TIM2):
			RCC->APB1ENR|=1U<<TIM2EN;
	break;

	case (uint32_t)(TIM3):
			RCC->APB1ENR|=1U<<TIM3EN;
	break;

	case (uint32_t)(TIM4):
			RCC->APB1ENR|=1U<<TIM4EN;
	break;

	case (uint32_t)(TIM5):
			RCC->APB1ENR|=1U<<TIM5EN;
	break;

	case (uint32_t)(TIM9):
			RCC->APB2ENR|=1U<<TIM9EN;
	break;

	case (uint32_t)(TIM10):
			RCC->APB2ENR|=1U<<TIM10EN;
	break;

	case (uint32_t)(TIM11):
			RCC->APB2ENR|=1U<<TIM11EN;
	break;

	}
	/*Set the Prescaler value*/
	TIMx->PSC=Presc-1; //16000000/1600=10000
	/*Set the auto-reload value*/
	TIMx->ARR = ARR-1; // 10000/10000=1=update event duration
	/*Clear the counter*/
	TIMx->CNT=0;
	/*Enable timer*/
	TIMx->CR1|= 1U<<CR1_CEN;
}



void TIMx_init_output_toggle_freq(TIM_TypeDef* TIMx, uint32_t ch, uint32_t Presc, uint32_t ARR)
{

    /*Enable clock access to timer 2*/
	switch((uint32_t)(TIMx))
	{
	case (uint32_t)(TIM2):
			RCC->APB1ENR|=1U<<TIM2EN;
	break;

	case (uint32_t)(TIM3):
			RCC->APB1ENR|=1U<<TIM3EN;
	break;

	case (uint32_t)(TIM4):
			RCC->APB1ENR|=1U<<TIM4EN;
	break;

	case (uint32_t)(TIM5):
			RCC->APB1ENR|=1U<<TIM5EN;
	break;

	case (uint32_t)(TIM9):
			RCC->APB2ENR|=1U<<TIM9EN;
	break;

	case (uint32_t)(TIM10):
			RCC->APB2ENR|=1U<<TIM10EN;
	break;

	case (uint32_t)(TIM11):
			RCC->APB2ENR|=1U<<TIM11EN;
	break;

	}
	/*Set the Prescaler value*/
	TIMx->PSC=Presc-1; //16000000/1600=10000
	/*Set the auto-reload value*/
	TIMx->ARR = ARR-1; // 10000/10000=1=update event duration

	/*Set output compare toggle mode*/
	TIMx->CCMR1&=~(7U<<4);
	TIMx->CCMR1 |=3U<<4;

	/*Enable Capture/Compare output at channel1*/
	switch (ch)
	{

	case 1:
		TIMx->CCER|=1U<<CC1E;
		break;

	case 2:
		TIMx->CCER|=1U<<CC2E;
		break;

	case 3:
		TIMx->CCER|=1U<<CC3E;
		break;

	case 4:
		TIMx->CCER|=1U<<CC4E;
		break;

	}
	/*Clear the counter*/
	TIMx->CNT=0;
	/*Enable timer*/
	TIMx->CR1|= 1U<<CR1_CEN;
}

