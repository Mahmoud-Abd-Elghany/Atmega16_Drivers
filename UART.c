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
