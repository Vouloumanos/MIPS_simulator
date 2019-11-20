lui $3, 0x2000
addiu $3, $3, 0x0012
lui $4, 0xAABB
addiu $4, $4, 0xCCDD
addiu $5, $0, 0xFF05
sh $5, -1($3)
srl $2, $2, 24
jr $0
nop

#Check for unaligned memory store. Expected: 245
