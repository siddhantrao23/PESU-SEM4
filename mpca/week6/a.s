.text
    LDR r0, =str
loop:
    LDRb r1, [r0], #1    
    ADD r2, r2, #1
    CMP r1, #0
    BNE loop

    SUB r2, r2, #1
    SWI 0x011

.data
    str: .asciz "hell"

