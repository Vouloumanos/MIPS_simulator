lui $3, 0x2200
addiu $3, $3, 0x0006
lui $4, 0xA0BB
addiu $4, $4, 0x70DD
sw $4, -2($3)
lhu $2, -1($3)
srl $2, $2, 8
jr $zero
nop


#Check for read from unaligned memory location (memory exception).
#Expected: 245
