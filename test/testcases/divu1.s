
addi $3, $3, 10
addi $4, $4, 3

divu $3, $4

mfhi $2

jr $0
nop

#expect 1
