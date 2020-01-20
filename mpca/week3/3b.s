.text
    LDR r0, =A
    LDR r1, =B
    MOV r2 ,#10
    LDR r3, [r1]
loop:
    LDR r4, [r0], #4
    CMP r3, r4
    BEQ found

    SUBs r2, r2, #1
    BNE loop

    MOV r6, #-1
    SWI 0x011
    
found:
    RSB r7, r2, #10
    SWI 0x011

.data
    A: .word 1,2,3,4,5,6,7,8,9,10
    B: .word 44
