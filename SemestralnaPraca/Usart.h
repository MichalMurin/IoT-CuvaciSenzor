

#ifndef __USART_H__
#define __USART_H__
#include "Board.h"
#include "Led.h"

class Usart
{
//variables
public:
protected:
private:
FILE *uart_ptr;

//functions
public:
	Usart();
	~Usart();
	// HW implementation
	static int hwSendByte(char data, FILE *stream);
	static int hwReceiveByte(FILE *stream);
	
protected:
private:

}; //Usart

#endif //__USART_H__
