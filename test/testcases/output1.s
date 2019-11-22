lui $3, 0x3000
ori $3, $3, 0x0004
lui $4, 0xAABB
ori $4, $4, 0xFF61
sw $4, 0($3)
ori $2, $2, 5
jr $0
nop

#Output character a even when the rest of the register is not 0. Expected: 5
