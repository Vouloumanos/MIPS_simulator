lui $3, 0x3000
ori $3, $3, 0x0004
lwl $2, 0($3)
jr $zero
nop


#Check for read from write-only address(memory exception).
#Expected: 245
