lui $3, 0x2400
ori $3, $3, 0x0006
lui $4, 0xA070
ori $4, $4, 0xCCDD
sw $4, -2($3)
lb $2, -2($3)
jr $zero
nop


#Check for read from memory location outside the range (memory exception).
#Expected: 245
