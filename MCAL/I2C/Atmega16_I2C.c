/*
 * Atmega16_I2C.c
 *
 * Created: 5/19/2021 5:47:33 PM
 *  Author: MAZ
 */ 

#include "Atmega16_I2C.h"
#include <avr/io.h>

static void I2C_StartCond(){
	// Clearing Control register while maintaining I2C Enable bit and Interrupt Enable bit values
	TWCR &= 0b00000111;
	// Clearing Interrupt Flag and sending Start condition
	TWCR |= (1<<TWSTA) | (1<<TWINT);
	while((TWCR & (1<<TWINT)) == 0){ /* waiting until Start Cond is sent */ }
}

static void I2C_StopCond(){
	// Clearing Control register while maintaining I2C Enable bit and Interrupt Enable bit values
	TWCR &= 0b00000111;
	// Clearing Interrupt Flag and sending Stop condition
	TWCR |= (1<<TWSTO) | (1<<TWINT);
	while((TWCR & (1<<TWINT)) == 0){ /* waiting until Stop Cond is sent */ }
}

static unsigned char I2C_getStatus(){
	return (TWSR & (0xF8));
}

static void I2C_writeData(unsigned char data){
	// Clearing Control register while maintaining I2C Enable bit and Interrupt Enable bit values
	TWCR &= 0b00000111;
	// Clearing Interrupt Flag
	TWCR |= (1<<TWINT);
	TWDR = data;
	while((TWCR & (1<<TWINT)) == 0){ /* waiting until data is transmitted */ }
}

static unsigned char I2C_readData_ACK(){
	// Clearing Control register while maintaining I2C Enable bit and Interrupt Enable bit values
	TWCR &= 0b00000111;
	// Clearing Interrupt Flag and Sending Ack
	TWCR |= (1<<TWINT) | (1<<TWEA);
	while((TWCR & (1<<TWINT)) == 0){ /* waiting until data is received */ }
	return TWDR;
}

static unsigned char I2C_readData_NACK(){
	// Clearing Control register while maintaining I2C Enable bit and Interrupt Enable bit values
	TWCR &= 0b00000111;
	// Clearing Interrupt Flag
	TWCR |= (1<<TWINT);
	while((TWCR & (1<<TWINT)) == 0){ /* waiting until data is received */ }
	return TWDR;
}

void I2C_init(void){
	//Enable I2C
	TWCR |= (1<<TWEN);
	/*
	*  SCL freq (Fast mode): 400KHz
	*  TWBR = 2
	*  TWPS = 0
	*/
	TWBR = TWBR_VALUE;
	//Setting Address
	TWAR |= (ADDRESS << 1);
}

void I2C_writeByte(unsigned char slaveAddress, unsigned char internalRegister, unsigned char data){
	// Start Condition
	I2C_StartCond();
	if(I2C_getStatus() == STARTCOND_STATUS){
		// Error
	}
	
	// Slave Address + Write bit
	// -Wait Ack
	I2C_writeData((slaveAddress<<1) | WRITEBIT);
	if(I2C_getStatus() == ADDRESS_WRITE_ACK_STATUS){
		// Error
	}
	
	// Register Address
	// -Wait Ack
	I2C_writeData(internalRegister);
	if(I2C_getStatus() == DATA_ACK_STATUS){
		// Error
	}
	
	// Send Data
	// -Wait Ack
	I2C_writeData(data);
	if(I2C_getStatus() == DATA_ACK_STATUS){
		// Error
	}
	
	// Stop Condition
	I2C_StopCond();
}

unsigned char I2C_readByte(unsigned char slaveAddress, unsigned char internalRegister){
		// Start Condition
		I2C_StartCond();
		if(I2C_getStatus() == STARTCOND_STATUS){
			// Error
		}
		// Slave Address + Write bit
		// -Wait Ack
		I2C_writeData((slaveAddress<<1) | WRITEBIT);
		if(I2C_getStatus() == ADDRESS_WRITE_ACK_STATUS){
			// Error
		}
		
		// Register Address
		// -Wait Ack
		I2C_writeData(internalRegister);
		if(I2C_getStatus() == ADDRESS_WRITE_ACK_STATUS){
			// Error
		}
		
		// Repeated Start
		I2C_StartCond();
		if(I2C_getStatus() == REPEATED_STARTCOND_STATUS){
			// Error
		}
		
		// Slave Address + Read bit
		// -Wait Ack
		I2C_writeData((slaveAddress<<1) | READBIT);
		if(I2C_getStatus() == ADDRESS_WRITE_ACK_STATUS){
			// Error
		}
		
		//Read Byte
		unsigned char Data = I2C_readData_NACK();
		if(I2C_getStatus() == DATA_NACK_STATUS){
			// Error
		}
		
		// Stop Condition
		I2C_StopCond();
		
		return Data;
}
