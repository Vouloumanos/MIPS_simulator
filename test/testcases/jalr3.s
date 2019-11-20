.set noreorder

lui $3, 0x1100
addi $2, $2, 8
addi $3, $3, 8

jalr $2, $3
nop

addi $2, $2, 7
jr $0
nop

#expect memory (245)
