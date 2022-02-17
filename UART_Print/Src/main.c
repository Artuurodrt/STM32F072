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
#include "systemclk_Config.h"
#include "userLed.h"
#include "uartPrint.h"
#include "main.h"


int main(void)
{
	uint8_t	i, sent;
	SystemClock_Config();

		/* Initialize built-in LED & Button pin */
		LED_Init();
		PB_Init();

		/* Initialize Debug Console*/
		console_Init();
		stm32_printf("Console ready!\r\n");

		sent = 0;
		i = 0;

		// Main loop
		while(1)
		{
			/* If User-Button is pushed down*/
			if (PB_GetState() == 1)
			{
				LED_On();	/* Keep LED On*/

				/* Send '#i' only once*/
				if (sent == 0)
				{
					stm32_printf("#%d\r\n", i);
					sent = 1;
					i++;
				}
			}

			/* If User-Button is released*/
			else
			{
				LED_Off();	/* Keep LED Off*/
				sent = 0;
			}
		}
}
