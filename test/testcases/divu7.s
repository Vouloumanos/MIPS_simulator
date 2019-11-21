
addiu $3, $3, -2
addiu $2, $2, 1

divu $2, $3

mfhi $2

jr $0
nop

#expect 1
