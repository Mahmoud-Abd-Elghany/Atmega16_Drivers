/*
 * Keypad.c
 *
 *      Author: Mahmoud Abdelghany
 */

#include "Keypad.h"

static uint8 Keypad_4x3_adjustSwitchNumber(uint8 button_no);
static uint8 Keypad_4x4_adjustSwitchNumber(uint8 button_no);

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

/*Function responsible for changing the no. of button pressed to its true value*/
uint8 Keypad_4x3_adjustSwitchNumber(uint8 button_no)
{
	switch (button_no)
	{
	case 10:
		return '*';
	case 11:
		return 0;
	case 12:
		return '#';
	}
}

/*Function responsible for changing the no. of button pressed to its true value*/
uint8 Keypad_4x4_adjustSwitchNumber(uint8 button_no)
{
	switch (button_no)
	{
	case 4:
		return 'A';
	case 5:
		return 4;
	case 6:
		return 5;
	case 7:
		return 6;
	case 8:
		return 'B';
	case 9:
		return 7;
	case 10:
		return 8;
	case 11:
		return 9;
	case 12:
		return 'C';
	case 13:
		return '*';
	case 14:
		return 0;
	case 15:
		return '#';
	case 16:
		return 'D';
	}
}
