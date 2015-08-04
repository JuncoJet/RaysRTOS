/***************************************************************************************** 
 *  main.c 
 * 
 *  �û����ļ� 
 * 
 *  Copyright (C) 2010  Է��â 
 * 
 *  2010-07-09  RaysRTOS1.0-STM8 �汾
 *****************************************************************************************/

/******************����ϵͳͷ�ļ�***************/
#include "RaysRTOS.h"



/******************��������Ķ�ջ***************/
INT8U Task0Stack[50];
INT8U Task1Stack[50];
INT8U Task2Stack[50];

/******************����Task0����***************/
void Task0(void)
{
 while(1)
 {
   RAYS_TimeDelay(3);
 }
}

/******************����Task1����***************/
void Task1(void)
{
 while(1)
 {
  PD_ODR_bit.ODR6=0;
   RAYS_TimeDelay(3); 
  PD_ODR_bit.ODR6=1;
   RAYS_TimeDelay(3);   
 }
}

/******************����Task2����***************/
void Task2(void)
{
 while(1)
 {
   RAYS_TimeDelay(40);
 }

}

/******************ϵͳ���ĳ�ʼ��***************/
void TimerInit(void)
{
  TIM3_PSCR =0x08;    //256��Ƶ
  TIM3_ARRH =0x02;    //625��Ƶ_16M��Ƶ�õ�100Hz
  TIM3_ARRL =0x70;
  TIM3_CR1  =0x84;
  TIM3_IER  =0x01;     //�����ж�  
  CLK_CKDIVR=0x00;   //ʱ���޷�Ƶ
  CLK_PCKENR1 |= 0X40;//����ʱ��
}

/****************������***************/
int main(void)
{
         RAYS_Init();
	 RAYS_TaskCreate(Task0,&Task0Stack[49],0);
	 RAYS_TaskCreate(Task1,&Task1Stack[49],1);
	 RAYS_TaskCreate(Task2,&Task2Stack[49],2);
	 TimerInit();
         PD_ODR_bit.ODR0=1;
         PD_DDR_bit.DDR6=1;
	 RAYS_Start();	              //�˺���ִ����ϵͳ����������
	 while(1);
}
