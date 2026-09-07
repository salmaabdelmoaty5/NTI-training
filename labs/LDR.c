#include "Std_types.h"
#include "Bit_Math.h"
#include "DIO.h"
#include "ADC.h"

int main(void)
{
    ADC_Init();
    DIO_voidSetPinDirection(PORTC, PIN0, OUTPUT);
    u16 adc = 0;
    u32 resist = 0;
    u32 R_known = 1000UL; 
    while (1)
    {
        adc = ADC_Read(0);
        if (adc > 0)
        {
            resist = (R_known * (1023UL - adc)) /adc;
        }
        if (resist > 2000UL) 
        {
            DIO_voidSetPinValue(PORTC, PIN0, HIGH); 
        }
        else
        {
            DIO_voidSetPinValue(PORTC, PIN0, LOW);  
        }
    }

    return 0;
}