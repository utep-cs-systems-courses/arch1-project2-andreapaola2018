	.arch msp430g2553
	.p2align 1,0

	.text

def:
	.word caseR
	.word caseG
	

state_advance:



caseR:
	call #toggle_red
	jmp out

caseG:
	call #toggle_green
	jmp out

out:
	ret
