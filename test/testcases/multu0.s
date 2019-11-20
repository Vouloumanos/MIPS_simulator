
addiu $3, $3, 3
addiu $4, $4, 4

multu $3, $4

mflo $2

jr $0
nop

#expect 12
