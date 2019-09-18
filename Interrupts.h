/*
 * Interrupts.h
 *
 *      Author: Mahmoud Abdelghany
 */

#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include "avr_config.h"
#include "com_macros.h"
#include "Std_def.h"

/* choosing which external interrupt to Enable
 * put INT_NO by 0 to enable INT0
 * put INT_NO by 1 to enable INT1
 * put INT_NO by 2 to enable INT2
 */
void Enable_Ext_Int (uint8 INT_NO);

/* choosing which external interrupt to Disable
 * put INT_NO by 0 to Disable INT0
 * put INT_NO by 1 to Disable INT1
 * put INT_NO by 2 to Disable INT2
 */
void Disable_Ext_Int (uint8 INT_NO);

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
