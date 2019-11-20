
lui $2, 0x8000
addiu $3, $3, 31

srav $2, $2, $3

jr $0
nop

#expect 255
