
addiu $2, $2, 7
addiu $3, $3, 0

sltu $2, $2, $3

jr $0
nop

#expect 0
