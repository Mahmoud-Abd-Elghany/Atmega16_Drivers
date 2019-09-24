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

}ICU_config;

/*Description:
 * Function responible for initializing ICU
 * 1- Set prescaler
 * 2- Set Edge type at which you want to capture the value
 */
void ICU_init (const ICU_config *);

/*Description:
 *Function used to call another function after finishing the task
 */
void ICU_SetCallBack(void (*a_Fun_Ptr)(void));

/*Description:
 *Used to return value of ICU captured value
 */
uint16 ICU_getInputValue(void);

/*Description:
 *Change the edge at whch you want to capture value
 */
void ICU_SetEdgeDetectionType(edge);

/*Description:
 *Stop ICU
 */
void ICU_DeInit(void);



#endif /* ICU_H_ */
