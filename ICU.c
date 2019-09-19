/*
 * ICU.c
 *
 *      Author: Mahmoud Abdelghany
 */


#include"ICU.h"


void Icu_init(const config* ICU_config)
{
	/*setting prescaler*/
	TCCR1B = (TCCR1B & ~(0x07)) | (ICU_config->prescaler);

	/*setting edgetype*/
	TCCR1B = (TCCR1B & (0<<ICES1)) | (ICU_config->edgetype<<ICES1);

	/*Enable ICU Interrupt module*/
	SET_BIT(TIMSK,TICIE1);

	TCCR1A |= (1<<FOC1A) |(1<<FOC1B);
	/*Assigning it as input pin*/
	CLEAR_BIT(DDRD,6);
}

