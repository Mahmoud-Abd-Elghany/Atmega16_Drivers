/*
 * Timers.h
 *
 *      Author: Mahmoud Abdelghany
 */

#include "Timer1.h"

void static volatile (*g_CallBack)(void) = NULL;

ISR(TIMER1_COMPA_vect)
{
	if( g_CallBack != NULL)
	{
		(*g_CallBack)();
	}
}


void Timer1_start( const Timer1_config * Timer1_config)
{
	TCNT1 = 0; /*start from 0*/

	/* Setting prescaler value */
	TCCR1B &= ~(0x07);
	TCCR1B |= (Timer1_config -> prescaler);

	/* Activating compare mode */
	TCCR1A |= (0x03<<2);
	SET_BIT(TCCR1B,WGM12);
	CLEAR_BIT(TCCR1B,WGM13);

	/*choosing channel */
	switch(Timer1_config-> channel)
	{
	case A:
		OCR1A = (Timer1_config-> ticks); /* assigning value to be compared to in A register*/
		SET_BIT (TCCR1A,FOC1A);
		SET_BIT(TIMSK,OCIE1A); /*Enable module interrupt*/
		break;
	case B:
		OCR1B = (Timer1_config-> ticks); /* assigning value to be compared to in B register*/
		SET_BIT (TCCR1A,FOC1B);
		SET_BIT(TIMSK,OCIE1B); /*Enable module interrupt*/
		break;
	default:
		OCR1A = (Timer1_config-> ticks); /* assigning value to be compared to in A register*/
		SET_BIT (TCCR1A,FOC1A);
		SET_BIT(TIMSK,OCIE1A); /*Enable module interrupt*/
		break;
	}


}

void Timer1_SetCallback(void (*a_function)(void))
{
	g_CallBack = a_function;
}


void OC1A_Enable (output_type output_mode)
{
	SET_BIT(DDRD,PD5);
	TCCR1A |= (output_mode << 6);
}
void OC1A_Disable (output_type output_mode)
{
	CLEAR_BIT(DDRD,PD5);
	TCCR1A &= ~(output_mode << 6);
}


void OC1B_Enable (output_type output_mode)
{
	SET_BIT(DDRD,PD4);
	TCCR1A |= (output_mode << 4);
}
void OC1B_Disable (output_type output_mode)
{
	CLEAR_BIT(DDRD,PD4);
	TCCR1A &= ~(output_mode << 4);
}


