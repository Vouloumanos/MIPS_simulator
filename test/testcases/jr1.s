.set noreorder

addi $2, $2, 7

jr $2
nop

addi $2, $2, 7
jr $0
nop

#expect memory (245)
