/*
 * Keypad.c
 *
 *      Author: Mahmoud Abdelghany
 */

#include "Keypad.h"

#if(N_col == 3)
static uint8 Keypad_4x3_adjustSwitchNumber(uint8 button_no);

#elif(N_col == 4)
static uint8 Keypad_4x4_adjustSwitchNumber(uint8 button_no);

#endif

uint8 Keypad_getPressedKey(void)
{
	for(uint8 col = 0; col<N_col; col++)
	{
		/*changing each column to output the changing others to input*/
		KEY_PORT_DIR &= 0x10 << col;
		KEY_PORT_OUT &= ~(0x10 <<col);

		for(uint8 row = 0; row <N_row;row++)
		{
#if(N_col==3)
		/*Functin responsible for returning the true value of button in 4x3 keypad*/
		return Keypad_4x3_adjustSwitchNumber((row*3)-(3-col));
#elif(N_col==4)
		/*Functin responsible for returning the true value of button in 4x3 keypad*/
		return Keypad_4x4_adjustSwitchNumber((row*3)-(3-col));
#endif
		}

	}


}


#if(N_col==3)
/*Function responsible for changing the no. of button pressed to its true value */
uint8 Keypad_4x3_adjustSwitchNumber(uint8 button_no)
{
	switch (button_no)
	{
	case 10:
		return '*';
		break;
	case 11:
		return 0;
		break;
	case 12:
		return '#';
		break;
	default:
		return button_no;
		break;
	}
}

#elif(N_col==4)
/*Function responsible for changing the no. of button pressed to its true value*/
uint8 Keypad_4x4_adjustSwitchNumber(uint8 button_no)
{
	switch (button_no)
	{
	case 4:
		return 'A';
		break;
	case 5:
		return 4;
		break;
	case 6:
		return 5;
		break;
	case 7:
		return 6;
		break;
	case 8:
		return 'B';
		break;
	case 9:
		return 7;
		break;
	case 10:
		return 8;
		break;
	case 11:
		return 9;
		break;
	case 12:
		return 'C';
		break;
	case 13:
		return '*';
		break;
	case 14:
		return 0;
		break;
	case 15:
		return '#';
		break;
	case 16:
		return 'D';
		break;
	default:
		return button_no;
		break;
	}
}
#endif
