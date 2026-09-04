/*
 * GccApplication10.c
 *
 * Created: 9/2/2026 10:17:34 PM
 * Author : Victus
 */ 
#include <avr/io.h>
 #include "Bit_Math.h"
 #include "Std_types.h"
 #include "DIO.h"



int main(void)
{

    DIO_voidSetPinDirection(PORTA,PIN0,INPUT);
	DIO_voidSetPinDirection(PORTA,PIN1,INPUT);
	DIO_voidSetPinDirection(PORTA,PIN2,INPUT);
	DIO_voidSetPinDirection(PORTA,PIN7,INPUT);
	
	DIO_voidSetPinDirection(PORTC,PIN0,OUTPUT);
	DIO_voidSetPinDirection(PORTC,PIN1,OUTPUT);
	DIO_voidSetPinDirection(PORTC,PIN2,OUTPUT);	
	
    while (1)
    {
	    if (DIO_u8ReadPinValue(PORTA, PIN7) == 0)
	    {
		    DIO_voidSetPinValue(PORTC, PIN0, HIGH);
		    DIO_voidSetPinValue(PORTC, PIN1, HIGH);
		    DIO_voidSetPinValue(PORTC, PIN2, HIGH);
	    }
	    else
	    {
		    if (DIO_u8ReadPinValue(PORTA, PIN0) == 0)
		    {
			    DIO_voidSetPinValue(PORTC, PIN0, HIGH);
		    }
		    else
		    {
			    DIO_voidSetPinValue(PORTC, PIN0, LOW);
		    }

		    if (DIO_u8ReadPinValue(PORTA, PIN1) == 0)
		    {
			    DIO_voidSetPinValue(PORTC, PIN1, HIGH);
		    }
		    else
		    {
			    DIO_voidSetPinValue(PORTC, PIN1, LOW);
		    }

		    if (DIO_u8ReadPinValue(PORTA, PIN2) == 0)
		    {
			    DIO_voidSetPinValue(PORTC, PIN2, HIGH);
		    }
		    else
		    {
			    DIO_voidSetPinValue(PORTC, PIN2, LOW);
		    }
	    }
		
    }
	
    }
