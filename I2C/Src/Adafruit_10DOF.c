/*
 * Adafruit_10DOF.c
 *
 *  Created on: Feb 16, 2022
 *      Author: Arturo de los Rios
 */
#include "Adafruit_10DOF.h"
#include "stdio.h"
#include "i2c.h"

void LSM303_Init(void){
	uint8_t tx_data[1] = {0x47};
	uint8_t tx_data2[1] = {0x08};

	I2C1_Write(I2C_Accelerometer_Slave_Address, CRL_REG1_A, tx_data, 1); // Enable the accelerometer
	I2C1_Write(I2C_Accelerometer_Slave_Address, CRL_REG4_A, tx_data2, 1); //2G and HR

}

LSM303_Data_T LSM303_Accelerometer(void){

	uint8_t sensordata[1];
    unsigned int Axyz[6]={0};
    LSM303_Data_T  xyz_Data;
    int accX, accY, accZ;

    I2C1_Read(I2C_Accelerometer_Slave_Address,OUT_X_L_A, sensordata, 1);
    Axyz[0] = sensordata[0];
    I2C1_Read(I2C_Accelerometer_Slave_Address,OUT_X_H_A, sensordata, 1);
    Axyz[1] = sensordata[0];
    I2C1_Read(I2C_Accelerometer_Slave_Address,OUT_Y_L_A, sensordata, 1);
    Axyz[2] = sensordata[0];
    I2C1_Read(I2C_Accelerometer_Slave_Address,OUT_Y_H_A, sensordata, 1);
    Axyz[3] = sensordata[0];
    I2C1_Read(I2C_Accelerometer_Slave_Address,OUT_Z_L_A, sensordata, 1);
    Axyz[4] = sensordata[0];
    I2C1_Read(I2C_Accelerometer_Slave_Address,OUT_Z_H_A, sensordata, 1);
    Axyz[5] = sensordata[0];

    /*
    I2C0_Rd(I2C_Accelerometer_Slave_Address,OUT_X_L_A, 6, sensordata);
    for(int i=0;i<6;i++){
        Axyz[i] = sensordata[i];
    }*/


    accX = (int) ((int16_t) ((Axyz[1] << 8 ) | Axyz[0] ));
    accY = (int) ((int16_t) ((Axyz[3] << 8 ) | Axyz[2] ));
    accZ = (int) ((int16_t) ((Axyz[5] << 8 ) | Axyz[4] ));

    // Convert The Readings
    xyz_Data.Ax = (float)accX/256.0;
    xyz_Data.Ay = (float)accY/256.0;
    xyz_Data.Az = (float)accZ/256.0;


return xyz_Data;
}

