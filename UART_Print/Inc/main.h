/*
 * main.h
 *
 *  Created on: Feb 16, 2022
 *      Author: arturodrt
 */

#ifndef MAIN_H_
#define MAIN_H_

/*
 * printf() and sprintf() from printf-stdarg.c
 */

int stm32_printf(const char *format, ...);
int stm32_sprintf(char *out, const char *format, ...);

#endif /* MAIN_H_ */
