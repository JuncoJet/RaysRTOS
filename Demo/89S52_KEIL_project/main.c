
#include "RaySRTOS.h"
#include "math.h"

/******************��������Ķ�ջ***************/
INT8U Task0Stack[20];
INT8U Task1Stack[20];
INT8U Task2Stack[20];
/******************ϵͳ���ĳ�ʼ��***************/
	 void TimerInit(void)
{
	TMOD=0x01;
    TH0=0xf9;
    TL0=0xfe;
    EA=1;
    ET0=1;
}
/******************����Task0����***************/
void Task0(void)
{
 INT8U asi=0;
 TimerInit();
 
 while(1)
 {
   P0++;
   RAYS_TimeDelay(3000);
 }
}
/******************����Task1����***************/
void Task1(void)
{

 while(1)
 {
   P1++;
   RAYS_TimeDelay(40);

 }
}

/******************����Task2����***************/
void Task2(void)
{

 while(1)
 {
   P2++;
   RAYS_TimeDelay(40);

 }
}

/****************������***************/
int main(void)
{
	 RAYS_Init();
	 RAYS_TaskCreate(Task0,Task0Stack,0);
	 RAYS_TaskCreate(Task1,Task1Stack,1);
	 RAYS_TaskCreate(Task2,Task2Stack,2);	 
	 RAYS_Start();	 //�˺���ִ����ϵͳ����������
	 while(1);
}