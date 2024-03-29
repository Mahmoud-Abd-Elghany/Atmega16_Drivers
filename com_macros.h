/*
 * com_macros.h
 *
 *      Author: Mahmoud Abdelghany
 */

#ifndef COM_MACROS_H_
#define COM_MACROS_H_

#define ENABLE_GI (BIT_IS_SET (SREG,7)) /* Enable the global interrupt flag  */
#define DISABLE_GI (BIT_IS_CLEAR (SREG,7)) /* Disable the global interrupt flag */


/* Setting */
#define SET_BIT(REG,BIT_NUM) (REG = REG | (1<<BIT_NUM)) /* Setting bit to 1 */
#define CLEAR_BIT(REG,BIT_NUM) (REG = REG & (~(1<<BIT_NUM))) /* Setting bit to 0 */
#define TOGGLE_BIT(REG,BIT_NUM) (REG = REG ^ (1<<BIT_NUM)) /* Toggle the bit between 0 and 1*/

/* Rotating */
#define ROR(REG,BIT_NUM) (REG = (REG >> BIT_NUM) | (REG << (8-BIT_NUM))) /* Rotating bits to Right */
#define ROL(REG,BIT_NUM) (REG = (REG << BIT_NUM) | (REG >> (8-BIT_NUM))) /* Rotating bits to Left */

/* Checking */
#define BIT_IS_SET(REG,BIT_NUM) (REG & (1<<BIT_NUM)) /* Checking if the bit is 1 (True if 1) */
#define BIT_IS_CLEAR(REG,BIT_NUM) (!(REG & (1<<BIT_NUM))) /* Checking if the bit is 0 (True if 0) */

#endif /* COM_MACROS_H_ */
