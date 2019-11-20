lui $3, 0x3000
ori $3, $3, 0x0004
lw $2, 0($3)
jr $zero
nop


#Check for read from write-only address(memory exception).
#Expected: 245
