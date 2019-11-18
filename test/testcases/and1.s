
addi $3, $3, 0b10101100
addi $4, $4, 0b00001100

and $2, $3, $4

jr $0
nop

#expect 12
