#include "project.h"

u8 ERROR[8]={22,14,20,20,0,20,22,22};
u8 HELLO[8]={22,22,16,14,19,19,0,22};


void DigitalTube(u8 Location,u8 number)
{
	
	//数码管显示字符
	u8 CharTable[]=
	{
			0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,    //0-9
			0x77,0x7C,0x39,0x5E,0x79,0x71,                        //A(10)  B(11)  C(12)  D(13)  E(14)  F(15) 
			0x76,0x6E,0x38,0x3E,0x72,0x70,												//H(16)  Y      L      U      R      -(负号) 
			0x00,0x7C,0x7B                                                  //空(22)
	};

	//位选：选择几号数码管
	switch(Location)
	{
		case 1: LSC=1; LSB=1; LSA=1; break;
		case 2: LSC=1; LSB=1; LSA=0; break;
		case 3: LSC=1; LSB=0; LSA=1; break;
		case 4: LSC=1; LSB=0; LSA=0; break;
		case 5: LSC=0; LSB=1; LSA=1; break;
		case 6: LSC=0; LSB=1; LSA=0; break;
		case 7: LSC=0; LSB=0; LSA=1; break;
		case 8: LSC=0; LSB=0; LSA=0; break;
	}
	
	//段选：送字符显示
	DIGITAL_PORT = CharTable[number];   
	
	Delay(1);                           //稳定显示字符
	DIGITAL_PORT = 0x00;                //消影
	
}