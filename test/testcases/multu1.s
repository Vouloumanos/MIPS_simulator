
addiu $3, $3, 3
addiu $2, $2, 4

multu $3, $2

mfhi $2

jr $0
nop

#expect 0
