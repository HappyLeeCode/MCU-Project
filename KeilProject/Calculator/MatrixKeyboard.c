#include "project.h"

extern u8 FLAG;

u8 Matrix_Key_scan()
{
  u8 key_value=0;
	
  {
	P1=0xf7;          //扫描第一列
	if(P1!=0xf7)      //第一列有按键被按下
	{
		Delay(10);
		switch(P1)
		{
			case 0x77:key_value=1;break;
			case 0xb7:key_value=5;break;
			case 0xd7:key_value=9;break;
			case 0xe7:key_value=13;break;
		}	
	}
	while(P1!=0xf7);  //等待按键松开

	P1=0xfb;			    //扫描第二列
	if(P1!=0xfb)      //第二列有按键被按下
	{
		Delay(10);
		switch(P1)
		{
			case 0x7b:key_value=2;break;
			case 0xbb:key_value=6;break;
			case 0xdb:key_value=10;break;      
			case 0xeb:key_value=14;break;
		}	
	}
	while(P1!=0xfb);  //等待按键松开

	P1=0xfd;			    //扫描第三列
	if(P1!=0xfd)      //第三列有按键被按下
	{
		Delay(10);
		switch(P1)
		{
			case 0x7d:key_value=3;break;
			case 0xbd:key_value=7;break;
			case 0xdd:key_value=11;break;
			case 0xed:key_value=15;break;
		}	
	}
	while(P1!=0xfd);  //等待按键松开

	P1=0xfe;          //扫描第四列
	if(P1!=0xfe)	    //第四列有按键被按下
	{
		Delay(10);
		switch(P1)
		{
			case 0x7e:key_value=4;break;
			case 0xbe:key_value=8;break;
			case 0xde:key_value=12;break;
			case 0xee:key_value=16;break;
		}	
	}
	while(P1!=0xfe);  //等待按键松开
  }
  
  
  if(key_value>=1&&key_value<=10)  
	  FLAG=1;
  
  return key_value;  //返回键入的键盘值
}