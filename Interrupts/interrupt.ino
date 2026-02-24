#include <avr/io.h>
#include <avr/interrupt.h>

ISR(INT0_vect){
  PORTC ^= (1<<PC0);
}

ISR(INT1_vect){
  for(int i= 0;i<5;i++){
    PORTC |= (1<<PC1) | (1<<PC2) | (1<<PC3);
    _delay_ms(500);
    PORTC &=~( (1<<PC1) | (1<<PC2) | (1<<PC3));
    _delay_ms(500);
  }

}

void setup(){
  SREG =0; 
  EIMSK = (1<<0)| (1<<1);
  DDRD &= ~(1 << PD2);
  DDRC |= ((1<<PC0) |(1<<PC1) | (1<<PC2) | (1<<PC3));
  PORTC =0;  
  EICRA = (1<<0)| (1<<1) | (1<<2)| (1<<3);
  SREG |= (1<<7);
}

void loop(){
  PORTC |= (1<<PC1);
  PORTC &= ~((1<<PC2) | (1<<PC3));
  _delay_ms(500);
  
  PORTC |= (1<<PC2);
  PORTC &= ~((1<<PC1) | (1<<PC3));
  _delay_ms(500);
  
  PORTC |= (1<<PC3);
  PORTC &= ~((1<<PC1) | (1<<PC2));
   _delay_ms(500);
}

