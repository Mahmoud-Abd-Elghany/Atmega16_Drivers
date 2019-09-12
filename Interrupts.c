#include "Interrupts.h"


void Enable_Int (uint8 INT_NO)
{
	switch (INT_NO){
			case 0:
				BIT_IS_SET(GICR,6);
				break;
			case 1:
				BIT_IS_SET(GICR,7);
				break;
			case 2:
				BIT_IS_SET(GICR,5);
				break;
	}

}

void Disable_Int (uint8 INT_NO)
{
	switch (INT_NO){
			case 0:
				BIT_IS_CLEAR(GICR,6);
				break;
			case 1:
				BIT_IS_CLEAR(GICR,7);
				break;
			case 2:
				BIT_IS_CLEAR(GICR,5);
				break;
	}

}

void INT0_mode (uint8 Mode)
{
	switch (Mode){
		case 0: //any change
			BIT_IS_SET(MCUCR,ISC00);
			BIT_IS_CLEAR (MCUCR,ISC01);
			break;
		case 1: //falling
			BIT_IS_SET(MCUCR,ISC01);
			BIT_IS_CLEAR (MCUCR,ISC00);
			break;
		case 2: //rising
			BIT_IS_SET(MCUCR,ISC00);
			BIT_IS_SET (MCUCR,ISC01);
			break;
	}
}

void INT1_mode (uint8 Mode)
{
	switch (Mode){
		case 0: //any change
			BIT_IS_SET(MCUCR,ISC10);
			BIT_IS_CLEAR (MCUCR,ISC11);
			break;
		case 1: //falling
			BIT_IS_SET(MCUCR,ISC11);
			BIT_IS_CLEAR (MCUCR,ISC10);
			break;
		case 2: //rising
			BIT_IS_SET(MCUCR,ISC10);
			BIT_IS_SET (MCUCR,ISC11);
			break;
	}
}

void INT2_mode (uint8 Mode)
{
	switch (Mode){
		case 1: //falling
			BIT_IS_CLEAR (MCUCSR,ISC2);
			break;
		case 2: //rising
			BIT_IS_SET(MCUCSR,ISC2);
			break;
	}
}
