#include "Std_types.h"
#include "BIT_MATH.h"
#include "UART.h"


#define UDR      (*(volatile u8*)0x2C)
#define UCSRA    (*(volatile u8*)0x2B)
#define UCSRB    (*(volatile u8*)0x2A)
#define UCSRC    (*(volatile u8*)0x40)
#define UBRRL    (*(volatile u8*)0x29)
#define UBRRH    (*(volatile u8*)0x40)


#define UDRE     5
#define RXC      7

void UART_Init(void)
{

    UCSRB = 0b00011000;
    UCSRC = 0b10000110;
    UBRRH = 0;
    UBRRL = 51;
}

void UART_SendChar(u8 copy_u8Data)
{
    while (!GET_BIT(UCSRA, UDRE));
    UDR = copy_u8Data;
}

u8 UART_GetChar(void)
{
    while (!GET_BIT(UCSRA, RXC));
    return UDR;
}

