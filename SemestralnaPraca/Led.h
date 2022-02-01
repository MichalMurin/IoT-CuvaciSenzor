
#ifndef __LED_H__
#define __LED_H__

#include "Board.h"

class Led
{
	//variables
	public:
	protected:
	private:

	//functions
	public:
	Led();
	~Led();
	void set(bool r, bool g, bool b);
	void set(Color c);
	void delayMs(int ms);
	void delayUs(int ms);
	void swPwm(Color c, uint8_t intensity);
	void setIntensity(uint8_t r, uint8_t g, uint8_t b);
	void setFrequency(Color color, int frequency, uint8_t seconds);
	Color findColor(char color);
	protected:
	private:
	Led( const Led &c );
	Led& operator=( const Led &c );

}; //Led

#endif //__LED_H__
