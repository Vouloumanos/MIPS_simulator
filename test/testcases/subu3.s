
lui $2, 0x7FFF
addi $2, $2, 0xFFFF
lui $3, 0x8000

subu $2, $2, $3

jr $0
nop

#expect -1 (255) no arithmetic
