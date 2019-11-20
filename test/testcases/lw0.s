lui $3, 0x2100
addiu $3, $3, 0x0006
lui $4, 0xAABB
addiu $4, $4, 0xCCDD
sw $4, -2($3)
lw $2, -2($3)
srl $2, $2, 24
jr $zero
nop


#Expected: 170
