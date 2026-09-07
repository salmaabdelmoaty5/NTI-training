#include "Std_types.h"
#include "Bit_Math.h"
#include <util/delay.h>
#include "DIO.h"
#include "ADC.h"
#include "LCD.H"

int main(void)
{
    u16 DigitalValue = 0;
    u32 InputVoltage = 0;
    ADC_Init();
    LCD_init();
    DIO_voidSetPinDirection(PORTA, PIN0, INPUT);
    GoToXY(0, 0);
    LCD_SendString((u8 *)"Volt: ");
    while (1)
    {
        DigitalValue = ADC_Read(0);
        InputVoltage = ((u32)DigitalValue * 5000UL) / 1024UL;
        GoToXY(6, 0);
        LCD_voidWriteNumber(InputVoltage);
        LCD_SendString((u8 *)" mV   ");
        _delay_ms(1000);
    }

    return 0;
}