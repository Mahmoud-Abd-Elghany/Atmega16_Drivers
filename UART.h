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

#endif /* UART_H_ */
