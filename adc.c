#include <avr/io.h>
#include <avr/interrupt.h>

#include "adc.h"

void ADC_init() {
    ADMUX |= (1 << REFS0);    // use AVcc as the reference
    ADCSRA |= (0 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);    // 8 prescale
    ADMUX |= (1 << ADLAR); // left adjust 8 bit
    ADCSRA |= (1 << ADIE); // enable Interrups
    ADCSRA |= (1 << ADEN);    // Enable the ADC
 
}

int ADC_read()
{
    int ADCval;

    ADCSRA |= (1 << ADSC);    // Start the ADC conversion

    ADCval = ADCH; // ADC value

    return ADCval;
}


