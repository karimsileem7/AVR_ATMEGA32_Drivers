#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "GIE_interface.h"
#include "RTOS_interface.h"
void LED1(void);
void LED2(void);
void LED3(void);

void main(void)
{
	PORT_voidInit();
	GIE_voidEnable();

	RTOS_voidCreateTask(0,500,&LED1);
	RTOS_voidCreateTask(1,1000,&LED2);
	RTOS_voidCreateTask(2,1500,&LED3);

	RTOS_voidStart();
	while(1)
	{

	}
}

void LED1(void)
{
	static u8 LedState=0;
	TOGGLE_BIT(LedState,0);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,LedState);

}
void LED2(void)
{
	static u8 LedState=0;
	TOGGLE_BIT(LedState,0);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN1,LedState);
}
void LED3(void)
{
	static u8 LedState=0;
	TOGGLE_BIT(LedState,0);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN2,LedState);
}
