.text
LDR r0, =A
LDR r4, =B

MOV r3, #5
loop:
    LDR r1, [r0]
    ADD r2, r2, r1
    ADD r0, r0, #4
    SUBs r3, r3, #1
    BNE loop
STR r2, [r4]

.data
A: .word 10,20,30,40,50
B: .word 00
