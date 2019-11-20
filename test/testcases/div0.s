
addiu $3, $3, 10
addiu $4, $4, 3

div $3, $4

mflo $2

jr $0
nop

#expect 3
