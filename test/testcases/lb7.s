lui $3, 0x3000
ori $3, $3, 0x0004
lui $4, 0xA070
ori $4, $4, 0xCCDD
sw $4, -2($3)
lb $2, 0($3)
jr $zero
nop


#Check for read from write-only address(memory exception).
#Expected: 245
