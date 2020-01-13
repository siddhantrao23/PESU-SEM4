.text
LDR r0, =A
LDR r1, =B

MOV r2, #5
loop:
    LDR r3, [r0]
    STR r3, [r1]
    ADD r0, r0, #4
    ADD r1, r1, #4
    SUBs r2, r2, #1
    BNE loop

.data
A: .word 10, 20, 30, 40, 50
B: .word 00, 00, 00, 00
