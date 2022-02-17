/*
 * userLed.h
 *
 *  Created on: Feb 16, 2022
 *      Author: arturodrt
 */

#ifndef USERLED_H_
#define USERLED_H_

void LED_Init(void);
void LED_On(void);
void LED_Off(void);
void LED_Toggle(void);

void PB_Init(void);
uint8_t	PB_GetState(void);

#endif /* USERLED_H_ */
