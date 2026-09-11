
#include "DIO.h"
#include "timer0.h"
#include "Std_types.h"
#include <avr/interrupt.h>
 
#define LED_PORT   PORTA
#define LED_PIN    0
 
void TIMER0_ISR(void)
{
    static u8 overflowCount = 0;
    static u8 ledState = LOW;
 
    overflowCount++;
 
    if (overflowCount == 30)
    {
        TIMER0_setPreload(124);       }
    else if (overflowCount > 30)
    {
        ledState = (ledState == HIGH) ? LOW : HIGH;
        DIO_voidSetPinValue(PORTA, PIN0, ledState);
 
        overflowCount = 0;
        TIMER0_setPreload(0);    
    }
}
 
int main(void)
{
    DIO_voidSetPinDirection(LED_PORT, LED_PIN, OUTPUT);
    DIO_voidSetPinValue(LED_PORT, LED_PIN, LOW);
 
    TIMER0_setCallBack(TIMER0_ISR);
    TIMER0_init();
 
    sei();    
    while (1)
    {
        
    }
 
    return 0;
}