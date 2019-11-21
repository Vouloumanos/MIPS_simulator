
lui $3, 0x8000
addiu $2, $2, 2

div $3, $2

mflo $2
srl $2, $2, 24

jr $0
nop

#expect 198
