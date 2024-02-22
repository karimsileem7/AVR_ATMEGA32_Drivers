/*********************************************************/
/***********		Author: KARIM SILEEM 	**************/
/***********		Layer: MCAL			 	**************/
/***********		Component: EXTI 		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 14-8/2020		 	**************/
/*********************************************************/



#ifndef  TIMER_REGISTER_H_
#define  TIMER_REGISTER_H_

#define  TCCR0         *((volatile u8*)0x53)               //Timer0 control register
#define  TCCR0_WGM00   6                                  //waveform generation mode bit0
#define  TCCR0_WGM01   3                                 //waveform generation mode bit1
#define  TCCR0_CS02    2                                //prescaler bit2
#define  TCCR0_CS01    1                               //prescaler bit1
#define  TCCR0_CS00    0                              //prescaler bit0

#define  OCR0          *((volatile u8*)0x5C)        //output compare register  0


#define  TIMSK         *((volatile u8*)0x59)      //Timer mask
#define  TIMSK_OCIE0   1                         //output compare 0 interrupt enable


#endif