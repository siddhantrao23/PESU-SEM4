MOV r0, #20
MOV r1, #20
EORs r2, r1, r0
BEQ equal
SUB r3, r1, r0 
b end
equal: ADD r3, r1, r0
end: SWI 0x011
