#include "project.h"

extern u8 FLAG;
extern u8 SLOT;
int i=0;

void Delay(u16 xms)		//@11.0592MHz
{
	u8 i, j;
	while(xms)
	{
		xms--;
		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
	}
}

void delay_10us(u16 time)
{
	while(time--);
}


void DisplayL_R(u8 A[])
{
	u8 i = 0;
	for(i=1;i<=8;i++)
	DigitalTube(i,A[i-1]);
}

void DisplayR_L(u8 A[])
{
	u8 i = 0;
	for(i=1;i<=8;i++)
	DigitalTube(i,A[8-i]);
}

void DisplayLedMatrix(u8 A[])
{
	u8 i = 0;
	for(i=0;i<8;i++)
	LedDotMatrix_show(i,A[i]);
}

void DisplayOperate()
{
	u8 ADD[8]={0x18,0x18,0x18,0xFF,0xFF,0x18,0x18,0x18};
	u8 SUB[8]={0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18};
	u8 MUL[8]={0x00,0x41,0x22,0x14,0x08,0x14,0x22,0x41};
	u8 DIV[8]={0x18,0x18,0x18,0xDB,0xDB,0x18,0x18,0x18};
	
	u16 time=20;

	switch(SLOT)
	{
		case 0: _74HC595_WriteByte(0x00);break;
		case 1: while(time--){DisplayLedMatrix(ADD);} break;
		case 2: while(time--){DisplayLedMatrix(SUB);} break;
		case 3: while(time--){DisplayLedMatrix(MUL);} break;
		case 4: while(time--){DisplayLedMatrix(DIV);} break;
		default: _74HC595_WriteByte(0x00);break;
	}
	
	_74HC595_WriteByte(0x00);
	
}
	
void Tips(int option,int number)
{							
	for(i=0;i<number;i++)
	{
		int time =80;
		while(time--)
		{
			switch(option)
			{
				case 0: DigitalTube(3,16);
								DigitalTube(4,14);
								DigitalTube(5,18);
								DigitalTube(6,18);
								DigitalTube(7,0);
								break;
				case 1: DigitalTube(2,23);
								DigitalTube(3,17);
								DigitalTube(4,14);
								DigitalTube(6,23);
								DigitalTube(7,17);
								DigitalTube(8,14);
								break;
			}
		}
		Delay(500);
	}
}
	







