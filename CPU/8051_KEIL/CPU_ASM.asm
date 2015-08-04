; /*****************************************************************************************  
;  *  8051 CPU���ASM�ļ�
;  * 
;  *  Copyright (C) 2010  Է��â 
;  * 
;  *  2010-07-09  RaysRTOS 
;  *****************************************************************************************/
$NOMOD51
#include "REG52.INC"

NAME	CPU_ASM


?PR?OSSched?CPU_ASM    SEGMENT CODE 
?PR?Timer0ISR?CPU_ASM  SEGMENT CODE 

	EXTRN	CODE (TickIntHook)
	EXTRN	DATA (TCB)
	EXTRN	DATA (OSPrioCur)
	EXTRN	DATA (OSPrioHighRdy)

	PUBLIC	Timer0ISR
	PUBLIC	OSSched

	RSEG  ?PR?OSSched?CPU_ASM
OSSched:
	USING	0
	CLR  	EA
	MOV  	A,OSPrioHighRdy
	XRL  	A,OSPrioCur
	JZ   	?C0001
	 PUSH ACC        
	 PUSH B
	 PUSH DPH
	 PUSH DPL
	 PUSH PSW
	 PUSH AR0	      
	 PUSH AR1
	 PUSH AR2
	 PUSH AR3
	 PUSH AR4
	 PUSH AR5
	 PUSH AR6   
	 PUSH AR7   

	MOV  	A,OSPrioCur
	MOV  	B,#03H
	MUL  	AB
	ADD  	A,#LOW (TCB)
	MOV  	R0,A
	MOV  	@R0,SP

	MOV  	OSPrioCur,OSPrioHighRdy

	MOV  	A,OSPrioCur
	MOV  	B,#03H
	MUL  	AB
	ADD  	A,#LOW (TCB)
	MOV  	R0,A
	MOV  	A,@R0
	MOV  	SP,A
	 POP AR7
	 POP AR6
	 POP AR5
	 POP AR4
	 POP AR3
	 POP AR2
	 POP AR1
	 POP AR0
	 POP PSW
	 POP DPL
	 POP DPH
	 POP B
	 POP ACC
?C0001:
	SETB 	EA
	RET 




; /*
; +---------------------------------------------------------------------------------------+
; |�������ƣ�	Timer0ISR																	|
; |---------------------------------------------------------------------------------------|
; |����ԭ�ͣ�	void Timer0ISR(prio)														|
; |																						|
; |�������ܣ�	�жϼ��л����� 														   		|																						|
; +---------------------------------------------------------------------------------------+
; */

CSEG	AT	0000BH
	LJMP	Timer0ISR 

	RSEG  ?PR?Timer0ISR?CPU_ASM
	USING	0
Timer0ISR:
	PUSH 	ACC
	PUSH 	B
	PUSH 	DPH
	PUSH 	DPL
	PUSH 	PSW
	USING	0
	MOV  	PSW,#00H
	CLR  	EA
	MOV  	TH0,#0FEH
	MOV  	TL0,#00H
	CLR  	TR0

	 PUSH AR0	      
	 PUSH AR1
	 PUSH AR2
	 PUSH AR3
	 PUSH AR4
	 PUSH AR5
	 PUSH AR6   
	 PUSH AR7 
	LCALL	TickIntHook
	MOV  	A,OSPrioCur
	MOV  	B,#03H
	MUL  	AB
	ADD  	A,#LOW (TCB)
	MOV  	R0,A
	MOV  	@R0,SP

	MOV  	OSPrioCur,OSPrioHighRdy

	MOV  	A,OSPrioCur
	MOV  	B,#03H
	MUL  	AB
	ADD  	A,#LOW (TCB)
	MOV  	R0,A
	MOV  	A,@R0
	MOV  	SP,A

	 POP AR7
	 POP AR6
	 POP AR5
	 POP AR4
	 POP AR3
	 POP AR2
	 POP AR1
	 POP AR0
	SETB 	TR0
	SETB 	EA
	POP  	PSW
	POP  	DPL
	POP  	DPH
	POP  	B
	POP  	ACC
	RETI 

	END
