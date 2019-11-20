lui $3, 0x3000
addiu $3, $3, 0x0000
lui $4, 0xAABB
addiu $4, $4, 0xCCDD
sw $4, 0($3)
jr $0
nop

#Check for store in read-only memory. Expected: 245
