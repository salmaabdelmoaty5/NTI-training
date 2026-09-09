#ifndef _UART_H_
#define _UART_H_
#include "Std_types.h"
#include <avr/io.h>
#include "Bit_Math.h"


void UART_Init(void);

void UART_SendChar(u8 copy_u8Data);

u8 UART_GetChar(void);




#endif