

#include "DSTSensor.h"

// default constructor
DSTSensor::DSTSensor()
{
	sbi(DDRC, TRIG);
	cbi(DDRC, ECHO);
} //DSTSensor

// default destructor
DSTSensor::~DSTSensor()
{
} //~DSTSensor

int DSTSensor::getDistance()		//returns distance in cm
{
	_delay_us(10);
	sbi(PORTC, TRIG);
	_delay_us(10);
	cbi(PORTC, TRIG);
	
	uint8_t timeInMicroseconds = 0;	
	int centiMeters = 0;			//1cm == 58 us , 1dm == 580us
	//uint8_t decimeters = 0;
	while((PINC &(1<<ECHO))== 0)
		{
			_delay_us(1);
			timeInMicroseconds++;
			if (timeInMicroseconds > 20000)
			{
				break;
			}
		}
		
	while((PINC &(1<<ECHO))!= 0)
	{
		_delay_us(58);
		centiMeters++;
		
	}
	
	return centiMeters;
}


void DSTSensor::printDistance()
{
	Usart us;
	printf("Distance is : %d cm \r\n", getDistance());
}