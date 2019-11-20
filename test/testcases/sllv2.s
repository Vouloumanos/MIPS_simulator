
addiu $2, $2, 1
addiu $3, $3, 32

sllv $2, $2, $3

jr $0
nop

#expect 1
