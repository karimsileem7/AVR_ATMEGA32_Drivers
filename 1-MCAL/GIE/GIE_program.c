/*********************************************************/
/***********		Author: KARIM SILEEM 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: EXTI 		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 14-8/2020		 	**************/
/*********************************************************/


#include "STD_TYPES"
#include "BIT_MATH"
#include  "EXTI_interface.h"
#include  "EXTI_register.h"

void GIE_voidEnable(void)
{
	SET_BIT(SREG,SREG_I);
}
void GIE_voidDisable(void)
{
	CLR_BIT(SREG,SREG_I);
}