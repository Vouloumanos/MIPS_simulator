lui $3, 0x2300
ori $3, $3, 0x0002
lui $4, 0xA070
ori $4, $4, 0xCCDD
sw $4, -2($3)
lb $2, 1($3)
jr $zero
nop

#Expected: 221
