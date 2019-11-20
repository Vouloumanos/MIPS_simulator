lui $3, 0x2000
ori $3, $3, 0x0010
lui $4, 0xAABB
ori $4, $4, 0xCCDD
sw $4, 3($3)
jr $0
nop

#Check for store in unaligned memory. Expected: 245
