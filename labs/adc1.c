#include <avr/io.h>
#include "Std_types.h"
#include "Bit_Math.h"
#include "DIO.h"
#include "ADC.h"

int main(void)
{
	u16 DigitalValue = 0;
	f32 InputVoltage = 0.0;

	DIO_voidSetPinDirection(PORTA, PIN0, INPUT);
	DIO_voidSetPinDirection(PORTC, PIN0, OUTPUT); 
	DIO_voidSetPinDirection(PORTC, PIN1, OUTPUT); 
	DIO_voidSetPinDirection(PORTC, PIN2, OUTPUT);
	ADC_Init();
	while (1)
    {
        DigitalValue = ADC_Read(0);
        InputVoltage = ((u32)DigitalValue * 5000UL) / 1024UL;
        if (InputVoltage > 0 && InputVoltage < 1500)
        {
            DIO_voidSetPinValue(PORTC, PIN0, HIGH);
            DIO_voidSetPinValue(PORTC, PIN1, LOW);
            DIO_voidSetPinValue(PORTC, PIN2, LOW);
        }
        else if (InputVoltage >= 1500 && InputVoltage < 3000)
        {
            DIO_voidSetPinValue(PORTC, PIN0, LOW);
            DIO_voidSetPinValue(PORTC, PIN1, HIGH);
            DIO_voidSetPinValue(PORTC, PIN2, LOW);
        }
        else if (InputVoltage >= 3000)
        {
            DIO_voidSetPinValue(PORTC, PIN0, LOW);
            DIO_voidSetPinValue(PORTC, PIN1, LOW);
            DIO_voidSetPinValue(PORTC, PIN2, HIGH);
        }
        else
        {
            DIO_voidSetPinValue(PORTC, PIN0, LOW);
            DIO_voidSetPinValue(PORTC, PIN1, LOW);
            DIO_voidSetPinValue(PORTC, PIN2, LOW);
        }
    }

    return 0;
}