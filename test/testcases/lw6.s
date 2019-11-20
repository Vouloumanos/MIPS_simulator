lui $3, 0x2100
addiu $3, $3, 0x0006
lw $2, 1($3)
jr $zero
nop


#Check for read from unaligned memory location (memory exception).
#Expected: 245
