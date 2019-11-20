
lui $3, 0x8000
addi $2, $2, 4

mult $3, $2

mfhi $2

jr $0
nop

#expect -2 (254)
