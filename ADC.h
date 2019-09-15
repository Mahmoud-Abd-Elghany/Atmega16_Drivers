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

typedef enum
{
	AREF,AVCC,IntVref=3
}ADC_source;


typedef enum
{
	Prescaler_2,Prescaler_4 =2,Prescaler_8,Prescaler_16,Prescaler_32,Prescaler_64,Prescaler_128
}ADC_prescaler;

typedef struct
{
	ADC_prescaler prescaler;
	ADC_source source;
}ADC_config;


/*Function responsible for initializing the ADC
 * 1- Set the prescaler (Prescaler_2 .... Prescaler_128).
 * 2- Select which source to use.
*/
void ADC_init(ADC_config *ADC_config_Ptr);

/*Function responsible for converting analog data from specific channel to digital data*/
uint16 ADC_ReadChannel(uint8 channel);

/*Function responsible for initializing the ADC*/
void ADC_dinit(void);


#endif /* ADC_H_ */
