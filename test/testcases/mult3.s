
addi $3, $3, -3
addi $2, $2, 5

mult $3, $2

mflo $2

jr $0
nop

#expect -15 (241)
