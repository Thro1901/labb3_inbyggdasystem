#include <avr/io.h>
#include <stdio.h> 
#include <avr/pgmspace.h>


#include "enum.h"
#include "statehandler.h"
#include "stateexecuter.h"


void stateHandler(int *button_pressed_count) {

	switch (*button_pressed_count) // handle state with button count
	{
	case 1:
		STATE = PULSE;
		break;
	case 2:
		STATE = FADE;
		break;
	case 3:
		STATE = TOGGLE;
		break;
	case 4:
		STATE = OFF;
		break;

	default:
		break;
	}
}

