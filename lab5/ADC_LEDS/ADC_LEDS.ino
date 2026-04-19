#include <avr/io.h>
#include <avr/interrupt.h>

void setup() {
  Serial.begin(9600);
  ADMUX = (1<<REFS0);
  ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)| (1<<ADIE);
  DDRB = 0x20;
  sei();
  // Configure PD6 as output
  DDRD |= (1 << PD4)|(1 << PD5)| (1 << PD2)| (1 << PD3);
  PORTD = 0x0;
}

uint16_t adc_result0;
bool ADC_endconversion_Flag=0;

ISR(ADC_vect){
  ADC_endconversion_Flag=1;
}

uint16_t adc_read(uint8_t ch)
{

  ch &= 0b00000111;
  ADMUX = (ADMUX & 0xF8)|ch; // clears the bottom 3 bits before ORing

  ADCSRA |= (1<<ADSC);
   if(ADC_endconversion_Flag ==1)
    {
      ADC_endconversion_Flag=0;
      return (ADC);
    }
    else return (-1);
}

void loop() {
 uint16_t adc_result = adc_read(0);
 Serial.println(adc_result);
 if(adc_result <= 20 ){
    PORTD = 0x0;
 }
 else if(adc_result <= 256){
    PORTD = 0x0;
   PORTD |= (1<<PD2);
 }
 else if(adc_result <= 512){
    PORTD = 0x0;
  PORTD |=  (1<<PD3)|(1<<PD2);

 }
  else if(adc_result<=768)
   {
    PORTD = 0x0;
    PORTD |= (1<<PD4)| (1<<PD3)|(1<<PD2);
  }
  else if(adc_result <= 1024){
    PORTD = 0x0;
    PORTD |= (1<<PD5)| (1<<PD4)| (1<<PD3)|(1<<PD2);
  }
}
