lui $3, 0x2500
ori $3, $3, 0x0006
lbu $2, -2($3)
jr $zero
nop


#Check for read from memory location outside the range (memory exception).
#Expected: 245
