
#include "Std_types.h"
#include <avr/io.h>
#include "Bit_Math.h"
#include <avr/interrupt.h>
#include "interrupt.h"

void EXTI_voidInit(void)
{
	
	CLR_BIT(MCUCR, ISC01);
	SET_BIT(MCUCR, ISC00);	
	CLR_BIT(MCUCR, ISC11);
	SET_BIT(MCUCR, ISC10);

	//hena baftah el PIE LL INTO WL INT1
	SET_BIT(GICR, INT0);
	SET_BIT(GICR, INT1);
}