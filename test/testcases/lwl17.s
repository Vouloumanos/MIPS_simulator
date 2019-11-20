lui $3, 0x3000
addiu $3, $3, 0x0004
lwl $5, 0($3)
jr $zero
nop


#Check for read from write-only address(memory exception).
#Expected: 245
