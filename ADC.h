/*
 * ADC.h
 *
 *      Author: Mahmoud Abdelghany
 */

#ifndef ADC_H_
#define ADC_H_

#include "avr_config.h"
#include "com_macros.h"
#include "Std_def.h"

/*Function responsible for initializing the ADC*/
void ADC_init(void);

/*Function responsible for converting analog data from specific channel to digital data*/
uint16 ADC_ReadChannel(uint8 channel);

/*Function responsible for initializing the ADC*/
void ADC_dinit(void);


#endif /* ADC_H_ */
