lui $3, 0x2400
ori $3, $3, 0x0000
lw $2, 0($3)
jr $zero
nop


#Check for read from memory location outside the range (memory exception).
#Expected: 245
