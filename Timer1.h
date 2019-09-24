/*
 * Timers.h
 *
 *      Author: Mahmoud Abdelghany
 */

#ifndef TIMER1_H_
#define TIMER1_H_

#include "Avr_config.h"
#include "com_macros.h"
#include "Std_def.h"


typedef enum
{
	toggle=1,clear,set
}output_type;

typedef enum
{
	A,B
}Timer1_channel;

typedef enum
{
	Prescaler_1=1,Prescaler_8,Prescaler_64,Prescaler_256,Prescaler_1024
}Timer1_prescaler;

typedef struct
{
	Timer1_channel channel;
	Timer1_prescaler prescaler;
	uint16 ticks;
}Timer1_config;

/* Description: Function responsible for initializing Timer1
 * 1- Set Ticks
 * 2- Set Prescaler
 * 3- Select compare channel
 */
void Timer1_start(const Timer1_config *Timer1_config);


/*Description: Function responsible for enabling/disabling OC1A pin
 * Set the output mode for the pin
 */
void OC1A_Enable (output_type output_mode);
void OC1A_Disable (output_type output_mode);

/*Description: Function responsible for enabling/disabling OC1B pin
 * Set the output mode for the pin
 */
void OC1B_Enable (output_type output_mode);
void OC1B_Disable (output_type output_mode);

#endif /* TIMER1_H_ */
