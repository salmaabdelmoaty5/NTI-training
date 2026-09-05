#ifndef _STEPPER_H_
#define _STEPPER_H_

#include "Std_types.h"
#include <avr/io.h>
#include "Std_types.h"
#include "Bit_Math.h"

#define FULL_STEP         1
#define HALF_STEP         2
#define CLOCKWISE         1
#define COUNTERCLOCKWISE  0

void Stepper_voidInit(void);
void Stepper_voidRotate(u8 Copy_u8Direction, u8 Copy_u8Mode);




#endif