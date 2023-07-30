#include "stm32f4xx.h"
#include "DIO.h"
#include <stdio.h>

int GPIO_digital_read(GPIO_TypeDef* GPIOx, int Pin_No)
{
	int state;

	if (GPIOx->IDR & 1U<<(Pin_No))
	{
		state=1;
	}

	else
	{
		state=0;
	}

	return state;
}



void GPIO_pin_mode(GPIO_TypeDef* GPIOx,int Pin_no, int mode)
{
  switch(mode)
  {
  case 0:
	  GPIOx->MODER&=~(1U<<(2*Pin_no));
	  GPIOx->MODER&=~(1U<<((2*Pin_no)+1));
      break;

  case 1:
	  GPIOx->MODER|=(1U<<(2*Pin_no));
	  GPIOx->MODER&=~(1U<<((2*Pin_no)+1));
      break;

  case 2:
	  GPIOx->MODER|=(2U<<(2*Pin_no));
	  break;

  case 3:
	  GPIOx->MODER|=(3U<<(2*Pin_no));
	  break;
  }

}



void GPIO_clock_enable(GPIO_TypeDef* GPIOx)
{
	switch((uint32_t)(GPIOx))
	{
	case (uint32_t)(GPIOA):
		RCC->AHB1ENR|=1U<<GPIOAEN;
		break;

	case (uint32_t)(GPIOB):
		RCC->AHB1ENR|=1U<<GPIOBEN;
		break;

	case (uint32_t)(GPIOC):
		RCC->AHB1ENR|=1U<<GPIOCEN;
		break;

	case (uint32_t)(GPIOD):
		RCC->AHB1ENR|=1U<<GPIODEN;
	    break;

	case (uint32_t)(GPIOE):
		RCC->AHB1ENR|=1U<<GPIOEEN;
		break;

	case (uint32_t)(GPIOH):
		RCC->AHB1ENR|=1U<<GPIOHEN;
		break;
	}
}


void GPIO_digital_write(GPIO_TypeDef* GPIOx,int Pin_No, int Pin_Status)
{

	if (Pin_Status==1)
	{
		GPIOx->BSRR|=(1U<<Pin_No);
	}
	else if(Pin_Status==0)
	{
		GPIOx->BSRR|=(1U<<(Pin_No+16));
	}


}


void GPIO_Alternate_func_select(GPIO_TypeDef* GPIOx,int Pin_No,int AFR_Type)
{

	if(0<=Pin_No<=7)
	{
        GPIOx->AFR[0]=(GPIOx->AFR[0])&(~(15U<<(4*Pin_No)))|(AFR_Type<<(4*Pin_No));
	}
	else
	{
		GPIOx->AFR[1]=(GPIOx->AFR[1])&(~(15U<<(4*Pin_No)))|(AFR_Type<<(4*Pin_No));
	}
}


void GPIO_pin_PUPD(GPIO_TypeDef* GPIOx,int Pin_no, int PUPD_mode)
{
  switch(PUPD_mode)
  {
  case 0:
	  GPIOx->PUPDR&=~(1U<<(2*Pin_no));
	  GPIOx->PUPDR&=~(1U<<((2*Pin_no)+1));
      break;

  case 1:
	  GPIOx->PUPDR|=(1U<<(2*Pin_no));
	  GPIOx->PUPDR&=~(1U<<((2*Pin_no)+1));
      break;

  case 2:
	  GPIOx->PUPDR|=(2U<<(2*Pin_no));
	  break;

  case 3:
	  GPIOx->PUPDR|=(3U<<(2*Pin_no));
	  break;
  }

}
