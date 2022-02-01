

#include "Led.h"
#include "Board.h"
// default constructor
Led::Led()
{
	sbi(DDRD, R_LED);
	sbi(DDRD, G_LED);
	sbi(DDRD, B_LED);
	
	
	PORTD |= (1<<B_LED);
	PORTD |= (1<<G_LED);
	PORTD |= (1<<R_LED);
	
	TCCR0A = 0;
	TCCR0B = 0;

	// set timer mode Fast PWM - red, blue
	sbi(TCCR0A,WGM00);			//fast PWM for TC0
	sbi(TCCR0A,WGM01);			//fast PWM for TC0
	sbi(TCCR0B,CS02);			//clkio/256 = 183Hz ... frekvencia signalu
	
	// set timer mode Fast PWM - green
	sbi(TCCR2A,WGM20);			//fast PWM for TC2
	sbi(TCCR2A,WGM21);			//fast PWM for TC2
	sbi(TCCR2B,CS21);			//clkio/256 = 183Hz ... frekvencia signalu
	sbi(TCCR2B,CS22);			//clkio/256 = 183Hz ... frekvencia signalu
	
	
} //Led

// default destructor
Led::~Led()
{
} //~Led

void Led::set(bool r, bool g, bool b)
{
	if (r) cbi(PORTD, R_LED); else sbi(PORTD,R_LED);
	if (g) cbi(PORTD, G_LED); else sbi(PORTD,G_LED);
	if (b) cbi(PORTD, B_LED); else sbi(PORTD,B_LED);		
}

void Led::set(Color c)
{
	switch (c)
	{
		case red: set(true,false,false);
		break;
		case green: set(false,true,false);
		break;
		case blue: set(false,false,true);
		break;
		case purple: set(true,false,true);
		break;
		case white: set(true,true,true);
		break;
		case black: set(false,false,false);
		break;
		case pink: setIntensity(250,30,230);
		break;
		default:
		set(false,false,false);
		break;
	}
}


void Led::delayMs(int ms)
{
	for(int i=1; i<ms; i++)
		_delay_ms(1);
}

void Led::delayUs(int us)
{
	for(int i=1; i<us; i++)
	_delay_us(1);
}

void Led::swPwm(Color c, uint8_t intensity)
{
	if (intensity >= 100)
	{
		set(c);
		return;
	}
	if (intensity == 0)
	{
		set(0,0,0);
		return;
	}
	
	set(c);
	delayUs(intensity);
	set(0,0,0);
	delayUs(100 -intensity);
	
}

void Led::setIntensity(uint8_t r, uint8_t g, uint8_t b)
{
	if (r == 0)
	{
		cbi(TCCR0A,COM0A0);
		cbi(TCCR0A,COM0A1);			//aby somnastavil natcdo hodnotu..treba tieto bity dat na 0
		sbi(PORTD,R_LED);			//zhasnem redLed
	}
	else
	{
		sbi(TCCR0A,COM0A0);
		sbi(TCCR0A,COM0A1);		// invertovany rezim
		OCR0A = r;				// do registra dam hodnotu pre intenzitu
	}
	
	if (g == 0)
	{
		cbi(TCCR2A,COM2B0);
		cbi(TCCR2A,COM2B1);			//aby somnastavil natcdo hodnotu..treba tieto bity dat na 0
		sbi(PORTD,G_LED);			//zhasnem blueLed
	}
	else
	{
		sbi(TCCR2A,COM2B0);
		sbi(TCCR2A,COM2B1);		// invertovany rezim
		OCR2B = g;				// do registra dam hodnotu pre intenzitu
	}
	
	if (b == 0)
	{
		cbi(TCCR0A,COM0B0);
		cbi(TCCR0A,COM0B1);			//aby somnastavil natcdo hodnotu..treba tieto bity dat na 0
		sbi(PORTD,B_LED);			//zhasnem blueLed
	}
	else
	{
		sbi(TCCR0A,COM0B0);
		sbi(TCCR0A,COM0B1);		// invertovany rezim
		OCR0B = b;				// do registra dam hodnotu pre intenzitu
	}
	
	
	
}
void Led::setFrequency(Color color, int frequency, uint8_t seconds)
{
	if (frequency <= 0)
	{
		frequency = 1;
	}
	int miliseconds = seconds * 1000;	
	int period = 1000/frequency;
	
	if (miliseconds < 2*period)
	{
		miliseconds = 2*period;
	}
	int counter = miliseconds/(2*period);
	for (int i = 0; i < counter; i++)
	{		
		set(color);
		delayMs(period);
		set(0,0,0);
		delayMs(period);
	}
}


Color Led::findColor(char color)
{
	Color returnColor;
	switch (color)
	{
		case 'g':
		returnColor = green;
		break;
		case 'b':
		returnColor = blue;
		break;
		case 'r':
		returnColor = red;
		break;
		case 'p':
		returnColor = purple;
		break;
		default:
		returnColor = white;
		break;
	}
	return returnColor;
}