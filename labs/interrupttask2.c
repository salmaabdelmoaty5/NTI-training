#include "Std_types.h"
#include "Bit_Math.h"
#include "DIO.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "interrupt.h"

volatile s8 direction = 1;

int main(void)
{
	DIO_voidSetPortDirection(PORTC, 0b11111111);
	DIO_voidSetPinDirection(PORTB, PIN2, INPUT);
	DIO_voidSetPinValue(PORTB, PIN2, HIGH);
	EXTI_voidInit();
	s8 current_led = 0;
	while (1)
	{
		for (u8 i = 0; i < 8; i++)
		{
			if (i == current_led)
			{
				DIO_voidSetPinValue(PORTC, i, HIGH);
			}
			else
			{
				DIO_voidSetPinValue(PORTC, i, LOW);
		}}

		_delay_ms(200);
		current_led += direction;
		if (current_led > 7)
		{
			current_led = 0;
		}
		else if (current_led < 0)
		{
			current_led = 7;
		}
	}
}

ISR(INT2_vect)
{
	direction = -direction;
}
