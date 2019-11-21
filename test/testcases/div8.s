
lui $3, 0xC000
addiu $2, $2, 1

div $2, $3

mfhi $2
srl $2, $2, 24

jr $0
nop

#expect 192
