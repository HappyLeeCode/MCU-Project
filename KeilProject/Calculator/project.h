#include <REGX52.H>
#include <INTRINS.H>

typedef unsigned char u8;
typedef unsigned int u16;


#define DIGITAL_PORT P0
#define KEY_MATRIX_PORT	P1
#define LED_PORT P2


//定义独立键盘
sbit KEY1 = P3^1;
sbit KEY2 = P3^0;
sbit KEY3 = P3^2;
sbit KEY4 = P3^3;

//74HC138译码器控制管脚，位选
sbit LSA = P2^2;
sbit LSB = P2^3;
sbit LSC = P2^4;

//74HC595(串转并模块)
sbit RCK = P3^5;
sbit SCK = P3^6;
sbit SER = P3^4;

//蜂鸣器
sbit BEEP = P2^5;

u8 Matrix_Key_scan();
void DigitalTube(u8 Location,u8 number);
void LEDflow(u16 number,u16 time);

void _74HC595_WriteByte(u8 Byte);
void LedDotMatrix_show(u8 Column,u8 Data);

void Delay(u16 xms);
void delay_10us(u16 time);
void DisplayL_R(u8 A[]);
void DisplayR_L(u8 A[]);
void DisplayLedMatrix(u8 A[]);
void DisplayOperate();

void beep(u16 time);
void Tips(int option,int number);
void Calculate();





	


