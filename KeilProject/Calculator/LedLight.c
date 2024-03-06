#include "project.h"


void LEDflow(u16 number,u16 time)
{
	while(number)
	{
		int i=0;
		for(i=0;i<8;i++)
		{
			LED_PORT=~(0x01<<i);
			Delay(time);
		}
		number--;
	}
}