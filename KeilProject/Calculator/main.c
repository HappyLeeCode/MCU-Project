#include "project.h"

u8 FLAG=0;
u8 SLOT=0;
u8 Box[8]={0};
u16 Result=0,Temp=0;
u8 KeyValue=0;
u8 StudentID[8]={5,1,1,1,6,3,9,2};

extern u8 ERROR[8];
extern u8 HELLO[8];


void main()
{
	RCK = 0;
	SCK = 0;
	_74HC595_WriteByte(0x00);
	Tips(0,3);
	while(1)
	{		
		DisplayL_R(StudentID);
		while(KEY1==0)
		{
			Delay(10);
			while(KEY1==0);
			Delay(10);
		  LEDflow(1,300);
			Calculate();
			if(KEY2==0)
			{
			Tips(1,3);
			}
		}
	}
}
