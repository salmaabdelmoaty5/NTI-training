/*
 * GccApplication13.c
 *
 * Created: 9/5/2026 5:52:10 PM
 * Author : Victus
 */ 

/* main.c */
#include "Std_types.h"
#include "DIO.h"
#include "stepper.h"
#include <util/delay.h>
#define F_CPU 8000000UL

int main(void)
{
	Stepper_voidInit();
	while (1)
	{
		Stepper_voidRotate(CLOCKWISE, FULL_STEP);
	}

	return 0;
}