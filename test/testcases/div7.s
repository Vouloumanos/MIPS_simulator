
lui $3, 0x8000
addiu $2, $2, 2

div $3, $2

mfhi $2

jr $0
nop

#expect 0
