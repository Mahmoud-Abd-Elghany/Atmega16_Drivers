/*
 * Interrupts.h
 *
 *  Created on: Sep 12, 2019
 *      Author: Ma7amee7o
 */

#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include "DIO.h"
#include "Avr_MOD.h"
#include "STD_Def.h"

#define Enable_GI (BIT_IS_SET (SREG,7)) /* Enable the global interrupt flag */
#define Disable_GI (BIT_IS_CLEAR (SREG,7)) /* Disable the global interrupt flag */

/* choosing which external interrupt to Enable
 * put INT_NO by 0 to enable INT0
 * put INT_NO by 1 to enable INT1
 * put INT_NO by 2 to enable INT2
 */
void Enable_Int (uint8 INT_NO);

/* choosing which external interrupt to Disable
 * put INT_NO by 0 to Disable INT0
 * put INT_NO by 1 to Disable INT1
 * put INT_NO by 2 to Disable INT2
 */
void Disable_Int (uint8 INT_NO);

/*Choosing mode for INT0
 * 0 : Interrupt for any logical change
 * 1 : Interrupt for every falling edge
 * 2 : Interrupt for every rising edge
 */
void INT0_mode (uint8 Mode);

/*Choosing mode for INT1
 * 0 : Interrupt for any logical change
 * 1 : Interrupt for every falling edge
 * 2 : Interrupt for every rising edge
 */
void INT1_mode (uint8 Mode);

/*Choosing mode for INT2
 * 1 : Interrupt for every falling edge
 * 2 : Interrupt for every rising edge
 */
void INT2_mode (uint8 Mode);


#endif /* INTERRUPTS_H_ */
