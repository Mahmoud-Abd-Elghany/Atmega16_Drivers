/*
 * Test.c
 *
 *      Author: Mahmoud Abdelghany
 */


#include "Timers.h"

int main(){

	Timer1_config *config;
	config -> mode = CTC;
	config -> start = 0000;
	config -> prescaler = Prescaler_1024;
	config -> compareA_value = 1000;
	Timer1_init(config);


	SET_BIT(TCCR1B,WGM12);

	TCCR1B |= (config->prescaler);

	OCR1A = (OCR1A & 0) | (config->compareA_value);

	CLEAR_BIT (TCCR1A,FOC1A);
	SET_BIT(TCCR1A,COM1A0);
	CLEAR_BIT(TCCR1A,COM1A1);
	while(1){	SET_BIT(DDRD,PD5);}
}

