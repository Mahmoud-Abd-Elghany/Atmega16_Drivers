/*
 * ADC.c
 *
 *  Created on: Sep 13, 2019
 *      Author: Ma7amee7o
 */

#include "ADC.h"

void ADC_init(void)
{

ADMUX = 0;

SET_BIT (ADCSRA,ADEN); /*enable ADC*/

/* Defining Prescaler */
SET_BIT (ADCSRA,ADPS0);
SET_BIT (ADCSRA,ADPS1);
CLEAR_BIT (ADCSRA,ADPS2);
}

uint16 ADC_ReadChannel(uint8 channel)
{
	channel &= 0x07; /*selecting only first 3 bits as channel should be only 3 bits 0...4*/
	ADMUX &= 0xE0; /*clearing  the last selection*/
	ADMUX |= channel; /*Assigning the no. of channel*/
	SET_BIT (ADCSRA,ADSC); /* Start conversion*/
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /*Pooling until conversion is done by checking the flag */
	SET_BIT(ADCSRA,ADIF); /* Clearing flag*/
	return ADC;






}


