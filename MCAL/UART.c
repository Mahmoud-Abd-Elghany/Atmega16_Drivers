/*
 * UART.c
 *
 *      Author: Mahmoud Abdelghany
 */

#include "UART.h"

void UART_init(void)
{
	/*Enable double speed mode*/
	UCSRA|= (1<<U2X);

	/*Enable RX and TX */
	UCSRB |= (1<<3) |(1<<4);

	/* Frame setup
	 *Parity bit Disabled
	 *Asynchronous mode
	 *Stop bit 1-bit
	 */

	/*writing the UCSRC character size 8-bit */
	UCSRC = (1<<URSEL) | (1<<UCSZ0) |(1<<UCSZ1);

	UBRRH = (UART_BAUDSCALER>>8);
	UBRRL = UART_BAUDSCALER;
}

void UART_SendByte(uint8 byte)
{
	/* polling until bit is set to indicate that UDR register is empty o write new data in it*/
	while(BIT_IS_CLEAR(UCSRA,UDRE)){}
	UDR = byte;
}

uint8 UART_RecieveByte(void)
{
	/* polling until bit is set to indicate that recieve is complete*/
	while(BIT_IS_CLEAR(UCSRA,RXC)){}
	return UDR;
	/*Flag cleared automatically after reading data*/
}

void UART_SendString(uint8 *String)
{
	uint8 i = 0;
	while(String[i] != '\0')
	{
		UART_SendByte(String[i]);
		i++;
	}
}

void UART_RecieveString(uint8* Str,uint8 size)
{
	uint8 Char= 0;
	while(Char < size)
	{
		Str[Char] = UART_RecieveByte;
		Char++;
	}
	Str[Char] = '\0';
}
