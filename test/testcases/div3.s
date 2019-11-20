
addiu $3, $3, -1
addiu $4, $4, -1

div $3, $4

mflo $2

jr $0
nop

#expect 1
