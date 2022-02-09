/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Arturo de los Rios
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "stm32f072xb.h"
#include "_HAL_GPIO.h"

int main()
{

	GPIO_TYPE myGPIO;
	myGPIO.port = PORTA;
	myGPIO.pin = 5;
	myGPIO.mode = GEN_PURPOSE_OUT_MODE;
	myGPIO.speed = HIGH_SPEED;
	myGPIO.otype = OUTPUT_PUSH_PULL;
	myGPIO.pull = NO_PU_PD;

	/*Initialize GPIO Port A*/
	GPIO_Init(myGPIO);


while(1){

	for(int i=0;i<1000000;i++);
		GPIOA->BSRR = (1 << 5);
	for(int i=0;i<1000000;i++);
		GPIOA->BSRR = (1 << 21);
	}
}
