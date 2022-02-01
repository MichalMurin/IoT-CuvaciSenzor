/*
 * Author : Michal
 */ 

#include "Led.h"
#include "Btn.h"
#include "Display.h"
#include "Usart.h"
#include "DSTSensor.h"
#include "Eeprom.h"

int main(void)
{
	Led rgb;					// create object of class Led	
	Display dsp;				// create object of class Display
	Usart uart;					// create object of class Uart
	Btn btn;					// create object of class Button
	DSTSensor dst;				// create object of class DSTSensor
	Eeprom eeprom;				// create object of class Eeprom
	
	printf("----------------START PROGRAMU---------------------\r\n");
	Color color;
	btn.initInterrupt(fall);
	eeprom.setColors();
	char colorEeeprom = 0;
	int freq = 1;
	int distance = 0;
	sei();						// global interrupt enable
	while(1){
		colorEeeprom = eeprom.Read(ADD_COLOR);
		color = rgb.findColor(colorEeeprom);
		distance = dst.getDistance();		
		freq = MAX_DIST_CM/distance;
		printf("Distance is %d cm, frequency of led is %d Hz\r\n", distance, freq);
		if (freq <= 15)
		{
			dsp.Show(freq);
		}else
		{
			dsp.Show(16);
		}
		
		rgb.setFrequency(color,freq,1);
		
	}
	printf("----------------KONIEC PROGRAMU---------------------/r/n");
	
	
}

