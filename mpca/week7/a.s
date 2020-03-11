MOV r0, #0
loop:
    SWI 0x201
    ADD r0, r0, #1
    MOV r4, #64000
delay:
    SUBs r4, r4, #1
    CMP r4, #0
    BNE delay
    CMP r0, #3
    BLE loop
SWI 0x011
