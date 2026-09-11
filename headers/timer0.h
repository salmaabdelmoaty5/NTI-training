#ifndef TIMER0_H_
#define TIMER0_H_

#include "Std_types.h"
#define TCCR0   (*((volatile u8*)0x53))
#define WGM00   6
#define WGM01   3
#define CS02    2
#define CS01    1
#define CS00    0

#define TCNT0   (*((volatile u8*)0x52))
#define TIMSK   (*((volatile u8*)0x59))
#define TOIE0   0

#define SREG    (*((volatile u8*)0x5F))
#define I_BIT   7
#define TIMER0_OVF_vect   __vector_11

#define ISR(vector) \
    void vector(void) __attribute__((signal)); \
    void vector(void)



void TIMER0_init(void);
void TIMER0_setPreload(u8 preloadValue);
void TIMER0_setCallBack(void (*pCallback)(void));

#endif