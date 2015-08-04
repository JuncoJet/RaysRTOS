/***************************************************************************************** 
 *  main.c 
 * 
 *  Copyright (C) 2010  Է��â 
 * 
 *  2010-07-09  RaysRTOS1.0-Mega8 �汾
 *****************************************************************************************/

/******************����ϵͳͷ�ļ�***************/
#include "RaysRTOS.h"

/******************��������Ķ�ջ***************/
INT8U Task0Stack[50];
INT8U Task1Stack[50];
INT8U Task2Stack[50];

//�û���������
void delays(unsigned char xx)
{
 while(xx--);

}
void delaysss(void)
{
 unsigned char i=0;
 i=10;
   delays(i);

}
/******************����Task0����***************/
void Task0(void)
{
	 unsigned char i=0;
 while(1)
 {
   PORTD=i++;
   RAYS_TimeDelay(3);
 }
}
/******************����Task1����***************/
void Task1(void)
{
 while(1)
 {
   PORTB^=0x01;
   RAYS_TimeDelay(4);

 }
}
/******************����Task2����***************/
void Task2(void)
{
INT8U ss=0;
 while(1)
 {
	 PORTC^=0x01;
	 for(ss=0;ss<10;ss++)
		 RAYS_TimeDelay(4);
	 delaysss();
 }

}

/******************ϵͳ���ĳ�ʼ��***************/
	 void TimerInit(void)
{
	TCNT0=0;
	TCCR0=_BV(CS02)|_BV(CS00);
}

/****************������***************/
int main(void)
{
	 RAYS_Init();
	 cli();
	 DDRB=0X01;
	 DDRD=0xff;
	 DDRC=0X01;
	 RAYS_TaskCreate(Task0,&Task0Stack[49],0);
	 RAYS_TaskCreate(Task1,&Task1Stack[49],1);
	 RAYS_TaskCreate(Task2,&Task2Stack[49],2);
	 TimerInit();
	 RAYS_Start();	 //�˺���ִ����ϵͳ����������
	 while(1);
}
