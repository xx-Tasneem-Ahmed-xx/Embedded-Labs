#include <avr/io.h>
volatile uint8_t tot_overflow;

ISR(TIMER2_OVF_vect){
  tot_overflow++;
}

float bcd =0;

void setup() {
  TIMSK2 |= (1 << TOIE0);
  sei();
  TCNT2=0;
  TCCR2B |= (1<<CS00) | (1<<CS01) | (1<<CS02);
  DDRC|=(1<<PC0);
  // PORTC &= ~(1<<PC0);
  PORTC=0;
}

void loop() {
  if (tot_overflow >= 15 && TCNT2 >= 66){    
    PORTC +=1;
    TCNT2 = 0; 
    tot_overflow = 0;
  }
}
