
addiu $2, $2, -1
addiu $3, $3, -2

sltu $2, $2, $3

jr $0
nop

#expect 0
