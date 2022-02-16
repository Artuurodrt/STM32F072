/*
 * i2c.h
 *
 *  Created on: Feb 16, 2022
 *      Author: Arturo de los Rios
 */

#ifndef I2C_H_
#define I2C_H_

void BSP_I2C1_Init();

uint8_t	I2C1_Write( uint8_t device_Address,
                        uint8_t register_Address,
                        uint8_t *data_Buffer, uint8_t nBytes );

uint8_t	I2C1_Read( uint8_t device_Address,
                       uint8_t register_Address,
                       uint8_t *data_Buffer,
                       uint8_t nBytes );

#endif /* I2C_H_ */
