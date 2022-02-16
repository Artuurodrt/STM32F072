/*
 * Adafruit_10DOF.h
 *
 *  Created on: Feb 16, 2022
 *      Author: Arturo de los Rios
 */

#ifndef ADAFRUIT_10DOF_H_
#define ADAFRUIT_10DOF_H_


// Accelerometer IMU 10 DOF
// Accelerometer Registers
#define CRL_REG1_A  0x20
#define CRL_REG2_A  0x21
#define CRL_REG3_A  0x22
#define CRL_REG4_A  0x23
#define OUT_X_L_A   0x28
#define OUT_X_H_A   0x29
#define OUT_Y_L_A   0x2A
#define OUT_Y_H_A   0x2B
#define OUT_Z_L_A   0x2C
#define OUT_Z_H_A   0x2D

// Accelerometer slave address IMU 10 DOF
#define I2C_Accelerometer_Slave_Address 0x19
#define I2C_giroscopio_Slave_Address 0x6B

#define RADTOGRAD 57.29577951308

typedef struct LSM303_Data_S
{
    float Ax;
    float Ay;
    float Az;

}LSM303_Data_T;


void LSM303_Init(void);

LSM303_Data_T LSM303_Accelerometer(void);


#endif /* ADAFRUIT_10DOF_H_ */
