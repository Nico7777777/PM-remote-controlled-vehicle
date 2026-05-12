#include <Arduino.h>
#include "avr/io.h>"
#include "avr/interrupt.h"

// TODOs
// I. On the remote control
// TODO 1: set output ports for the four buttons and RF transmitter
// TODO 2: configure interrupts for button trigger (optional: with debounce)
// TODO 3: implement button press handling and RF signal transmission
// TODO 4: Store the last pressed buttons in the last 500 ms for future feature adding as encoded additional commands

// II. On the slim shady car
// TODO 5: set input ports for RF receiver and output ports for motor control
// TODO 6: SPI interface for ultrasounds module for collision detection
// TODO 7: implement RF signal reception and motor control logic
// TODO 8: implement collision detection and response using ultrasound data
// TODO 9: trigger data saving; still need to think up what data should be included in the structure
void init() {
  // PINS 3,4,5,6 are LEFT, BACK, RIGHT, FRONT buttons
  // uC PINS 3, 4, 5, 6 on port B corresponding to Arduino SBD PINS 2, 3, 4, 5
  PORTB &= ~(1 << PORTB2) | ~(1 << PORTB3) | ~(1 << PORTB4) | ~(1 << PORTB5);
  DDRB &= ~(1 << DDB2) | ~(1 << DDB3) | ~(1 << DDB4) | ~(1 << DDB5);
}
void main() {
  
}