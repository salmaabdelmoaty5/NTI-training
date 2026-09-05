/*
 * GccApplication12.c
 *
 * Created: 9/5/2026 3:40:46 PM
 * Author : Victus
 */ 

#include <avr/io.h>
#include "Std_types.h"
#include "DIO.h"
#include "Bit_Math.h"
#include <util/delay.h>

void HBridge_MoveForward(void)
{
	DIO_voidSetPinValue(PORTC, PIN0, HIGH);
	DIO_voidSetPinValue(PORTC, PIN2, HIGH);
	DIO_voidSetPinValue(PORTC, PIN1, LOW);
	DIO_voidSetPinValue(PORTC, PIN3, LOW);
}

void HBridge_MoveBackward(void)
{
	DIO_voidSetPinValue(PORTC, PIN1, HIGH);
	DIO_voidSetPinValue(PORTC, PIN3, HIGH);
	DIO_voidSetPinValue(PORTC, PIN0, LOW);
	DIO_voidSetPinValue(PORTC, PIN2, LOW);
}

void HBridge_Stop(void)
{
	DIO_voidSetPinValue(PORTC, PIN0, LOW);
	DIO_voidSetPinValue(PORTC, PIN1, LOW);
	DIO_voidSetPinValue(PORTC, PIN2, LOW);
	DIO_voidSetPinValue(PORTC, PIN3, LOW);
}

int main(void)
{
	
	DIO_voidSetPinDirection(PORTC, PIN0, OUTPUT);
	DIO_voidSetPinDirection(PORTC, PIN1, OUTPUT);
	DIO_voidSetPinDirection(PORTC, PIN3, OUTPUT);
	DIO_voidSetPinDirection(PORTC, PIN2, OUTPUT);

	while (1)
	{
		
		HBridge_MoveForward();
		_delay_ms(5000);
		
		HBridge_Stop();
		_delay_ms(5000);
		
		HBridge_MoveBackward();
		_delay_ms(5000);
		
		HBridge_Stop();
		_delay_ms(5000);
	}

	return 0;
}

