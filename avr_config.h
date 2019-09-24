/*
 * avr_config.h
 *
 *      Author: Mahmoud Abdelghany
 */

#ifndef AVR_CONFIG_H_
#define AVR_CONFIG_H_

#ifndef F_CPU
#define F_CPU 1000000UL /* 1MHz Clock Frequency  */
#endif


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


#endif /* AVR_CONFIG_H_ */
