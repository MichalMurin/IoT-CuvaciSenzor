

#ifndef BOARD_H_
#define BOARD_H_

#ifndef F_CPU
	#define F_CPU 12000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>

#define sbi(x,y) x |= _BV(y)
#define cbi(x,y) x &= ~(_BV(y))
#define tbi(x,y) x ^= _BV(y)

#define ADD_COLOR 0			//adresa na ukladanie zobrazovanej farby
#define ADD_POSITION 1		//adresa na ukladanie pozicie v pamate
#define MAX_DIST_CM 250		//maximalna vzdialenost merana na senzore v cm

#define R_LED PORTD6
#define G_LED PORTD3
#define B_LED PORTD5
#define BTN PORTD2
#define SER PORTC5
#define OE PORTC4
#define RCLK PORTD7
#define SRCLK PORTB1

#define TRIG PORTC2
#define ECHO PORTC3

#define HRX PORTD0
#define HTX PORTD1

#define BAUDERATE 9600 // 115200
#define UBRR_VALUE ((F_CPU / (BAUDERATE * 16L)) -1)  //   8....51  ,  16.....25  12.....12

#define ZERO	0b00111111
#define ONE		0b00000110
#define TWO		0b01011011
#define THREE	0b01001111
#define FOUR	0b01100110
#define FIVE	0b01101101
#define SIX		0b11111101
#define SEVEN	0b00000111
#define EIGHT	0b01111111
#define NINE	0b11101111
#define NONE	0b00000000
#define AHEX	0b01110111
#define BHEX	0b01111100
#define CHEX	0b01011000
#define DHEX	0b01011110
#define EHEX	0b01111001
#define FHEX	0b01110001
#define DOT		0b10000000
#define ERR		0b01001001


enum Color{red,green,blue,purple,white,black,pink};
	
enum externInt{		// EICRA
		low,			// 00
		change,			// 01
		fall,			// 10
		rising			// 11
	};

#endif /* BOARD_H_ */