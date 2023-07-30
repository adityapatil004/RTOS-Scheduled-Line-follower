
#ifndef DIO_H_
#define DIO_H_

#define HIGH 1
#define LOW  0
#define INPUT 0
#define OUTPUT 1
#define ALTERNATE_FUNCTION 2
#define ANALOG 3
#define GPIOAEN 0
#define GPIOBEN 1
#define GPIOCEN 2
#define GPIODEN 3
#define GPIOEEN 4
#define GPIOHEN 7
#define NO_PUPD 0
#define PULL_UP 1
#define PULL_DOWN 2
#define RESERVED 3


int GPIO_digital_read(GPIO_TypeDef* GPIOx, int Pin_No);
void GPIO_digital_write(GPIO_TypeDef* GPIOx,int Pin_No, int Pin_Status);
void GPIO_pin_mode(GPIO_TypeDef* GPIOx,int Pin_no, int mode);
void GPIO_clock_enable(GPIO_TypeDef* GPIOx);
void GPIO_Alternate_func_select(GPIO_TypeDef* GPIOx,int Pin_No,int AFR_Type);
void GPIO_pin_PUPD(GPIO_TypeDef* GPIOx,int Pin_no, int PUPD_mode);

#endif /*DIO_H_ */
