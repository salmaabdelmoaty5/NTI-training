#include <avr/io.h>
#include "Std_types.h"
#include "DIO.h"
#include "Bit_Math.h"
#include <util/delay.h>

int main(void)
{

	DIO_voidSetPinDirection(PORTC, PIN0, OUTPUT);
	
	while (1)
	{
		DIO_voidSetPinValue(PORTC, PIN0, HIGH);
		_delay_ms(3000);
		DIO_voidSetPinValue(PORTC, PIN0, LOW);
		_delay_ms(3000);
	}

	return 0;
}