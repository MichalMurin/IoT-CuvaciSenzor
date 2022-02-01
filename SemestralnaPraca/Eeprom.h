

#ifndef __EEPROM_H__
#define __EEPROM_H__
#include "Board.h"
class Eeprom
{
//variables
public:
protected:
private:

//functions
public:
	Eeprom();
	~Eeprom();
	static void Write(uint16_t Addr, uint8_t data);
	static uint8_t Read(uint16_t Addr);
	void setColors();
protected:
private:
	Eeprom( const Eeprom &c );
	Eeprom& operator=( const Eeprom &c );

}; //Eeprom

#endif //__EEPROM_H__
