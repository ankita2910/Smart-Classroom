#include <LPC21xx.H>
#include"lcdheader.h"
#include"libheader.h"

char var1;
int result2;

void SPI_Slave_Init()
{
	PINSEL0 |= (1 << 8) | (1 << 10) | (1 << 12) | (1 << 14);    // select miso mosi sck ssel
	PINSEL0 &= ~((1 << 9) | (1 << 13) | (1 << 11)) | (1 << 15);
	S0SPCR = (1 << 2)|(1 << 6)|(1 << 11);
	S0SPCR &= ~(1 << 5);
	S0SPCCR = 8;
}

int main()
{
	LcdInit();
	IODIR0 |= 1<<7;
	SPI_Slave_Init();
	LcdString("SLAVE : ");

while(1)
	{
		
		var1=SPI_Slave_Input();
		LcdCmd(0x8A);
		LcdData(var1);	
		result2=SPI_Slave_Input3();
		LcdCmd(0xc0);
		LcdNum(result2/3.3);	

	}
}

