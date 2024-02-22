/*********************************************************/
/***********		Author: KARIM SILEEM 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: EXTI 		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 14-8/2020		 	**************/
/*********************************************************/



#ifndef  TIMER_INTERFACE_H_
#define  TIMER_INTERFACE_H_

void TIMER0_voidInit(void);

u8 TIMER0_u8SetCallBack(void(*copy_pvCallBack)(void));



#endif