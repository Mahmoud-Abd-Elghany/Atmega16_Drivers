/*
 * Keypad.c
 *
 *  Created on: Sep 14, 2019
 *      Author: Ma7amee7o
 */

#include "Keypad.h"



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
		return Keypad_4x3_adjustSwitchNumber(row,col);
#elif(N_col==4)
		return Keypad_4x4_adjustSwitchNumber(row,col);
#endif
		}

	}


}

uint8 Keypad_4x3_adjustSwitchNumber(uint8 row,uint8 col)
{

}

uint8 Keypad_4x4_adjustSwitchNumber(uint8 row,uint8 col)
{

}
