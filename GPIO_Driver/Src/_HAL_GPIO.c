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

uint32_t PINPOS[16] = {
(0x00),
(0x01),
(0x02),
(0x03),
(0x04),
(0x05),
(0x06),
(0x07),
(0x08),
(0x09),
(0x0A),
(0x0B),
(0x0C),
(0x0D),
(0x0E),
(0x0F)
};


static void config_GPIO_pin(GPIO_TypeDef *port, uint32_t pinNumber, uint32_t pinMode){

	if(pinNumber <= 15){
		switch(pinMode){
		case INPUT_MODE:
			port->MODER &= ~((1 << POS_BIT1) | (1 << POS_BIT2));
			break;
		case GEN_PURPOSE_OUT_MODE:
			port->MODER &= ~(1 << POS_BIT2);
			port->MODER |= (1 << POS_BIT1);
			break;
		case ALT_FUNCTION_MODE:
			port->MODER &= ~(1 << POS_BIT1);
			port->MODER |= (1 << POS_BIT2);
			break;
		case ANALOG_MODE:
			port->MODER &= ~((1 << POS_BIT1) | (1 << POS_BIT2));
			port->MODER |= (1 << POS_BIT1) | (1 << POS_BIT2);
			break;
		default:
			break;
		}
	}
}


static void config_GPIO_OType(GPIO_TypeDef *gpio, uint32_t pinNumber,uint32_t outType ,uint32_t pinMode){

	if(pinNumber <= 15){
		switch(pinMode){
		case OUTPUT_PUSH_PULL:
			gpio->OTYPER &= ~(1 << POS_BIT1);
			break;
		}

	}

}



static void config_GPIO_Speed(GPIO_TypeDef *gpio, uint32_t pinNumber,uint32_t pinSpeed ,uint32_t pinMode){

	if(pinNumber <= 15){


	}
}


