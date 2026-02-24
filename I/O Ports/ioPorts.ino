#include <avr/io.h>
#include <util/delay.h>


void setup() {
    // Configure PD6 as output
    DDRD |= (1 << PD6);

    // LED OFF initially (negative logic → HIGH = OFF)
    PORTD |= (1 << PD6);
}

void loop() {
    // LED ON
    PORTD &= ~(1 << PD6);
    _delay_ms(1000);

    // LED OFF
    PORTD |= (1 << PD6);
    _delay_ms(1000);

}