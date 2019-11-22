lui $3, 0x3000
ori $3, $3, 0x0004
lui $2, 0xAABB
ori $2, $2, 0xFF61
sw $2, 0($3)
jr $0
nop

#Output character a even when the rest of the register is not 0. Expected: 97
