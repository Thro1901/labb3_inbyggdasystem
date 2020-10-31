#include <avr/io.h>
#include <stdio.h> 

#include "enum.h"
#include "stateexecuter.h"
#include "led.h"
#include "timer.h"

void ExecuteState(int adc_val) {
	switch (STATE)
	{
	case 0:
		TCCR0A |= (1 << COM0A1); // enable OCR0A
		OCR0A = simple_ramp();	
		break;
	case 1:
		ADCSRA |= (1 << ADSC); // Start the ADC conversion
		OCR0A = adc_val;
		break;
	case 2:
		TCCR0A &= ~(1 << COM0A1);  // disable OCR0A
		TOGGLE_led();
		break;
	case 3:
		PORTD &= ~(1 << PD6); // Turn off led. Put PD6 to LOW.
		break;

	default:
		break;
	}
}


