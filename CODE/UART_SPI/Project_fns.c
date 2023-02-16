#include <LPC21xx.H>
#include"lcdheader.h"
#include"libheader.h"
#include"prototype.h"


char SPI_Master_Input()
{
		IOCLR0 = (1<<7);
		while(!(S0SPSR & (1 << 7)));
		IOSET0 =(1<<7);
		return S0SPDR;
}
char SPI_Slave_Input()
{
		IOCLR0 = (1 << 7);
		while(!(S0SPSR & (1 << 7)));
		IOSET0 =(1 << 7);
		return S0SPDR;
}
char SPI_Slave_Input2()
{
		IOCLR0 = (1<<25);
		while(!(S0SPSR & (1 << 7)));
		IOSET0 =(1<<25);
		return S0SPDR;
}

char SPI_Master_IO(char data)
{
		IOCLR0 = (1<<7);
		S0SPDR = data;
		while(!( S0SPSR & (1 << 7)));
		data=S0SPDR;
		IOSET0 =(1<<7);		
		return data;
}	

char SPI_Master_IO2(char data)
{
		IOCLR0 = (1<<25);
		S0SPDR = data;
		while(!( S0SPSR & (1 << 7)));
		data=S0SPDR;
		IOSET0 =(1<<25);		
		return data;
}
int SPI_Master_IO3(int data)
{
		IOCLR0 = (1<<25);
		S0SPDR = data;
		while(!( S0SPSR & (1 << 7)));
		data=S0SPDR;
		IOSET0 =(1<<25);		
		return data;
}
			   
int SPI_Master_IO1(int data)
{
		IOCLR0 = (1<<7);
		S0SPDR = data;
		while(!( S0SPSR & (1 << 7)));
		data=S0SPDR;
		IOSET0 =(1<<7);		
		return data;
}




void SPI_Slave_Output(char data)
{
		IOCLR0 = (1<<7);
		S0SPDR=data;
		while(!(S0SPSR & (1 << 7)));
		IOSET0 = ~(1<<7);
}
		
void Uart_Init_Receive(void)
{
	PINSEL0 |= ( 1 << 2);
	PINSEL0 &= ~(1 << 3);
	U0LCR=(1 << 7);
	U0DLL=97;
	U0LCR = (1 << 1) | (1 << 0);
}

char Receive_Uart()
{
	while(!(U0LSR & (1 << 0)));
	return (U0RBR);
}


void SPI_Master_Init()
{
	PINSEL0 |= (1 << 8)|(1 << 12)|(1<<10);    // select miso mosi sck ssel
	PINSEL0 &= ~((1<<9)|(1 << 13)|(1<<11));
	S0SPCR = (1 << 2)|(1 << 5)|(1<<6)|(1<<11);
	S0SPCCR = 8;
}
void Adc_Init()
{
	PINSEL1 |=(1 << 24)	;
	PINSEL1 &= ~(1 << 25)	;
	ADCR = (1 << 1)|(3 << 8)|(1 << 21)|(1 << 16)|(2 << 17);

}
char SPI_Slave_Input1()
{

		IOCLR0 = (1<<25);
		while(!(S0SPSR & (1 << 7)));
		IOSET0 =(1 << 25);
		return S0SPDR;

}
char SPI_Slave_Input3()
{

		IOCLR0 = (1<<7);
		while(!(S0SPSR & (1 << 7)));
		IOSET0 =(1<<7);
		return S0SPDR;

}
