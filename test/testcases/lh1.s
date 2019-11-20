lui $3, 0x2200
ori $3, $3, 0x0006
lui $4, 0xA0BB
ori $4, $4, 0x70DD
sw $4, -2($3)
lh $2, -2($3)
jr $zero
nop


#Expected: 187
