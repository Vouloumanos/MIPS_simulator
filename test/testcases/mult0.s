
addi $3, $3, 3
addi $4, $4, 4

mult $3, $4

mflo $2

jr $0
nop

#expect 12
