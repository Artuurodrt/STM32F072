/*
 * uartPrint.c
 *
 *  Created on: Feb 16, 2022
 *      Author: Arturo de los Rios
 */

#include "stm32f072xb.h"

void console_Init(void){


	RCC->AHBENR |= RCC_AHBENR_GPIOAEN; /* GPIOA clock enabled */

	/* PA2 and PA3 are configured in Alternate function mode */
	GPIOA->MODER &= ~(GPIO_MODER_MODER2_Msk | GPIO_MODER_MODER3_Msk);  /* Clear bits */
	GPIOA->MODER |= (0x02 <<GPIO_MODER_MODER2_Pos) | (0x02 <<GPIO_MODER_MODER3_Pos);

	/* PA2 and PA3 --> AF1 (USART2)*/
	GPIOA->AFR[0] &= ~(0x0000FF00); /* Clear bits */
	GPIOA->AFR[0] |=  (0x00001100);

	RCC -> APB1ENR |= RCC_APB1ENR_USART2EN;	/* USART2 clock enabled*/

	/* Clear USART2 configuration (reset state) 8-bit, 1 start, 1 stop, CTS/RTS disabled */
	USART2->CR1 = 0x00000000;
	USART2->CR2 = 0x00000000;
	USART2->CR3 = 0x00000000;


	RCC->CFGR3 &= ~RCC_CFGR3_USART2SW_Msk;	/* PCLK (APB1) is selected as clock source, PCLK -> 48 MHz */

	USART2->CR1 |= USART_CR1_OVER8;
	USART2->BRR = 833;

	USART2->CR1 |= USART_CR1_TE | USART_CR1_RE;	/* Enable both Transmitter and Receiver */

	USART2->CR1 |= USART_CR1_UE;	/* USART2 enabled  */

}
