.set noreorder

addi $2, $2, 7

jalr $2, $0
nop

addi $2, $2, 7

#expect 0x000C (12)
