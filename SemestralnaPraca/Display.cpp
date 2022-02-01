

#include "Display.h"

// default constructor
Display::Display()
{
	sbi(DDRC, SER);		//natavime ako vystupy
	sbi(DDRC,OE);
	sbi(DDRD, RCLK);
	sbi(DDRB,SRCLK);
} //Display

// default destructor
Display::~Display()
{
} //~Display


void Display::Show(uint8_t num)
{
		uint8_t result;
		switch (num)
		{
			case 0:
				result=ZERO;
				break;
			case 1:
				result=ONE;
				break;
			case 2:
				result=TWO;
				break;
			case 3:
				result=THREE;
				break;
			case 4:
				result=FOUR;
				break;
			case 5:
				result=FIVE;
				break;
			case 6:
				result=SIX;
				break;
			case 7:
				result=SEVEN;
				break;
			case 8:
				result=EIGHT;
				break;
			case 9:
				result=NINE;
				break;
			case 10:
				result=AHEX;
				break;
			case 11:
				result=BHEX;
				break;
			case 12:
				result=CHEX;
				break;
			case 13:
				result=DHEX;
				break;
			case 14:
				result=EHEX;
				break;
			case 15:
				result=FHEX;
				break;
			case 16:
				result=ERR;
				break;
			case 17:
				result=DOT;
				break;
			default:
				result = NONE;
				break;
		}
		this -> Dsp(result);
}

void Display::delayMs(int ms)
{
	for(int i=1; i<ms; i++)
	_delay_ms(1);
}

void Display::Dsp(uint8_t num)
{
	sbi(PORTC,OE);								//zapiseme log 1 aby sme vypli OE a neovlpyvnovali vystup
	for (int i=0 ; i<8 ; i++)
	{
		if ((num & 0b10000000) == 0b10000000)	//skontorlujem najvyssi bit
		{
			sbi(PORTC,SER);
		}
		else
		{
			cbi(PORTC,SER);
		}
		num = num << 1;
		sbi(PORTB, SRCLK);
		cbi(PORTB, SRCLK);
		
	}
	sbi(PORTD,RCLK);		//	transcript from shift register to memory
	cbi(PORTD,RCLK);		//  impulse
	cbi(PORTC,OE);			//	set output
}