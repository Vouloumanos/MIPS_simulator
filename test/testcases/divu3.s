
lui $3, 0xFFFF
addi $3, $3, 0xFFFF
addi $4, $4, -1

divu $3, $4

mflo $2

jr $0
nop

#expect ?
