#include "project.h"

void beep(u16 time)
{
	u16 i=20;
	while(i--)
	{
		BEEP=1;
		delay_10us(0.5*time);// —” ±
		BEEP=0;
		delay_10us(0.5*time);// —” ±
	}  
	BEEP=0;
}