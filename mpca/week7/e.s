MOV R0, #0
again: 
    SWI 0X202
    CMP R0, #2
    BEQ loop
    B again
    loop:
        MOV R5, #4
        LDR R1, =P
        back:
            LDRB R0, [R1]
            SWI 0X200
            BL delay
            ADD R1, R1, #1
            SUB R5, R5, #1
            CMP R5, #0
            BNE back
    B again
    delay:
        MOV R4, #16000
        loop3:
            SUB R4, R4, #1
            CMP R4, #0
            BGE loop3
            MOV PC, LR

.data
    P: .byte 0b11000111
    E: .byte 0b10001111
    S: .byte 0b10101011
    U: .byte 0b01101101
