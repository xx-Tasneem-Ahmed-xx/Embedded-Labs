#include <avr/io.h>
#include <util/delay.h>


void setup() {
    // PB0, PB1, PB2 as INPUT (switches)
    DDRB &= ~((1 << PB0) | (1 << PB1) | (1 << PB2));

    // switches are pull-down
    PORTB &= ~((1 << PB0) | (1 << PB1) | (1 << PB2));

    // PC0, PC1 as OUTPUT (L293D inputs)
    DDRC |= (1 << PC0) | (1 << PC1);

    // Motor initially at rest
    PORTC &= ~((1 << PC0) | (1 << PC1));

    Serial.begin(9600);
}

void loop() {
  // First switch pressed → Clockwise
  if (PINB & (1 << PB0))
  {
    PORTC |= (1 << PC1);   // IN2 = 1
    PORTC &= ~(1 << PC0);  // IN1 = 0
  }

  // Second switch pressed → Anti-clockwise
  else if (PINB & (1 << PB1))
  {
    PORTC |= (1 << PC0);   // IN1 = 1
    PORTC &= ~(1 << PC1);  // IN2 = 0
  }

  // Third switch pressed → Stop motor
  else if (PINB & (1 << PB2))
  {
    PORTC &= ~((1 << PC0) | (1 << PC1));
  }
}