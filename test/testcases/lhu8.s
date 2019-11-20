lui $3, 0x0000
addiu $3, $3, 0x0006
lui $4, 0xA0BB
addiu $4, $4, 0x70DD
sw $4, -2($3)
lhu $2, -2($3)
srl $2, $2, 12
jr $zero
nop


#Check for read from memory location outside the range (memory exception).
#Expected: 245
