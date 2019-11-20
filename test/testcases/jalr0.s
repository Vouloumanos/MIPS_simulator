.set noreorder

addiu $2, $2, 7

jalr $2, $0
nop

addiu $2, $2, 7

#expect 0x000C (12)
