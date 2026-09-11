#include "DIO.h"
#include "ADC.h"
#include "TIMER0_CTC.h"
#include "Std_types.h"
#include <avr/interrupt.h>
 
#define LED_PORT     PORTB
#define LED_PIN      0
 
#define POT_CHANNEL  0   
void TIMER0_CompareMatch_ISR(void)
{
    static u8 ledState = LOW;
 
    ledState = (ledState == HIGH) ? LOW : HIGH;
    DIO_voidSetPinValue(LED_PORT, LED_PIN, ledState);
}
 
int main(void)
{
    u16 adcValue;
    u8  compareValue;
    DIO_voidSetPinDirection(LED_PORT, LED_PIN, OUTPUT);
    DIO_voidSetPinValue(LED_PORT, LED_PIN, LOW);
 
    ADC_Init();
 
    TIMER0_CTC_voidSetCallBack(TIMER0_CompareMatch_ISR);
    TIMER0_CTC_voidInit();
 
    sei();    
    while (1)
    {
        /* read the pot (0 - 1023) and scale it down to OCR0's
           8-bit range (0 - 255) */
        adcValue     = ADC_Read(POT_CHANNEL);
        compareValue = (u8)(adcValue >> 2);
 
        TIMER0_CTC_voidSetCompareValue(compareValue);
    }
 
    return 0;
}
