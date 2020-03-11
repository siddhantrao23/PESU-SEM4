.text
again:
    SWI 0x202
    CMP r0, #1
    BEQ again
    BEQ loop1
    CMP r0, #2
    BEQ loop2
    B again
    loop1:
        MOV r5, #16
        LDR r1, =zero
    back1:
        LDRb r0, [r1]
        SWI 0x200
        BL delay
    ADD r1, r1, #1
    SUB r5, r5, #1
    CMP r5, #0
    BNE back1
    B again
    loop2:
        MOV r5, #16
