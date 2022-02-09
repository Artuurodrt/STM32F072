/*
 * _HAL_GPIO.c
 *
 *  Created on: Feb 5, 2022
 *      Author: Arturo de los Rios
 */

#include <stdint.h>
#include "_HAL_GPIO.h"

uint32_t PINPOS_32[16] = {
(0x00),
(0x02),
(0x04),
(0x06),
(0x08),
(0x0A),
(0x0C),
(0x0E),
(0x10),
(0x12),
(0x14),
(0x16),
(0x18),
(0x1A),
(0x1C),
(0x1E)
};


void GPIO_Init(GPIO_TYPE gpio_Type){

	if(gpio_Type.port == PORTA){
		GPIO_CLK_ENABLE_GPIOA;
	}
	else if(gpio_Type.port == PORTB){
		GPIO_CLK_ENABLE_GPIOB;
	}
	else if(gpio_Type.port == PORTC){
		GPIO_CLK_ENABLE_GPIOC;
	}
	else if(gpio_Type.port == PORTD){
		GPIO_CLK_ENABLE_GPIOD;
	}
	else if(gpio_Type.port == PORTE){
		GPIO_CLK_ENABLE_GPIOE;
	}
	else if(gpio_Type.port == PORTF){
		GPIO_CLK_ENABLE_GPIOF;
	}
	config_GPIO_pin(gpio_Type.port, gpio_Type.pin, gpio_Type.mode);
	config_GPIO_Speed(gpio_Type.port, gpio_Type.pin, gpio_Type.speed);
	config_GPIO_OType(gpio_Type.port, gpio_Type.pin, gpio_Type.otype);
	config_GPIO_PUPD(gpio_Type.port, gpio_Type.pin, gpio_Type.pull);
}

static void config_GPIO_pin(GPIO_TypeDef *gpio, uint32_t pinNumber, uint32_t pinMode){

	if(pinNumber <= 15){
		switch(pinMode){
		case INPUT_MODE:
			gpio->MODER &= ~((1 << POS32_BIT1) | (1 << POS32_BIT2));
			break;
		case GEN_PURPOSE_OUT_MODE:
			gpio->MODER &= ~(1 << POS32_BIT2);
			gpio->MODER |= (1 << POS32_BIT1);
			break;
		case ALT_FUNCTION_MODE:
			gpio->MODER &= ~(1 << POS32_BIT1);
			gpio->MODER |= (1 << POS32_BIT2);
			break;
		case ANALOG_MODE:
			gpio->MODER &= ~((1 << POS32_BIT1) | (1 << POS32_BIT2));
			gpio->MODER |= (1 << POS32_BIT1) | (1 << POS32_BIT2);
			break;
		default:
			break;
		}
	}
}

static void config_GPIO_Speed(GPIO_TypeDef *gpio, uint32_t pinNumber,uint32_t pinSpeed){

	if(pinNumber <= 15){
		switch(pinSpeed){
		case LOW_SPEED:
			gpio->OSPEEDR &= ~((1 << POS32_BIT1) | (1 << POS32_BIT2));
			break;
		case MEDIUM_SPEED:
			gpio->OSPEEDR &= ~(1 << POS32_BIT2);
			gpio->OSPEEDR |= (1 << POS32_BIT1);
			break;
		case HIGH_SPEED:
			gpio->OSPEEDR &= ~((1 << POS32_BIT1) | (1 << POS32_BIT2));
			gpio->OSPEEDR |= (1 << POS32_BIT1) | (1 << POS32_BIT2);
			break;
		default:
			break;
		}
	}
}


static void config_GPIO_OType(GPIO_TypeDef *gpio, uint32_t pinNumber,uint32_t outType){

	if(pinNumber <= 15){
		switch(outType){
		case OUTPUT_PUSH_PULL:
			gpio->OTYPER &= ~(1 << pinNumber);
			break;
		case OUTPUT_PULL_DRAIN:
			gpio->OTYPER |= (1 << pinNumber);
			break;
		default:
			break;
		}
	}
}

static void config_GPIO_PUPD(GPIO_TypeDef *gpio, uint32_t pinNumber,uint32_t pinPUPD){

	if(pinNumber <= 15){
		switch(pinPUPD){
		case NO_PU_PD:
			gpio->PUPDR &= ~((1 << POS32_BIT1) | (1 << POS32_BIT2));
		break;
		case PULL_UP:
			gpio->PUPDR &= ~(1 << POS32_BIT2);
			gpio->PUPDR |= (1 << POS32_BIT1);
		break;
		case PULL_DOWN:
			gpio->PUPDR &= ~(1 << POS32_BIT1);
			gpio->PUPDR |= (1 << POS32_BIT2);
		break;
		case RESERVED:
			gpio->PUPDR &= ~((1 << POS32_BIT1) | (1 << POS32_BIT2));
			gpio->PUPDR |= (1 << POS32_BIT1) | (1 << POS32_BIT2);
		break;

		}
	}
}

void GPIO_Write(GPIO_TypeDef *gpio, uint32_t pinNumber, uint8_t state){

	if(state){
		gpio->BSRR = (1 << pinNumber);
	}
	else{
		gpio->BSRR = (1 << (pinNumber + 16));
	}
}


void GPIO_Toggle(GPIO_TypeDef *gpio, uint32_t pinNumber){

	gpio->ODR ^= (1 << pinNumber);

}
