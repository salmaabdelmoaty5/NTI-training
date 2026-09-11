#include "timer0.h"
#include "Bit_math.h"
static void (*g_timer0Callback)(void) = NULL;

void TIMER0_init(void)
{

    CLR_BIT(TCCR0, WGM00);
    CLR_BIT(TCCR0, WGM01);

    SET_BIT(TCCR0, CS00);
    CLR_BIT(TCCR0, CS01);
    SET_BIT(TCCR0, CS02);

    SET_BIT(TIMSK, TOIE0);
}

void TIMER0_setPreload(u8 preloadValue)
{
    TCNT0 = preloadValue;
}

void TIMER0_setCallBack(void (*pCallback)(void))
{
    if (pCallback != NULL)
    {
        g_timer0Callback = pCallback;
    }
}

ISR(TIMER0_OVF_vect)
{
    if (g_timer0Callback != NULL)
    {
        g_timer0Callback();
    }
}