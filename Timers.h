/*
 * Timers.h
 *
 *      Author: Mahmoud Abdelghany
 */

#ifndef TIMERS_H_
#define TIMERS_H_

#include "Avr_config.h"
#include "com_macros.h"
#include "Std_def.h"

typedef enum
{
	Normal,CTC,fast_PWM
}Timer1_mode;

typedef enum
{
	toggle=1,clear,set
}output_type;

typedef enum
{
	A,B,Overflow
}int_channel;

typedef enum
{
	Prescaler_1=1,Prescaler_8,Prescaler_64,Prescaler_256,Prescaler_1024
}Timer1_prescaler;

typedef struct
{
	Timer1_mode mode;
	Timer1_prescaler prescaler;
	uint16 start;
	uint16 compareA_value;
	uint16 compareB_value;
}Timer1_config;

/* Description: Function responsible for initializing Timer1
 * 1- Set start value
 * 2- Set Prescaler
 * 3- Set operation mode
 * If(CTC or PMW)
 * 4- Set compare value in channel A and/or B
 */
void Timer1_init(Timer1_config * Timer1_config);

/* Description: Function responsible for enabling/disabling Timer1 interrupt module
 * Choose which mode to activate/deactivate the it's interrupt
 */
void Timer1_Int_Enable (int_channel channel);
void Timer1_Int_Disable (int_channel channel);

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

#endif /* TIMERS_H_ */
