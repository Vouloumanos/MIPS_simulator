
addiu $3, $3, -2
addiu $2, $2, 1

div $2, $3

mflo $2

jr $0
nop

#expect 0
