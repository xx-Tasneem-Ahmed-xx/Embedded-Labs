#include <avr/io.h>
volatile uint8_t tot_overflow;

ISR(TIMER2_OVF_vect){
  tot_overflow++;
}

float bcd = 0;

void setup() {
  TIMSK2 |= (1 << TOIE0);
  sei();
  TCNT2=0;
  TCCR2B |= (1<<CS00) | (1<<CS01) | (1<<CS02);
  DDRC|=(1<<PC0) | (1<<PC1) | (1<<PC2) | (1<<PC3);
  PORTC=0;
}

void loop() {
  if (tot_overflow >= 15 && TCNT2 >= 66){    
    PORTC +=1;
    if (PORTC > 9) PORTC = 0;
    TCNT2 = 0; 
    tot_overflow = 0;
  }
}
