
addi $2, $2, -1
addi $3, $3, 1

subu $2, $2, $3

jr $0
nop

#expect -2 (254)
