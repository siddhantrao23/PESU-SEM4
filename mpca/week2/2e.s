MOV r0, #15
MOV r1, #9

gcd:
    CMP r0, r1
    BEQ eqal
    BMI subtr
    SUB r0, r0, r1
    B gcd

subtr:
    SUB r1, r1, r0
    B gcd
    
eqal:
    MOV r2, r0
    SWI 0x011
