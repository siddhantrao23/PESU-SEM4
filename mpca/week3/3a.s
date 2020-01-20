.text
    MOV r2 ,#10
    LDR r0, =A
    LDR r4, =B
loop:
    LDRb r1, [r0], #1
    ADD r3, r3, r1
    SUBs r2, r2, #1
    BNE loop
    
    STR r3, [r4]
    SWI 0x011

.data
    A: .byte 1,2,3,4,5,6,7,8,9,10
    B: .word 0
