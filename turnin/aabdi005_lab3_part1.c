/*	Author: aabdi005
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0x00; PORTB = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;

    unsigned char tmpA = 0x00;
    unsigned char tmpB = 0x00;
    unsigned char bits = 0x00;
    unsigned short iter = 0;
    /* Insert your solution below */
    while (1) {
      bits = 0x00;
      tmpA = PINA;
      tmpB = PINB;
      iter = 0;
      //loop through 8 times and see which bits are active and add
      while(iter < 9) {
	  //Check tmpA
	  if((tmpA & 0x01) == 0x01) bits++;
	  if((tmpB & 0x01) == 0x01) bits++;
          
          //Bit shift both 
          tmpA = tmpA >> 1;
          tmpB = tmpB >> 1;
	  iter++;
	}

     PORTC = bits;

    }
    return 1;
}
