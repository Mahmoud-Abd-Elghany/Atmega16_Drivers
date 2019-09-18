/*
 * Timers.h
 *
 *      Author: Mahmoud Abdelghany
 */

#include"Timers.h"


void Timer1_init( Timer1_config * Timer1_config)
{
	TCNT1 = (Timer1_config -> start); /* setting the no. to start from */
	TCCR1B |= (Timer1_config -> prescaler); /* setting prescaler value */


	switch(Timer1_config -> mode)
	{
	case Normal:
		/*activating normal mode*/
		TCCR1A &= ~(0x03); /* clearing WGM10 and WGM11*/
		TCCR1B &= ~(0x03<<3); /* clearing WGM10 and WGM11*/
		SET_BIT (TCCR1A,FOC1A);
		SET_BIT (TCCR1A,FOC1B);
		break;

	case CTC:
		/*activating compare mode and assigning compare value*/
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);/* clearing WGM10 and WGM11*/
		SET_BIT(TCCR1B,WGM12); /* setting WGM12*/
		CLEAR_BIT(TCCR1B,WGM13); /* clearing WGM13*/
		OCR1A = (Timer1_config-> compareA_value); /* assigning value to be compared to in A register*/
		OCR1B = (Timer1_config-> compareB_value); /* assigning value to be compared to in B register*/
		CLEAR_BIT (TCCR1A,FOC1B);
		SET_BIT (TCCR1A,FOC1A);
		break;

	case fast_PWM:
		/*activating PWM mode and assigning compare value*/
		TCCR1A |= (0x03); /*setting WGM10 and WGM11*/
		TCCR1B |= (0x03<<3); /*setting WGM12 and WGM13 */
		OCR1A = (Timer1_config-> compareA_value); /* assigning value to be compared to in A register*/
		OCR1B = (Timer1_config-> compareB_value); /* assigning value to be compared to in B register*/
	}
}

void Timer1_Int_Enable (int_channel channel)
{
	switch(channel)
	{
	case A:
		/* Enable interrupt for compare output channel A */
		SET_BIT(TIMSK,OCIE1A);
		break;
	case B:
		/* Enable interrupt for compare output channel B */
		SET_BIT(TIMSK,OCIE1B);
		break;
	case Overflow:
		/*Enable interrupt for Overflow mode*/
		SET_BIT(TIMSK,TOIE1);
		break;
	}
}

void Timer1_Int_Disable (int_channel channel)
{
	switch(channel)
	{
	case A:
		/* Disable interrupt for compare output channel A */
		CLEAR_BIT(TIMSK,OCIE1A);
		break;
	case B:
		/* Disable interrupt for compare output channel B */
		CLEAR_BIT(TIMSK,OCIE1B);
		break;
	case Overflow:
		/*Disable interrupt for Overflow mode*/
		CLEAR_BIT(TIMSK,TOIE1);
		break;
	}
}


void OC1A_Enable (output_type output_mode)
{
	TCCR1A |= (output_mode << 6);
}
void OC1A_Disable (output_type output_mode)
{
	TCCR1A &= ~(output_mode << 6);
}


void OC1B_Enable (output_type output_mode)
{
	TCCR1A |= (output_mode << 4);
}
void OC1B_Disable (output_type output_mode)
{
	TCCR1A &= ~(output_mode << 4);
}


