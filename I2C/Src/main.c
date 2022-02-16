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

#include "stdint.h"
#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "stm32f072xb.h"
#include "i2c.h"
#include "Adafruit_10DOF.h"

int main(void)
{
    LSM303_Data_T LSM303_Data;
    float Pitch, Roll, Yaw = 0.0;


	BSP_I2C1_Init();
	LSM303_Init();

    while(1){

    LSM303_Data = LSM303_Accelerometer();

    Pitch = RADTOGRAD*atan2f(-LSM303_Data.Ax,sqrtf(LSM303_Data.Ay*LSM303_Data.Ay+LSM303_Data.Az*LSM303_Data.Az));
    Roll = RADTOGRAD*atan2f(LSM303_Data.Ay,sqrtf(LSM303_Data.Ax*LSM303_Data.Ax+LSM303_Data.Az*LSM303_Data.Az));
    Yaw = RADTOGRAD*atan2f(sqrtf(LSM303_Data.Ax*LSM303_Data.Ax+LSM303_Data.Ay*LSM303_Data.Ay),LSM303_Data.Az);

    }
}

