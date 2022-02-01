


#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include "Board.h"

class Display
{
//variables
public:
protected:
private:

//functions
public:
	Display();
	~Display();
	void Show(uint8_t num);
	void delayMs(int ms);
protected:
private:
	void Dsp(uint8_t num);
	Display( const Display &c );
	Display& operator=( const Display &c );

}; //Display

#endif //__DISPLAY_H__
