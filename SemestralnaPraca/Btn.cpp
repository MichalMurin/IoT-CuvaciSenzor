


#include "Btn.h"
#include "Eeprom.h"
Btn* Btn::button_ptr;

// default constructor
Btn::Btn()
{
	cbi(DDRD,BTN);		// set as input
	sbi(PORTD,BTN);		// set pull-up
	button_ptr = this; 
	is_pressed = false;
} //Button

// default destructor
Btn::~Btn()
{
	EIMSK &=~(1<<INT0);		// turn off interrupt
} //~Button

bool Btn::isPressed(void)
{
/*	while((PIND & (1<<BTN))!=0){};			// wait, BTN=1
	_delay_ms(10);							// delay
	while((PIND & (1<<BTN))==0){};			// wait for release button	 
	return true;							// if BTN = 0  . . . pressed
*/
	if((PIND & (1<<BTN))==0) return true;	// pressed
	else return false;						// released
}

void Btn::initInterrupt(externInt edge)
{
	EICRA |= edge;			// bits ISC00, ISC01
	sbi(EIMSK,INT0);		// enable extern interrupt 0
}

void Btn::interruptHandler(void)
{
	tbi(PORTD,G_LED);
	is_pressed = true;
	Eeprom eeprom;
	uint8_t position = eeprom.Read(ADD_POSITION);
	char color = eeprom.Read(position);
	eeprom.Write(0,color);
	if (position == 6)
	{
		position = 1;
	}
	position++;
	eeprom.Write(ADD_POSITION,position);
	printf("Tlacitkom sa zmenila farba\r\n");
}


bool Btn::getPressed(void)
{
	return is_pressed;
}

void Btn::setPressed(bool pressed)
{
	is_pressed = pressed;
}

ISR(INT0_vect)
{
	Btn::button_ptr->interruptHandler();
}