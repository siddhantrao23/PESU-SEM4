MOV r0, #0
again:
    SWI 0x203
    CMP r0, #1
    BEQ one
    CMP r0, #2
    BEQ two
    CMP r0, #4
    BEQ three
    CMP r0, #8
    BEQ four
    CMP r0, #16
    BEQ five
    CMP r0, #32
    BEQ six
    CMP r0, #64
    BEQ seven
    CMP r0, #128
    BEQ eight
    CMP r0, #256
    BEQ nine
    CMP r0, #512
    BEQ a
    CMP r0, #1024
    BEQ b
    CMP r0, #2048
    BEQ c
    CMP r0, #4096
    BEQ d
    CMP r0, #8192
    BEQ e
    CMP r0, #16384
    BEQ f
    B again
    CMP r0, #32768
    BEQ last
    B again

one:
    LDR r0, =ZERO
    LDRb r0, [r0]
    SWI 0x200
    BL delay
    B again
two:
    LDR r0, =ONE
    LDRb r0, [r0]
    SWI 0x200
    BL delay
    B again
three:
    LDR r0, =TWO
    LDRb r0, [r0]
    SWI 0x200
    BL delay
    B again
four:
    LDR r0, =THREE
    LDRb r0, [r0]
    SWI 0x200
    BL delay
    B again
five:
    LDR r0, =FOUR
    LDRb r0, [r0]
    SWI 0x200
    BL delay
    B again
six:
    LDR r0, =FIVE
    LDRb r0, [r0]
    SWI 0x200
    BL delay
    B again
seven:
    LDR r0, =SIX
    LDRb r0, [r0]
    SWI 0x200
    BL delay
    B again
eight:
    LDR r0, =SEVEN
    LDRb r0, [r0]
    SWI 0x200
    BL delay
    B again
nine:
    LDR r0, =EIGHT
    LDRb r0, [r0]
    SWI 0x200
    BL delay
    B again
a:
    LDR r0, =NINE
    LDRb r0, [r0]
    SWI 0x200
    BL delay
    B again
b:
    LDR r0, =A
    LDRb r0, [r0]
    SWI 0x200
    BL delay
    B again
c:
    LDR r0, =B
    LDRb r0, [r0]
    SWI 0x200
    BL delay
    B again
d:
    LDR r0, =C
    LDRb r0, [r0]
    SWI 0x200
    BL delay
    B again
e:
    LDR r0, =D
    LDRb r0, [r0]
    SWI 0x200
    BL delay
    B again
f:
    LDR r0, =E
    LDRb r0, [r0]
    SWI 0x200
    BL delay
    B again

last:
    LDR r0, =F
    LDRb r0, [r0]
    SWI 0x200
    BL delay
    B again

delay: 
    MOV r4,#16000
    loop3: SUB r4, r4, #1
    CMP r4, #0
    BGE loop3
    MOV PC, LR

end:
    SWI 0x011


.data
    ZERO: .byte 0b11101101
    ONE: .byte 0b01100000
    TWO: .byte 0b11001110
    THREE: .byte 0b11101010
    FOUR: .byte 0b01100011
    FIVE: .byte 0b10101011
    SIX: .byte 0b10101111
    SEVEN: .byte 0b11100000
    EIGHT: .byte 0b11101111
    NINE: .byte 0b11101011
    A: .byte 0b11100111
    B: .byte 0b00101111
    C: .byte 0b10001101
    D: .byte 0b01101110
    E: .byte 0b10001111
    F: .byte 0b10000111
