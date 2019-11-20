lui $3, 0x2000
addiu $3, $3, 0x0012
lui $4, 0xAABB
addiu $4, $4, 0xCCDD
addiu $5, $0, 0xFF05
sw $4, -2($3)
sb $5, 0($3)
lw $2, -2($3)
jr $0
nop

#Expected: 221
