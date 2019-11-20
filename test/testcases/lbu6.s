lui $3, 0x1000
addiu $3, $3, 0x0006
lui $4, 0xA070
addiu $4, $4, 0xCCDD
sw $4, -2($3)
lbu $2, -2($3)
jr $zero
nop


#Check for read from memory location outside the range (memory exception).
#Expected: 245
