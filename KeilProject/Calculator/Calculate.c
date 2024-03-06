#include "project.h"

extern u8 FLAG;
extern u8 SLOT;
extern u8 Box[8];
extern u16 Result,Temp;
extern u8 KeyValue;

extern u8 ERROR[8];

u16 ArryValue(const u8 Box[])
{
	u16 i=0,j=0;
	u16 sum=0;
	for(i=0;i<8;i++)
	{
		u16 weight=1;
		for(j=0;j<i;j++)
		{
			weight*=10;
		}		
		sum+=Box[i]*weight;
	}
	return sum;
}

void ArryCreate(const u16 Result,u8 Box[])
{
	u16 i=0,j=0;
	for(i=0;i<8;i++)
	{
		u16 weight=1;
		for(j=0;j<i;j++)
		{
			weight*=10;
		}		
		Box[i]=Result/weight%10;
	}	
		//Box[0]=Result%10;                 
		//Box[1]=Result/10%10;
		//Box[2]=Result/100%10;
		//Box[3]=Result/1000%10;
		//Box[4]=Result/10000%10;
		//Box[5]=Result/100000%10;
		//Box[6]=Result/1000000%10;
		//Box[7]=Result/10000000%10;	
}

void ArryClear(u8 Box[])
{
	u16 i=0;
	for(i=0;i<8;i++)
		 Box[i]=0;  
}



void CheckInput()
{
	while(SLOT==4&&Temp==0)
	{
    DisplayL_R(ERROR);
		KeyValue=Matrix_Key_scan();
		if(KeyValue==16)
				break;
	}
}

void CheckOutput()
{
	while(Result<Temp)
	{
    DisplayL_R(ERROR);
		KeyValue=Matrix_Key_scan();
		if(KeyValue==16)
		{			Result=0;
					Temp=0;
					FLAG=0;
					SLOT=0;
				break;
		}
	}
}



//void CheckResult()
//{
//	
//	
//}
void Operate(u8 SLOT)
{
	switch(SLOT)
	{
		case 0: Result=Temp; break;      
		case 1: Result=Result+Temp; break;
		case 2: CheckOutput();Result=Result-Temp; break;
		case 3: Result=Result*Temp; break;
		case 4: Result=Result/Temp; break;
	}
	Temp=0;
}

void Calculate()
{

	u8 i=0;
	while(1)
	{
		if(KEY2==0)
			break;
		
		DisplayR_L(Box);
		KeyValue=Matrix_Key_scan();

		if(KeyValue!=0)
		{
			beep(KeyValue);
			if(FLAG==1)  
			{
				for(i=7;i>0;i--)          
				{
					Box[i]=Box[i-1];
				}
				if(KeyValue==10)
					KeyValue=0;
				else;
				Box[0]=KeyValue; 
				
				Temp=ArryValue(Box);
				
				CheckInput();
				FLAG=0;
			}
			
			
			else
			{
				if(KeyValue==16)
				{
					ArryClear(Box);           
					DisplayR_L(Box);
					Result=0;
					Temp=0;
					FLAG=0;
					SLOT=0;
				}
								
				else if(KeyValue==15)
				{
					Operate(SLOT);
					ArryCreate(Result,Box);
					Temp=ArryValue(Box);
					DisplayR_L(Box);
					SLOT=0;
				}	
				
				else		//此时，KeyValue=11~14，依次对应为+、-、x、/操作
				{
					Operate(SLOT);
					ArryClear(Box);
					DisplayR_L(Box);
					SLOT=KeyValue%10;	
				}
				
				DisplayOperate();


//				else if(KeyValue==11)
//				{
//					Operate(SLOT);
//					ArryClear(Box);
//					DisplayR_L(Box);
//					SLOT=1;
//				}			
//				else if(KeyValue==12)
//				{
//					Operate(SLOT);
//					ArryClear(Box);
//					DisplayR_L(Box);
//					SLOT=2;
//				}			
//				else if(KeyValue==13)
//				{
//					Operate(SLOT);
//					ArryClear(Box);
//					DisplayR_L(Box);
//					SLOT=3;
//				}				
//				else if(KeyValue==14)
//				{
//					Operate(SLOT);
//					ArryClear(Box);
//					DisplayR_L(Box);
//					SLOT=4;
//				}
			}
		}	
	}
}