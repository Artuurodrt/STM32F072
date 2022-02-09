/*
 * _HAL_GPIO.h
 *
 *  Created on: Feb 5, 2022
 *      Author: Arturo de los Rios
 */

#ifndef _HAL_GPIO
#define _HAL_GPIO
#include "stm32f072xb.h"


/*Bit Position for 32 bit Registers*/
#define POS32_BIT1 (PINPOS_32[pinNumber])
#define POS32_BIT2 (PINPOS_32[pinNumber]+1)


/*Port Names*/
#define PORTA GPIOA
#define PORTB GPIOB
#define PORTC GPIOC
#define PORTD GPIOD
#define PORTE GPIOE
#define PORTF GPIOF

/*GPIO port mode register (GPIOx_MODER)*/
#define  INPUT_MODE 			((uint32_t)0x00)
#define  GEN_PURPOSE_OUT_MODE   ((uint32_t)0x01)
#define  ALT_FUNCTION_MODE      ((uint32_t)0x02)
#define  ANALOG_MODE  		    ((uint32_t)0x03)


/*GPIO port output type register (GPIOx_OTYPER)*/
#define OUTPUT_PUSH_PULL	 ((uint32_t)0x00)
#define OUTPUT_PULL_DRAIN    ((uint32_t)0x01)

/*GPIO port output speed register (GPIOx_OSPEEDR)*/
#define LOW_SPEED		 ((uint32_t)0x00)
#define MEDIUM_SPEED	 ((uint32_t)0x01)
#define HIGH_SPEED	 	 ((uint32_t)0x03)

/*GPIO port pull-up/pull-down register (GPIOx_PUPDR)*/
#define NO_PU_PD		 ((uint32_t)0x00)
#define PULL_UP			 ((uint32_t)0x01)
#define PULL_DOWN		 ((uint32_t)0x02)
#define RESERVED		 ((uint32_t)0x03)

/*Clock Enabling*/
#define GPIO_CLK_ENABLE_GPIOA		 (RCC->AHBENR |= (1 << 17))
#define GPIO_CLK_ENABLE_GPIOB		 (RCC->AHBENR |= (1 << 18))
#define GPIO_CLK_ENABLE_GPIOC		 (RCC->AHBENR |= (1 << 19))
#define GPIO_CLK_ENABLE_GPIOD		 (RCC->AHBENR |= (1 << 20))
#define GPIO_CLK_ENABLE_GPIOE		 (RCC->AHBENR |= (1 << 21))
#define GPIO_CLK_ENABLE_GPIOF		 (RCC->AHBENR |= (1 << 22))


typedef struct{

	GPIO_TypeDef *port;

	uint32_t pin;

	uint32_t mode;

	uint32_t otype;

	uint32_t pull;

	uint32_t speed;

	uint32_t alt_func;

}GPIO_TYPE;

void GPIO_Init(GPIO_TYPE gpio_Type);

static void config_GPIO_pin(GPIO_TypeDef *gpio, uint32_t pinNumber, uint32_t pinMode);

static void config_GPIO_OType(GPIO_TypeDef *gpio, uint32_t pinNumber,uint32_t outType);

static void config_GPIO_Speed(GPIO_TypeDef *gpio, uint32_t pinNumber,uint32_t pinSpeed);

static void config_GPIO_PUPD(GPIO_TypeDef *gpio, uint32_t pinNumber,uint32_t pinPUPD);

void GPIO_Write(GPIO_TypeDef *gpio, uint32_t pinNumber,uint8_t state);

void GPIO_Toggle(GPIO_TypeDef *gpio, uint32_t pinNumber);
#endif /* _HAL_GPIO */
