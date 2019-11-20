lui $3, 0x1000
ori $3, $3, 0x0012
lui $4, 0xAABB
ori $4, $4, 0xCCDD
ori $5, $0, 0xFF05
sh $5, 0($3)
srl $2, $2, 24
jr $0
nop

#Check for store in memory location out of range. Expected: 245
