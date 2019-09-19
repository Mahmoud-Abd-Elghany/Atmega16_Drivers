/*
 * ICU.h
 *
 *      Author: Mahmoud Abdelghany
 */

#ifndef ICU_H_
#define ICU_H_

#include "avr_config.h"
#include "com_macros.h"
#include "Std_def.h"

typedef enum
{
	FALLING,RISING
}edge;

typedef enum
{
	Prescaler_1=1,Prescaler_8,Prescaler_64,Prescaler_256,Prescaler_1024
}clock;

typedef struct
{
	clock prescaler;
	edge edgetype;

}config;

#endif /* ICU_H_ */
