
lui $3, 0x8000
addiu $2, $2, 4

multu $3, $2

mfhi $2

jr $0
nop

#expect 2
