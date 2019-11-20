.set noreorder

addi $2, $2, 7
addi $3, $3, 7

jalr $2, $3
nop

addi $2, $2, 7
jr $0
nop

#expect memory (245)
