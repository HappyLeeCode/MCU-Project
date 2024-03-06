#include "project.h"





void _74HC595_WriteByte(u8 Byte)
{
	u8 i=0;
	for(i=0;i<8;i++)
	{
		SER=Byte&(0x80>>i);		//��Byte�Ӹ�λ����λ�������͵�SER
		SCK=1;                //SCKÿ��һ��ʱ�������أ���һ��λ
		SCK=0;
	}
	RCK=1;									//RCKÿ��һ��ʱ�������أ���SER�е����ݲ������
	RCK=0;
}


void LedDotMatrix_show(u8 Column,u8 Data)
{
	_74HC595_WriteByte(Data);    //����д��Data
	P0=~(0x80>>Column);          //ѡ�е�Column��
	Delay(1);                    //��ʱ
	_74HC595_WriteByte(0x00);                     //��Ӱ
}

