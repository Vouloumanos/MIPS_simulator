addiu $2, $0, 0xFFFF
andi $2, $2, 0b01010101
jr $0
nop

#Expected: 85
