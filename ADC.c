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
SET_BIT (ADCSRA,7);
SET_BIT (ADCSRA,0);
SET_BIT (ADCSRA,1);
CLEAR_BIT (ADCSRA,2);
}

void ADC_ReadChannel(uint8 channel)
{
	SET_BIT (ADMUX,channel);

}


