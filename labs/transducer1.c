#include "Std_types.h"
#include "Bit_Math.h"
#include "DIO.h"
#include "ADC.h"

int main(void)
{
    u16 ADC_Reading = 0;
    u32 mv_value = 0;
    u32 Tempreture_value = 0;
    DIO_voidSetPinDirection(PORTB, PIN0, OUTPUT); //buzzer
    DIO_voidSetPinDirection(PORTA, PIN0, INPUT);
    DIO_voidSetPinDirection(PORTC, PIN0, OUTPUT);
    DIO_voidSetPinDirection(PORTC, PIN1, OUTPUT);
    DIO_voidSetPinDirection(PORTC, PIN2, OUTPUT);
    ADC_Init();

    while (1)
    {
        ADC_Reading = ADC_Read(0);
        mv_value = ((u32)ADC_Reading * 5000UL) / 1024UL;
        Tempreture_value = mv_value / 10UL;
        if (Tempreture_value < 20)
        {
            DIO_voidSetPinValue(PORTC, PIN0, HIGH);
            DIO_voidSetPinValue(PORTC, PIN1, LOW);
            DIO_voidSetPinValue(PORTC, PIN2, LOW);
			DIO_voidSetPinValue(PORTB, PIN0, LOW);
        }
        else if (Tempreture_value >= 20 && Tempreture_value < 40)
        {
            DIO_voidSetPinValue(PORTC, PIN0, LOW);
            DIO_voidSetPinValue(PORTC, PIN1, HIGH);
            DIO_voidSetPinValue(PORTC, PIN2, LOW);
			DIO_voidSetPinValue(PORTB, PIN0, LOW);
        }
        else
        {
            DIO_voidSetPinValue(PORTC, PIN0, LOW);
            DIO_voidSetPinValue(PORTC, PIN1, LOW);
            DIO_voidSetPinValue(PORTC, PIN2, HIGH);
			DIO_voidSetPinValue(PORTB, PIN0, HIGH);
        }
    }

    return 0;
}