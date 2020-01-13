.text
LDR r0, =A
LDR r1, =B

MOV r2, #4
MOV r5, #0
loop:
    LDRb r3, [r0]
    ADD r5, r5, r3
    ADD r0, r0, #1
    SUBs r2, r2, #1
    BNE loop
STR r5, [r1]
SWI 0x011

.data
A: .byte 10, 20, 30, 40
B: .byte 0
