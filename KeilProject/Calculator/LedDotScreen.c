#include "project.h"





void _74HC595_WriteByte(u8 Byte)
{
	u8 i=0;
	for(i=0;i<8;i++)
	{
		SER=Byte&(0x80>>i);		//把Byte从高位到低位，依次送到SER
		SCK=1;                //SCK每来一个时钟上升沿，移一个位
		SCK=0;
	}
	RCK=1;									//RCK每来一个时钟上升沿，将SER中的数据并行输出
	RCK=0;
}


void LedDotMatrix_show(u8 Column,u8 Data)
{
	_74HC595_WriteByte(Data);    //整行写入Data
	P0=~(0x80>>Column);          //选中第Column列
	Delay(1);                    //延时
	_74HC595_WriteByte(0x00);                     //消影
}

