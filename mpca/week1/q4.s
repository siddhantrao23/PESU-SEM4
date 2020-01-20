MOV r1, #21
ANDs r2, r1, #1
BEQ even
MOV r3, #1
b end
even: MOV r3, #0
end: SWI 0x011
