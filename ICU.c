/*
 * ICU.c
 *
 *      Author: Mahmoud Abdelghany
 */


#include"ICU.h"

static volatile void (*g_callback_Ptr)(void) = NULL;

ISR(TIMER1_CAPT_vect)
{
	if(g_callback_Ptr != NULL)
	{
		(*g_callback_Ptr)();
	}
}

void Icu_init(const ICU_config *config)
{
	/*setting prescaler*/
	TCCR1B = (TCCR1B & ~(0x07)) | (config->prescaler);

	/*setting edgetype*/
	TCCR1B = (TCCR1B & (0<<ICES1)) | (config->edgetype<<ICES1);

	/*Enable ICU Interrupt module*/
	SET_BIT(TIMSK,TICIE1);

	TCCR1A |= (1<<FOC1A) |(1<<FOC1B);

	/*Assigning icu pin as input pin*/
	CLEAR_BIT(DDRD,6);

	/*Normal mode*/
	TCCR1A |= (0x03<<2);

	/* Set timer start value to 0 and icu value to 0 */
	ICR1 =0;
	TCNT1 = 0;
}

void ICU_SetCallBack(void(*a_Fun_Ptr)(void))
{
	g_callback_Ptr = a_Fun_Ptr;
}

uint16 ICU_getInputValue(void)
{
	return ICR1;
}

void ICU_SetEdgeDetectionType(edge type)
{
	TCCR1B = (TCCR1B & ~(0x01<<6)) | (type<<6);
}

void ICU_DeInit(void)
{
	{
		TCCR1A = 0;
		TCCR1B = 0;
		TCNT1 = 0;
		ICR1 = 0;

		/*disabling ICU interrupt module*/
		TIMSK &= ~(1<<5);

	}
}
