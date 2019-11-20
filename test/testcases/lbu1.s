lui $3, 0x2300
addiu $3, $3, 0x0006
lui $4, 0xA070
addiu $4, $4, 0xCCDD
sw $4, -2($3)
lbu $2, -1($3)
jr $zero
nop


#Expected: 112
