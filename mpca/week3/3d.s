.text
    LDR r0, =A
    LDR r1, =B
    MOV r2, #4
loop:
    LDR r3, [r0], #4
    LDR r4, [r1], #4
    MUL r5, r3, r4
    ADD r6, r6, r5
    SUBs r2, r2, #1
    BNE loop
    
    SWI 0x011

.data 
    A: .word 10, 20, 30, 40
    B: .word 1, 2, 3, 4
