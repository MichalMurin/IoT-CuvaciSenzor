

#include "Eeprom.h"

// default constructor
Eeprom::Eeprom()
{
} //Eeprom

// default destructor
Eeprom::~Eeprom()
{
} //~Eeprom

void Eeprom::Write(uint16_t Addr, uint8_t data)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEPE));
	/* Set up address and Data Registers */
	EEAR = Addr;
	EEDR = data;
	/* Write logical one to EEMPE */
	EECR |= (1<<EEMPE);
	/* Start eeprom write by setting EEPE */
	EECR |= (1<<EEPE);
}
void Eeprom::setColors()		//save color names in Eeprom
{
	Write(ADD_POSITION,2);
	char color = 'r';
	Write(2,color);
	color = 'g';
	Write(3,color);
	color = 'b';
	Write(4,color);
	color = 'p';
	Write(5,color);
	color = 'w';
	Write(6,color);
}
uint8_t Eeprom::Read(uint16_t Addr)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEPE))
	;
	/* Set up address register */
	EEAR = Addr;
	/* Start eeprom read by writing EERE */
	EECR |= (1<<EERE);
	/* Return data from Data Register */
	return EEDR;
}
