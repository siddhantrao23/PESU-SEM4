.data
    str: .asciz "PESU"
    num: .word 1

.text
    MOV r0, #30
    MOV r1, #7
    MOV r7, #0
    LDR r8, =num
    LDR r8, [r8]
    LDR r2, =str
loop:    
    SWI 0x204   ;print at x,y
    BL delay
    CMP r0, #0
    SUBNE r0, r0, #1
    BEQ end
    B loop
delay:
    CMP r7, r8
    ADDNE r7, r7, #1
    BNE delay
    SWI 0x206   ;clrscr
    MOV r7, #0
    MOV PC, LR
end:
    SWI 0x011
.end
