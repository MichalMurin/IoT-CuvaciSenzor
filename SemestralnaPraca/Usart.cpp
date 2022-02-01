

#include "Usart.h"
#include "Eeprom.h"
// default constructor
Usart::Usart()
{
	Eeprom eeprom;
	eeprom.Write(1, 0);
	DDRD |= (1<<HTX);					// Tx as output (not necessary, when TXEN is set, also TX is set as output)
	UBRR0H = (uint8_t)(UBRR_VALUE>>8);	// BAUDERATE
	UBRR0L = (uint8_t)UBRR_VALUE;
	UCSR0C |= (1<<UCSZ01)|(1<<UCSZ00);  // 8 bits, no parity, 1 stop
	UCSR0B |= (1<<RXEN0)|(1<<TXEN0);	// enable rx and tx

	//UCSR0A |= (1<<U2X0);				// double speed mode	
	
	uart_ptr = fdevopen(hwSendByte, hwReceiveByte);		//send , receive methods - HW UART
	stdout = stdin = uart_ptr;
	
	sbi(UCSR0B, RXCIE0);	//
	sbi(UCSR0A, RXC0 );
	
} //Uart

// default destructor
Usart::~Usart()
{
} //~Usart

/************************************************************ HW UART ************************************************************/
int Usart::hwSendByte(char data, FILE *stream)
{
	while(!(UCSR0A & (1<<UDRE0))){};
	UDR0 = data;
	return 0;
}



int Usart::hwReceiveByte(FILE *stream)
{
	uint8_t data;
	while(!(UCSR0A & (1<<RXC0))){};
	data = UDR0;
	return data;
}
/*********************************************************************************************************************************/

ISR(USART_RX_vect)
{
	cli();
	Eeprom eeprom;
	char pismeno;
	pismeno = UDR0;
	eeprom.Write(0, pismeno);
	printf("Farba sa zmenila\r\n");		//vypiseme znak ktory sa precital
	sei();
	//pismeno = UDR0;						//neviem preco ale bluetooth cita znak 3x ???
	//pismeno = UDR0;
	
}