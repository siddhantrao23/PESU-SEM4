.text
    LDR r0, =A
    LDR r1, =B
loop:
    LDRb r2, [r0], #1
    STRb r2, [r1], #1
    CMP r2, #0
    BNE loop

    LDR r0, =B
    SWI 0x02
    SWI 0x011

.data
    A: .asciz "bhargeeeeeeeee"
    B: .asciz ""
