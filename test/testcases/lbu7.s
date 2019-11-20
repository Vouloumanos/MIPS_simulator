lui $3, 0x3000
addiu $3, $3, 0x0007
lb $2, 0($3)
jr $zero
nop


#Check for read from write-only address(memory exception).
#Expected: 245
