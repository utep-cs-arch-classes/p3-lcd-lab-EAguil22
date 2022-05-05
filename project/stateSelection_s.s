	.arch msp430g2553
	.p2align 1,0
	.text

	
	.global stateSelection
	.extern state
	.extern count
	


jmp_tb:
	.word case_1
	.word case_2
	.word case_3
	.word case_4
	

stateSelection:
	mov.w &state, r12
	add.w r12, r12
	mov.w jmp_tb(r12), r0

case_1:
	mov.w #250, r12
	CALL #buzzer_set_period
	jmp end
	
case_2:
	CALL #playgame
	jmp end

case_3:
	
	CALL #win
	jmp end

case_4:
	
	CALL #lose
	jmp end

default:
	CALL #playgame

end:
	pop r0
