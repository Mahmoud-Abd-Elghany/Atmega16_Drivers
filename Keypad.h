/*
 * Keypad.h
 *
 *  Created on: Sep 14, 2019
 *      Author: Ma7amee7o
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

#endif /* KEYPAD_H_ */
