lui $3, 0x2100
addiu $3, $3, 0x0004
lui $4, 0xAABB
addiu $4, $4, 0xCCDD
lui $5, 0xEEEE
addui $5, $5, 0xEEEE
sw $4, 0($3)
lwl $5, 1($3)
srl $2, $5, 24
jr $zero
nop


#Expected: 187
