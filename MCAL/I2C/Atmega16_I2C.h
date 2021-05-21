/*
 * Atmega16_I2C.h
 *
 * Created: 5/19/2021 5:47:57 PM
 *  Author: MAZ
 */ 


#ifndef ATMEGA16_I2C_H_
#define ATMEGA16_I2C_H_

#define F_CPU (8000000U)
#define TWBR_VALUE (2)
#define ADDRESS (0x5E)
#define WRITEBIT (0x00)
#define READBIT (0x01)
#define STARTCOND_STATUS (0x08)
#define REPEATED_STARTCOND_STATUS (0x10)
#define ADDRESS_WRITE_ACK_STATUS (0x18)
#define DATA_ACK_STATUS (0x28)
#define DATA_NACK_STATUS (0x30)

void I2C_init(void);
void I2C_writeByte(unsigned char slaveAddress, unsigned char internalRegister, unsigned char data);
unsigned char I2C_readByte(unsigned char slaveAddress, unsigned char internalRegister);


#endif /* ATMEGA16_I2C_H_ */