
#ifndef __BUTTON_H__
#define __BUTTON_H__

#include "Board.h"

class Btn
{
	//variables
	public:
	static Btn* button_ptr;
	protected:
	private:
	volatile bool is_pressed;
	//functions
	public:
	Btn();
	~Btn();
	bool isPressed(void);
	void interruptHandler(void);
	void initInterrupt(externInt edge);
	uint8_t getCounter();
	bool getPressed(void);
	void setPressed(bool pressed);
	protected:
	private:


}; //Button

#endif //__BUTTON_H__
