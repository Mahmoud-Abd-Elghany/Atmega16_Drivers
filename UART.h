/*
 * UART.h
 *
 *      Author: Mahmoud Abdelghany
 */

#ifndef UART_H_
#define UART_H_

#include "avr_config.h"
#include "com_macros.h"
#include "Std_def.h"

#define UART_BAUDRATE 9600UL
#define UART_BAUDSCALER (( F_CPU / (8*UART_BAUDRATE) )-1)

void UART_init(void);

/*Function responsible for sending 1 byte*/
void UART_SendByte(uint8 byte);

/*Function responsible for recieving 1 byte*/
uint8 UART_RecieveByte(void);

/*Function responsible for sending a string*/
void UART_SendString(uint8 *String);

/*Function responsible for recieving a string
 * pass Array pointer and its size
 */
void UART_RecieveString(uint8* Str,uint8 size);

#endif /* UART_H_ */
