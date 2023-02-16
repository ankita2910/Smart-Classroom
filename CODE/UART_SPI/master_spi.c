#include<LPC21xx.H>

#include"lcdheader.h"
#include"libheader.h"
#include"prototype.h"


char var;
int result;


int main()
{
	unsigned int done = 1;
	IODIR0 |= (1 << 7)|(1<<25);
	LcdInit();
	Uart_Init_Receive();
	SPI_Master_Init();
	Adc_Init();	

	LcdString("MASTER : ");
	while(1)
	{	
		var = Receive_Uart();
		LcdCmd(0xc0);
		LcdData(var);
		SPI_Master_IO(var);
		while(!(ADDR & (done << 31))) ;
		result = (ADDR & (0x3ff <<  6));
		result >>=6;
		SPI_Master_IO1(result);

		delay(100);
		SPI_Master_IO2(var);
		SPI_Master_IO3(result);
		
	}				  


}
