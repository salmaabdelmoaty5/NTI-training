/*
 * GccApplication11.c
 *
 * Created: 9/3/2026 6:17:44 PM
 * Author : Victus
 */ 

#include <avr/io.h>
#include "Bit_Math.h"
#include "Std_types.h"
#include "DIO.h"
#include "LCD.H"
#define F_CPU 8000000UL
#include <util/delay.h>


int main(void)
{
    LCD_init();
	LCD_SendString ((u8 *)"Salma");
    while (1) 
    {
    }
}