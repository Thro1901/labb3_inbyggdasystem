#include <avr/io.h>

#include "timer.h"

void timer_init() {

    // Timer0 Set the Fast PWN
    TCCR0A |= (1 << WGM01) | (1 << WGM00) | (1 << COM0A1);

    // Set the value (255) that you want to count to
    OCR0A = 255;
  
    //Timer0 set prescaler to 64 and start the timer
    TCCR0B |= (1 << CS01) | (1 << CS00);


    // Timer2 CTC mode
    TCCR2A |= (1 << WGM21);

    // Counts up with each pulse. MAX 255
    TCNT2 = 0;

    //Timer2  set prescaler to 1024 and start the timer
    TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20);

    TIMSK2 |= (1 << OCIE2A); // compair match A Enable interups
   

}
