
lui $2, 0x8000
ori $2, $2, 7
addiu $3, $3, 32

srlv $2, $2, $3

jr $0
nop

#expect 7
