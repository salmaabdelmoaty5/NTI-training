/*
 * GccApplication14.c
 *
 * Created: 9/6/2026 7:01:22 PM
 * Author : Victus
 */ 

#include "Std_types.h"
#include "Bit_Math.h"
#include "DIO.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "interrupt.h"

int main(void)
{
	DIO_voidSetPinDirection(PORTC, PIN0, OUTPUT);
	DIO_voidSetPinDirection(PORTC, PIN1, OUTPUT);
	DIO_voidSetPinDirection(PORTD, PIN2, INPUT);
	DIO_voidSetPinDirection(PORTD, PIN3, INPUT);

	EXTI_voidInit();
	sei();

	while (1)
	{
	}
}

ISR(INT0_vect)
{
	if (DIO_u8ReadPinValue(PORTC, PIN0) == HIGH)
	{
		DIO_voidSetPinValue(PORTC, PIN0, LOW);
	}
	else
	{
		DIO_voidSetPinValue(PORTC, PIN0, HIGH);
	}
}

ISR(INT1_vect)
{
	if (DIO_u8ReadPinValue(PORTC, PIN1) == HIGH)
	{
		DIO_voidSetPinValue(PORTC, PIN1, LOW);
	}
	else
	{
		DIO_voidSetPinValue(PORTC, PIN1, HIGH);
	}
}