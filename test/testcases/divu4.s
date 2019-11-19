
addi $3, $3, -2
addi $4, $4, 2

divu $3, $4

mfhi $2

jr $0
nop

#expect 0
