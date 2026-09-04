#include "Std_Types.h"
#include "Bit_Math.h"
#include <avr/io.h>
#include <util/delay.h>
#include "keypad.h"

void KEYPAD_init(void) {
	DIO_voidSetPortDirection(PORTD, 0x0F);
	DIO_voidSetPortDirection(PORTC, 0x00);
	
	// Enable internal pull-up resistors for input rows (PC0 - PC3)
	DIO_voidSetPinValue(PORTC, 0, HIGH);
	DIO_voidSetPinValue(PORTC, 1, HIGH);
	DIO_voidSetPinValue(PORTC, 2, HIGH);
	DIO_voidSetPinValue(PORTC, 3, HIGH);
}

char KEYPAD_getPressedKey(void) {
	const u8 keypad_matrix[4][4] = {
		{'7', '8', '9', '/'},
		{'4', '5', '6', '*'},
		{'1', '2', '3', '-'},
		{'C', '0', '=', '+'}
	};

	u8 col, row;
	u8 col_patterns[4] = {0x0E, 0x0D, 0x0B, 0x07};

	for (col = 0; col < 4; col++) {
		DIO_voidSetPortValue(PORTD, col_patterns[col]);
		_delay_ms(2);
	
	
		if (DIO_u8ReadPinValue(PORTC, 0) == 0) { row = 0; _delay_ms(20); while(DIO_u8ReadPinValue(PORTC, 0) == 0); return keypad_matrix[row][col]; }
		if (DIO_u8ReadPinValue(PORTC, 1) == 0) { row = 1; _delay_ms(20); while(DIO_u8ReadPinValue(PORTC, 1) == 0); return keypad_matrix[row][col]; }
		if (DIO_u8ReadPinValue(PORTC, 2) == 0) { row = 2; _delay_ms(20); while(DIO_u8ReadPinValue(PORTC, 2) == 0); return keypad_matrix[row][col]; }
		if (DIO_u8ReadPinValue(PORTC, 3) == 0) { row = 3; _delay_ms(20); while(DIO_u8ReadPinValue(PORTC, 3) == 0); return keypad_matrix[row][col]; }
	}

	return '\0';
}
