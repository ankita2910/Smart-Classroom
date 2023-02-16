#include <LPC21xx.H>
#include"lcdheader.h"
#include"libheader.h"
void LcdInit()
{
	IODIR0 |= RS | RW | EN | DATAPINS;
	LcdCmd(0x38);
	LcdCmd(0x0E);
	LcdCmd(0x01);
	LcdCmd(0x80);

}
void LcdCmd(int cmd)
{
	IOCLR0 = RS |RW;
	IOCLR0 = DATAPINS;
	IOSET0 = (cmd << 15);
	IOSET0 = EN;
	delay(30);
	IOCLR0 = EN;
}

void LcdData(char ch)
{
	IOSET0 = RS;
	IOCLR0 = RW;
	IOCLR0 = DATAPINS;
	IOSET0 = (ch << 15);
	IOSET0 = EN;
	delay(30);
	IOCLR0 = EN;
}

void LcdString(char *str)
{
	while(*str)
	{
		LcdData(*str);
		str++;
	}															   	
}

void LcdString2(char *str)
{
	int c=1;
	while(*str)
	{
		
		LcdData(*str);
		str++;
		c++;
		if(c == 32)
		{
			delay(30);
			LcdCmd(0x01);//clear lcd
			LcdCmd(0x80);
			c = 1;
		}
	}
}


void LcdString1(char *str)
{
	int c=1;
	while(*str)
	{
		
		LcdData(*str);
		str++;
		c++;
		if(c == 16)
		{
			LcdCmd(0xc0);
		}
	
	}
}

void LcdNum(int a)
{
	
	 if(a)
	{
		LcdNum(a / 10);
		LcdData((a % 10) + 48);//(a%10)+0x30
	}
}
