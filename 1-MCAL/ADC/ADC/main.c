#include "STD_TYPES.h"

#include "PORT_interface.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "GIE_interface.h"
void ADCNotification (void);


u8 App_u8ADCReading;
void main (void)
{
	PORT_voidInit();

	ADC_voidInit();

	/*Enable global interrupts*/
	GIE_voidEnable();
	while(1)
	{
		ADC_u8StartConversionAsynch(0,&App_u8ADCReading,&ADCNotification);
	}
}

void ADCNotification (void)
{
	DIO_u8SetPortValue(DIO_u8PORTC,App_u8ADCReading);
}
