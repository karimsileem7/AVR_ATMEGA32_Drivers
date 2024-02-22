/**********************************************************************/
/**********************************************************************/
/*****************		Author: Amgad Samir		***********************/
/*****************		Layer:	RTOS Stack		***********************/
/*****************		SWC:	TIMER			***********************/
/*****************		Version:1.00			***********************/
/**********************************************************************/
/**********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER_interface.h"
#include "TIMER_register.h"
#include "TIMER_private.h"
#include "TIMER_config.h"

static void (*TIMER0_pvCallBackFunc)(void)=NULL;

void TIMER0_voidInit(void)
{
	/*Choose CTC Mode*/
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	/*Set compare match value to 125 for 1ms compare time*/
	OCR0=125;

	/*Compare match interrupt enable*/
	SET_BIT(TIMSK,TIMSK_OCIE0);

	/*Precaler: Division by 64*/
	SET_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);
}

u8 TIMER0_u8SetCallBack(void (*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorStatus=OK;

	if(Copy_pvCallBackFunc!=NULL)
	{
		TIMER0_pvCallBackFunc= Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorStatus=NULL_POINTER;
	}

	return Local_u8ErrorStatus;
}

/*CTC ISR*/
void __vector_10 (void)	__attribute__((signal));
void __vector_10 (void)
{
	if(TIMER0_pvCallBackFunc!= NULL)
	{
		TIMER0_pvCallBackFunc();
	}
}
