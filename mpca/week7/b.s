.text
    MOV r0, #8
    MOV r1, #32
    loop:
    ANDs r2, r0, #1
    CMP r2, #1
    BEQ odd
    SUBs r1, r1, #1
    CMP r1, #0
    BNE loop

    ANDs r3, r3, #1
    CMP r3, #0
    BEQ evenparity
    LDR r0, =O
    SWI 0x02
    SWI 0x011

odd:
    MOV r0, r0, LSR #1
    SUBs r1, r1, #1
    ADD r3, r3, #1
    B loop

evenparity:
    LDR r0, =E
    SWI 0x02
    SWI 0x011

.data
    O: .asciz "Odd Parity"
    E: .asciz "Even Parity"
