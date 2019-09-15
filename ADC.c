/*
 * ADC.c
 *
 *      Author: Mahmoud Abdelghany
 */

#include "ADC.h"

void ADC_init(ADC_config *ADC_config_Ptr)
{

ADMUX = 0;
SET_BIT (ADCSRA,ADEN); /*enable ADC*/


/* Selecting Prescaler by assigning prescaler value to ADPS0..2 bits  in ADCSRA register  */
ADCSRA &= ~(0x07); /*clearing used bits*/
ADCSRA |= ((ADC_config_Ptr->prescaler));

/*Selecting which Source to use by assigning source value to REFS0 & REFS1 bits in ADMUX register */
ADMUX &= ~(0x02<<6); /*clearing used bits*/
ADMUX |= ((ADC_config_Ptr->source));

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

void ADC_dinit(void)
{
	CLEAR_BIT (ADCSRA,ADEN); /*Disable ADC*/
}


