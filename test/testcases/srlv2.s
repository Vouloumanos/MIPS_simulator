
lui $2, 0x8000
addi $2, $2, 7
addi $3, $3, 32

srlv $2, $2, $3

jr $0
nop

#expect 7
