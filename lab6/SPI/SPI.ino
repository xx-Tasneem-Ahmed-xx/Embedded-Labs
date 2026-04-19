#include <avr/io.h>

#define SS PB2
#define MOSI PB3
#define MISO PB4
#define SCK PB5
// #define SPIF 7


void SPI_INIT(){
  DDRB |= (1<<MOSI)|(1<<SCK)|(1<<SS);
  DDRB &= ~(1<<MISO);
  PORTB |= (1<<SS);
  // SPCR = (1<<6) | (1<<4) | (1<<0);
  SPCR = (1<<SPE) | (1<<MSTR) | (1<<SPR0); 
  // SPSR &= ~(1<<0);

}

int SPI_Read(){
  SPDR = 0xff;
  while(!(SPSR & (1<<SPIF)));
  return(SPDR);
}

void SPI_Write(int data){
  int flush_buffer;
  SPDR = data;
  while(!(SPSR & (1<<SPIF)));
  flush_buffer = SPDR;
  // int DUMP = SPIF;
}

void setup() {
  SPI_INIT();
  Serial.begin(9600);
  delay(1000);
}
int Transmit(int data){
  int flush_buffer;
  SPDR = data;
  while(!(SPSR & (1<<SPIF)));
  flush_buffer = SPDR;
  return flush_buffer;
}


int counter = 0;

void loop() {
  PORTB &= ~(1<<SS);              // Select slave

  int received = Transmit(counter);  // Send + Receive in SAME step

  PORTB |= (1<<SS);              // Deselect slave

  Serial.println(received);      // Print received data

  counter++;
  _delay_ms(100);
}
