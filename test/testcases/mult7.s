
lui $3, 0x8000
addi $2, $2, 2

mult $3, $2

mflo $2

jr $0
nop

#expect 0
