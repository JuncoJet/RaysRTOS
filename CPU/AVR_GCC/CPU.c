/*****************************************************************************************  
 *  AVR CPU���C�ļ�
 * 
 *  Copyright (C) 2010  Է��â 
 * 
 *  2010-07-09  RaysRTOS 
 *****************************************************************************************/

#include "RaySRTOS.h"


/******************ȫ�ֱ�������***************/
  INT8U   StackIdle[StackSizeIdle]; 				// ������������ջ
  INT8U   OSRdyTbl;     							// ���������б�
  INT8U   OSPrioCur;		            			// ��ǰ��������ȼ�
  INT8U   OSPrioHighRdy	;           		    	// ����Ҫ������������ȼ�	
  INT8U  IdleCount;								// ���������Լ���
  struct  TaskCtrBlock TCB[OS_TASKS + 1];			// ����������ƿ�TCB����
  INT16U  *TEMP_SP;

/*
+---------------------------------------------------------------------------------------+
|�������ƣ�	SPPoint																		|
|---------------------------------------------------------------------------------------|
|����ԭ�ͣ�	void SPPoint(prio)															|
|																						|
|�������ܣ�	����C������SPָ������ 														|
+---------------------------------------------------------------------------------------+
*/	
 	void SPPoint(void)
	{
	  TEMP_SP=&(TCB[OSPrioCur].OSTCBStkPtr);	
	}

void  CPU_TaskCreate(void (*p_Task)(void),INT8U *p_Stack,INT8U t_Prio)
	{
	unsigned char i=0;
		*(p_Stack--) = 	(unsigned char)((unsigned int)p_Task&0x00ff);;	  		//�������	
		*(p_Stack--) =  (unsigned char)(((unsigned int)p_Task&0xff00)>>8);      	//�������
		*(p_Stack--) =0x00;                    	  //R1 __zero_reg__             
  		*(p_Stack--) =0x00;                    	  //R0 __tmp_reg__ 
  		*(p_Stack--) =0x80;                    	  //SREG �������У�����ȫ���ж�         
 	 for(i=0;i<30;i++)  						
   		*(p_Stack--)=i;                    		   						
		TCB[t_Prio].OSTCBStkPtr = (INT16U)p_Stack;// ���˹���ջ��ջ�������浽��ջ��������
		TCB[t_Prio].OSTCBDly = 0;	
	}

void CPU_OSStart(void)
   {
    CPU_TaskCreate(Idle_Task,&StackIdle[StackSizeIdle-1],OS_TASKS);
	OSPrioCur = OSPrioHighRdy=0;			// �ھ������в�����߼��ľ������� 
	SP=TCB[OSPrioCur].OSTCBStkPtr+33; 		//��ջ���Ƶ�pcλ��,׼������
	TIMSK|=_BV(TOIE0);
	sei();	
   }

