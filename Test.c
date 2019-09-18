/*
 * Test.c
 *
 *      Author: Mahmoud Abdelghany
 */


#include "Timers.h"

int main(){

	Timer1_config * config;
	config -> mode = CTC;
	config -> start = 0;
	config -> prescaler = Prescaler_1024;
	config -> compareA_value = 500;
	config -> compareB_value = 1000;
	Timer1_init(config);
	DDRD|=(1<<PD5);
	OC1A_Enable(toggle);
	DDRD|=(1<<PD4);
	OC1B_Enable(toggle);
	while(1){

	}
}

