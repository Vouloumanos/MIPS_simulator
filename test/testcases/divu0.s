
addi $3, $3, 10
addi $4, $4, 3

divu $3, $4

mflo $2

jr $0
nop

#expect 3
