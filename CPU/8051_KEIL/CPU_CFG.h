/*****************************************************************************************  
 *  8051 CPU���H�ļ�
 * 
 *  Copyright (C) 2010  Է��â 
 * 
 *  2010-07-09  RaysRTOS 
 *****************************************************************************************/
/*--------------------------------------------------------------------------------------+
|�ض�Ӳ��ƽ̨                                                                           |
+---------------------------------------------------------------------------------------*/
#include<REG52.h>

typedef unsigned char  BOOLEAN;
typedef unsigned char  INT8U;                                             
typedef signed   char  INT8S;                                            
typedef unsigned int   INT16U;                                            
typedef signed   int   INT16S;                                            
typedef unsigned long  INT32U;                                        
typedef signed   long  INT32S; 

/*--------------------------------------------------------------------------------------+
|ϵͳ����																				|
+---------------------------------------------------------------------------------------*/
#define StackSizeIdle     20		 // �����������ջ��С                 
#define OS_TICKS_PER_SEC  100        // ����һ���ڵ�ʱ�ӽ�����             
#define OS_TASKS		  3			 // �趨�������������,�������������� 
#define TASK_SUSPEND_EN   0          //�����Ƿ���Թ���ͻָ� 1������ 0��������


typedef unsigned char  STACK_TypeDef;
typedef unsigned char  PRIO_TypeDef;
typedef unsigned int   TICKS_TypeDef;

/*--------------------------------------------------------------------------------------+
|����ṹ��TCB                                                                          |
+---------------------------------------------------------------------------------------*/
  struct TaskCtrBlock            	 // ������ƿ����ݽṹ
{
	INT8U	OSTCBStkPtr;			 // ��������Ķ�ջ��  
	INT16U	OSTCBDly;				 // ������ʱʱ��
};

/*--------------------------------------------------------------------------------------+
|ϵͳ�꺯��																				|
+---------------------------------------------------------------------------------------*/
#define  OS_ENTER_CRITICAL()  (EA=0) // �����ٽ��

#define  OS_EXIT_CRITICAL()   (EA=1) // �˳��ٽ��


/******************ȫ�ֱ�������***************/
extern  INT8U   StackIdle[StackSizeIdle]; 				// ������������ջ
extern  INT8U   OSRdyTbl;     							// ���������б�
extern  INT8U   OSPrioCur;		            			// ��ǰ��������ȼ�
extern  INT8U   OSPrioHighRdy;           		    	// ����Ҫ������������ȼ�	
extern  INT8U  IdleCount;								// ���������Լ���
extern  struct  TaskCtrBlock TCB[OS_TASKS + 1];			// ����������ƿ�TCB����

void CPU_TaskCreate(void (*p_Task)(void),STACK_TypeDef *p_Stack,PRIO_TypeDef t_Prio);
void CPU_OSStart(void);


