#include <avr/io.h>
#include <avr/interrupt.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ADMUX = (1<<REFS0);
  ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)| (1<<ADIE);
  DDRB = 0x20;
  sei();
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
 
  Serial.println(adc_read(0));

}
