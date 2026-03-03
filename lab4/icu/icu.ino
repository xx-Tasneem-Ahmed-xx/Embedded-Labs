#include <avr/io.h>
#include <util/delay.h>

void setup() {
  DDRB &= ~(1<<PB0);   

  TCCR1A = 0x00;
  TCCR1B = (1<<ICNC1) | (1<<ICES1) | (1<<CS10);
  TCNT1=0; 
  TIFR1 = (1<<ICF1); 

  Serial.begin(9600);
}

unsigned int t;
void loop() {
  
  unsigned int first, second;
  while ((TIFR1 & (1<<ICF1)) == 0);
  first = ICR1;
  TIFR1 = (1<<ICF1);


  while ((TIFR1 & (1<<ICF1)) == 0);
  second = ICR1;
  TIFR1 = (1<<ICF1);


  if (second >= first)
    t = second - first;
  else
    t = (65536UL - first) + second;

  Serial.println(F_CPU/t);
  _delay_ms(50);
}