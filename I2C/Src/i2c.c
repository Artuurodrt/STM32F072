/*
 * i2c.c
 *
 *  Created on: Feb 16, 2022
 *      Author: Arturo de los Rios
 */

#include "stm32f072xb.h"
#include "stdio.h"


void BSP_I2C1_Init()
{

	// Pin configuration for I2C1 pins
	// SCL -> PB8
	// SDA -> PB9

	RCC->AHBENR |= RCC_AHBENR_GPIOBEN;  /* I/O port B Clock enable*/
	GPIOB->MODER &= ~(GPIO_MODER_MODER8 | GPIO_MODER_MODER9);
	GPIOB->MODER |= GPIO_MODER_MODER8_1 | GPIO_MODER_MODER9_1;  /* Alternate Function mode for Pin PB8 and Pin PB9*/
	GPIOB->OTYPER |= GPIO_OTYPER_OT_8 | GPIO_OTYPER_OT_9;  /* PB8 and PB9 as open-drain output*/
	GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR8 | GPIO_OSPEEDER_OSPEEDR9;  /* PB8 and PB9 --> High Speed */
	GPIOB->PUPDR |= (1<<16) | (1<<18);  /* PB8 and PB9 --> Pull up */
	GPIOB->AFR[1] &= ~(0x000000FF);
	GPIOB->AFR[1] |= (1<<0) | (1<<4);  /* PB8 and PB9 --> AF1 (I2C1) */
	RCC->CFGR3 |= RCC_CFGR3_I2C1SW;	/* Select SYSCLK as I2C1 clock (48MHz)*/
	RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;  /* Enable I2C1 Clock*/
    I2C1->CR1 &= ~I2C_CR1_PE; /* reset PE*/

   /* while(I2C1->CR1&I2C_CR1_PE);            //while PE ==1
    I2C1->TIMINGR|=(PRESC << 28)|(SCLL<<0)|(SCLH<<8)|(SCLDEL<<20)|(SDADEL<<16);
    I2C1->CR1|=I2C_CR1_PE; //set PE */

	// Reset I2C1 Configuration to default values
	I2C1->CR1 	  = 0x00000000;
	I2C1->CR2 	  = 0x00000000;
	I2C1->TIMINGR = 0x00000000;

	// Configure timing for 100kHz, 50% duty cycle
	I2C1->TIMINGR |= ((4-1)  <<I2C_TIMINGR_PRESC_Pos); // Clock prescaler /4 -> 12MHz
	I2C1->TIMINGR |= (60 	 <<I2C_TIMINGR_SCLH_Pos);  // High half-period = 5µs
	I2C1->TIMINGR |= (60     <<I2C_TIMINGR_SCLL_Pos);  // Low  half-period = 5µs

	// Enable I2C1
	I2C1->CR1 |= I2C_CR1_PE;

}

uint8_t	I2C1_Read( uint8_t device_Address,
                       uint8_t register_Address,
                       uint8_t *data_Buffer,
                       uint8_t nBytes )
{
	uint32_t 	timeout;	/* Flag waiting timeout */
	uint8_t		counter;	/* Loop counter */


	I2C1->CR2 &= ~I2C_CR2_SADD_Msk;
	I2C1->CR2 |= ((device_Address << 1U) << I2C_CR2_SADD_Pos); /* Set device address */


	I2C1->CR2 &= ~I2C_CR2_RD_WRN;/* Set I2C in Write mode*/

	/*Transfer NBYTES = 1 -  No AUTOEND*/
	I2C1->CR2 &= ~I2C_CR2_NBYTES;
	I2C1->CR2 |= (1 <<16U);
	I2C1->CR2 &= ~I2C_CR2_AUTOEND;


	I2C1->CR2 |= I2C_CR2_START; /* Start I2C transaction */

	/* Wait for TXIS with timeout */
	timeout = 100000;
	while (((I2C1->ISR) & I2C_ISR_TXIS) != I2C_ISR_TXIS)
	{
		timeout--;
		if (timeout == 0) return 1;
	}

	/* Send Register address */
	I2C1->TXDR = register_Address;

	/* Wait for TC with timeout */
	timeout = 100000;
	while (((I2C1->ISR) & I2C_ISR_TC) != I2C_ISR_TC)
	{
		timeout--;
		if (timeout == 0) return 2;
	}

	/* Set I2C in Read mode */
	I2C1->CR2 |= I2C_CR2_RD_WRN;

	/* Transfer NBYTES, no AUTOEND */
	I2C1->CR2 &= ~I2C_CR2_NBYTES;
	I2C1->CR2 |= (nBytes <<16U);
	I2C1->CR2 &= ~I2C_CR2_AUTOEND;


	I2C1->CR2 |= I2C_CR2_START;	/* Re-Start transaction*/

	counter = nBytes;

	while (counter>0)
	{
		/* Wait for RXNE with timeout */
		timeout = 100000;
		while (((I2C1->ISR) & I2C_ISR_RXNE) != I2C_ISR_RXNE)
		{
			timeout--;
			if (timeout == 0) return 3;
		}

		/* Store data into data_Buffer*/
		*data_Buffer = I2C1->RXDR;
		data_Buffer++;
		counter--;
	}

	I2C1->CR2 |= I2C_CR2_STOP;	/* Generate STOP condition*/


	/* Wait for STOPF with timeout*/
	timeout = 100000;
	while (((I2C1->ISR) & I2C_ISR_STOPF) != I2C_ISR_STOPF)
	{
		timeout--;
		if (timeout == 0) return 4;
	}

	/* Return success*/
	return 0;
}

uint8_t	I2C1_Write( uint8_t device_Address,
                        uint8_t register_Address,
                        uint8_t *data_Buffer, uint8_t nBytes )
{
	uint32_t 	timeout;	/* Flag waiting timeout*/
	uint8_t		n;		/* Loop counter*/

	/* Set device address*/
	I2C1->CR2 &= ~I2C_CR2_SADD_Msk;
	I2C1->CR2 |= ((device_Address <<1U) <<I2C_CR2_SADD_Pos);

	I2C1->CR2 &= ~I2C_CR2_RD_WRN;	/* Set I2C in Write mode */

	/* Transfer NBYTES, with AUTOEND*/
	I2C1->CR2 &= ~I2C_CR2_NBYTES;
	I2C1->CR2 |= ((nBytes+1) <<16U);
	I2C1->CR2 |= I2C_CR2_AUTOEND;

	I2C1->ICR |= I2C_ICR_STOPCF;	/* Clear STOPF flag */

	I2C1->CR2 |= I2C_CR2_START;	/* Start I2C transaction */

	/* Wait for TXIS with timeout*/
	timeout = 100000;
	while (((I2C1->ISR) & I2C_ISR_TXIS) != I2C_ISR_TXIS)
	{
		timeout--;
		if (timeout == 0) return 1;
	}

	I2C1->TXDR = register_Address;	/* Send register address */

	n = nBytes;

	while(n>0)
	{
		/* Wait for TXIS with timeout*/
		timeout = 100000;
		while (((I2C1->ISR) & I2C_ISR_TXIS) != I2C_ISR_TXIS)
		{
			timeout--;
			if (timeout == 0) return 2;
		}

		/* Send data */
		I2C1->TXDR = *data_Buffer;
		data_Buffer++;
		n--;
	}

	/* Wait for STOPF with timeout */
	timeout = 100000;
	while (((I2C1->ISR) & I2C_ISR_STOPF) != I2C_ISR_STOPF)
	{
		timeout--;
		if (timeout == 0) return 3;
	}

	/* Return success */
	return 0;
}



