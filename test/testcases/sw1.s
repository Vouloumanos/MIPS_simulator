lui $3, 0x2000
addiu $3, $3, 0x0010
lui $4, 0xAABB
addiu $4, $4, 0xCCDD
sw $4, 0($3)
lw $2, 0($3)
srl $2, $2, 16
jr $0
nop

#Expected: 187
