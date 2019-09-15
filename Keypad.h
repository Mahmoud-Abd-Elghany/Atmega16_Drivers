/*
 * Keypad.h
 *
 *      Author: Mahmoud Abdelghany
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "avr_config.h"
#include "com_macros.h"
#include "Std_def.h"

#define KEY_PORT_DIR DDRA
#define KEY_PORT_OUT PORTA
#define KEY_PORT_IN PORTA

#define N_row 4
#define N_col 3

/*Function responsible for detecting the key pressed in the keypad and returning its value */
uint8 Keypad_getPressedKey(void);

#endif /* KEYPAD_H_ */
