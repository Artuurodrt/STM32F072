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

int main()
{
/*Initialize the clock for the GPIO Port A*/
	RCC->AHBENR |= (1 << 17);
	GPIOA->MODER = (1 << 10);
	GPIOA->OSPEEDR|=(3 << 10);
	GPIOA->OTYPER &= ~(1<<5);
	GPIOA->PUPDR &= ~((1<<10) | (1<<11));

while(1){

	for(int i=0;i<1000000;i++);
		GPIOA->BSRR = (1 << 5);
	for(int i=0;i<1000000;i++);
		GPIOA->BSRR = (1 << 21);
	}
}
