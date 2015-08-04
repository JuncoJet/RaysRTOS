/***************************************************************************************** 
 *  RaysRTOS/RaysRTOS_ASM.c 
 * 
 *  RaysRTOS�����ļ� 
 * 
 *  Copyright (C) 2010  Է��â 
 * 
 *  2010-07-09  RaysRTOS1.0-Mega8 �汾
 *  
 *	ȫ��ռʽ���� �ṩϵͳ��ʱ ���� �ָ��ȹ��� ���������8��  					   
 *****************************************************************************************/
#include "RaysRTOS.h"

/******************ȫ�ֱ�������***************/
 extern struct TaskCtrBlock  TCB[OS_TASKS + 1];		// ����������ƿ�				
 extern INT8U   OSPrioCur;		            		// �������е�����				
 extern INT8U   OSPrioHighRdy;           		// �������ȼ�������				
 extern INT16U  *TEMP_SP;
/*
+---------------------------------------------------------------------------------------+
|�������ƣ�	OSSched																		|
|---------------------------------------------------------------------------------------|
|����ԭ�ͣ�	void OSSched(prio)															|
|																						|
|�������ܣ�	�����л����� 														   		|																						|
+---------------------------------------------------------------------------------------+
*/
void OSSched(void)
{
	OS_ENTER_CRITICAL();                	//���ж�
				
	if(OSPrioHighRdy != OSPrioCur)			// ������ǵ�ǰ���е����񣬽���������� */
	{
 	//push all
  __asm__ __volatile__("PUSH __zero_reg__          \n\t");  //R1 
  __asm__ __volatile__("PUSH __tmp_reg__           \n\t");  //R0  
  __asm__ __volatile__("IN   __tmp_reg__,__SREG__  \n\t");  //����״̬�Ĵ���SREG 
  __asm__ __volatile__("PUSH __tmp_reg__           \n\t"); 
  __asm__ __volatile__("CLR  __zero_reg__          \n\t");  //R1��������    
  __asm__ __volatile__("PUSH R18                   \n\t"); 
  __asm__ __volatile__("PUSH R19                   \n\t"); 
  __asm__ __volatile__("PUSH R20                   \n\t"); 
  __asm__ __volatile__("PUSH R21                   \n\t"); 
  __asm__ __volatile__("PUSH R22                   \n\t"); 
  __asm__ __volatile__("PUSH R23                   \n\t"); 
  __asm__ __volatile__("PUSH R24                   \n\t"); 
  __asm__ __volatile__("PUSH R25                   \n\t"); 
  __asm__ __volatile__("PUSH R26                   \n\t"); 
  __asm__ __volatile__("PUSH R27                   \n\t"); 
  __asm__ __volatile__("PUSH R30                   \n\t");     
  __asm__ __volatile__("PUSH R31                   \n\t");
  __asm__ __volatile__("PUSH R2                    \n\t");   
  __asm__ __volatile__("PUSH R3                    \n\t");   
  __asm__ __volatile__("PUSH R4                    \n\t");   
  __asm__ __volatile__("PUSH R5                    \n\t"); 
  __asm__ __volatile__("PUSH R6                    \n\t"); 
  __asm__ __volatile__("PUSH R7                    \n\t");  
  __asm__ __volatile__("PUSH R8                    \n\t");  
  __asm__ __volatile__("PUSH R9                    \n\t");   
  __asm__ __volatile__("PUSH R10                   \n\t"); 
  __asm__ __volatile__("PUSH R11                   \n\t"); 
  __asm__ __volatile__("PUSH R12                   \n\t"); 
  __asm__ __volatile__("PUSH R13                   \n\t"); 
  __asm__ __volatile__("PUSH R14                   \n\t"); 
  __asm__ __volatile__("PUSH R15                   \n\t");   
  __asm__ __volatile__("PUSH R16                   \n\t");  
  __asm__ __volatile__("PUSH R17                   \n\t");  
  __asm__ __volatile__("PUSH R28                   \n\t");  //R28��R29���ڽ����ڶ�ջ�ϵ�ָ�� 
  __asm__ __volatile__("PUSH R29                   \n\t");  //��ջ��� 
	SPPoint();   
	*TEMP_SP=SP;						//���浱ǰ��ջָ��
	OSPrioCur = OSPrioHighRdy;			// ����OSPrioCur
	SPPoint();
	SP=*TEMP_SP;            			//�����ջָ���л�
 	//pop all
  __asm__ __volatile__("POP  R29                   \n\t");     
  __asm__ __volatile__("POP  R28                   \n\t"); 
  __asm__ __volatile__("POP  R17                   \n\t"); 
  __asm__ __volatile__("POP  R16                   \n\t"); 
  __asm__ __volatile__("POP  R15                   \n\t");     
  __asm__ __volatile__("POP  R14                   \n\t");     
  __asm__ __volatile__("POP  R13                   \n\t");     
  __asm__ __volatile__("POP  R12                   \n\t");     
  __asm__ __volatile__("POP  R11                   \n\t");     
  __asm__ __volatile__("POP  R10                   \n\t"); 
  __asm__ __volatile__("POP  R9                    \n\t"); 
  __asm__ __volatile__("POP  R8                    \n\t"); 
  __asm__ __volatile__("POP  R7                    \n\t");   
  __asm__ __volatile__("POP  R6                    \n\t"); 
  __asm__ __volatile__("POP  R5                    \n\t"); 
  __asm__ __volatile__("POP  R4                    \n\t");  
  __asm__ __volatile__("POP  R3                    \n\t"); 
  __asm__ __volatile__("POP  R2                    \n\t");        
  __asm__ __volatile__("POP  R31                   \n\t");     
  __asm__ __volatile__("POP  R30                   \n\t");     
  __asm__ __volatile__("POP  R27                   \n\t");     
  __asm__ __volatile__("POP  R26                   \n\t");     
  __asm__ __volatile__("POP  R25                   \n\t");     
  __asm__ __volatile__("POP  R24                   \n\t");     
  __asm__ __volatile__("POP  R23                   \n\t");     
  __asm__ __volatile__("POP  R22                   \n\t");     
  __asm__ __volatile__("POP  R21                   \n\t");     
  __asm__ __volatile__("POP  R20                   \n\t");     
  __asm__ __volatile__("POP  R19                   \n\t"); 
  __asm__ __volatile__("POP  R18                   \n\t");   
  __asm__ __volatile__("POP  __tmp_reg__           \n\t");      //SERG ��ջ���ָ� 
  __asm__ __volatile__("OUT  __SREG__,__tmp_reg__  \n\t");     
  __asm__ __volatile__("POP  __tmp_reg__           \n\t");      //R0 ��ջ 
  __asm__ __volatile__("POP  __zero_reg__          \n\t");      //R1 ��ջ 
	}
	OS_EXIT_CRITICAL();     //���ж�
}

/*
+---------------------------------------------------------------------------------------+
|�������ƣ�	SIGNAL																		|
|---------------------------------------------------------------------------------------|
|����ԭ�ͣ�	 SIGNAL(SIG_OVERFLOW0)														|
|																						|
|�������ܣ�	�жϼ��л����� 														   		|																						|
+---------------------------------------------------------------------------------------+
*/
SIGNAL(SIG_OVERFLOW0)
{
	OS_ENTER_CRITICAL();           //���ж�
	TCNT0=TCNT0_INIT;
	//push all �����ж��Զ�����ļĴ���
  __asm__ __volatile__("PUSH R2                    \n\t");   
  __asm__ __volatile__("PUSH R3                    \n\t");   
  __asm__ __volatile__("PUSH R4                    \n\t");   
  __asm__ __volatile__("PUSH R5                    \n\t"); 
  __asm__ __volatile__("PUSH R6                    \n\t"); 
  __asm__ __volatile__("PUSH R7                    \n\t");  
  __asm__ __volatile__("PUSH R8                    \n\t");  
  __asm__ __volatile__("PUSH R9                    \n\t");   
  __asm__ __volatile__("PUSH R10                   \n\t"); 
  __asm__ __volatile__("PUSH R11                   \n\t"); 
  __asm__ __volatile__("PUSH R12                   \n\t"); 
  __asm__ __volatile__("PUSH R13                   \n\t"); 
  __asm__ __volatile__("PUSH R14                   \n\t"); 
  __asm__ __volatile__("PUSH R15                   \n\t");   
  __asm__ __volatile__("PUSH R16                   \n\t");  
  __asm__ __volatile__("PUSH R17                   \n\t");  
  __asm__ __volatile__("PUSH R28                   \n\t");  //R28��R29���ڽ����ڶ�ջ�ϵ�ָ�� 
  __asm__ __volatile__("PUSH R29                   \n\t");  //��ջ��� 

  	TickIntHook();
	SPPoint();   
	*TEMP_SP=SP;						//���浱ǰ��ջָ��
	OSPrioCur = OSPrioHighRdy;			// ����OSPrioCur
	SPPoint();
	SP=*TEMP_SP;            			//�����ջָ���л�
	//pop all �����ж��Զ�����ļĴ���
  __asm__ __volatile__("POP  R29                   \n\t");     
  __asm__ __volatile__("POP  R28                   \n\t"); 
  __asm__ __volatile__("POP  R17                   \n\t"); 
  __asm__ __volatile__("POP  R16                   \n\t"); 
  __asm__ __volatile__("POP  R15                   \n\t");     
  __asm__ __volatile__("POP  R14                   \n\t");     
  __asm__ __volatile__("POP  R13                   \n\t");     
  __asm__ __volatile__("POP  R12                   \n\t");     
  __asm__ __volatile__("POP  R11                   \n\t");     
  __asm__ __volatile__("POP  R10                   \n\t"); 
  __asm__ __volatile__("POP  R9                    \n\t"); 
  __asm__ __volatile__("POP  R8                    \n\t"); 
  __asm__ __volatile__("POP  R7                    \n\t");   
  __asm__ __volatile__("POP  R6                    \n\t"); 
  __asm__ __volatile__("POP  R5                    \n\t"); 
  __asm__ __volatile__("POP  R4                    \n\t");  
  __asm__ __volatile__("POP  R3                    \n\t"); 
  __asm__ __volatile__("POP  R2                    \n\t");   
  OS_EXIT_CRITICAL();              //���ж�
} 
