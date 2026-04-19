#include <avr/io.h>
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ADMUX = (1<<REFS0);
  ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
  DDRB = 0x20;
}
  uint16_t adc_result0;

uint16_t adc_read(uint8_t ch)
{

  ch &= 0b00000111;
  ADMUX = (ADMUX & 0xF8)|ch; // clears the bottom 3 bits before ORing

  ADCSRA |= (1<<ADSC);

  while(ADCSRA & (1<<ADSC));

  return (ADC);
}

void loop() {
  adc_result0 = adc_read(0);
  Serial.println(adc_result0);

}
