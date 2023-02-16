#include <LPC21xx.H>
#include"lcdheader.h"
#include"libheader.h"

char var2;
int result3;

void SPI_Slave_Init()
{
	PINSEL0 |= (1 << 8)|(1 << 10)|(1<<12)|(1 << 14);    // select miso mosi sck ssel
	PINSEL0 &= ~((1<<9)|(1 << 13)|(1<<11));
	S0SPCR = (1 << 2)|(0 << 5)|(1 << 6)|(1 << 11);
	S0SPCCR = 8;
}

int main()
{
	LcdInit();
	IODIR0 |= 1<<25;
	SPI_Slave_Init();
	LcdString("SLAVE 1 : ");

while(1)
	{
		
		var2=SPI_Slave_Input1();
		LcdCmd(0x8A);
		LcdData(var2);	
		result3=SPI_Slave_Input2();	
		LcdCmd(0xc0);
		LcdNum(result3/3.3);	

	}
}

