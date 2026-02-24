#include <avr/io.h>
volatile uint8_t tot_overflow;

void setup() {
  TCCR2A=0;
  TCCR2B=0;
  TCCR2B |= (1<<3) | (1<<CS20) | (1<<CS21) | (1<<CS22);
  
  DDRC|=(1<<PC0);
  PORTC &= ~(1<<PC0);

  OCR2A = 126;
  tot_overflow=0;
  TIMSK2 |= (1 << OCIE2A);
  sei();
}

ISR(TIMER2_COMPA_vect){
  tot_overflow++;
  
  if (tot_overflow >= 31){
    PORTC ^= (1 << 0);
    tot_overflow = 0; 
  }
}

void loop() {
}
