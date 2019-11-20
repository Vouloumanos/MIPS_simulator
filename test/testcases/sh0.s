lui $3, 0x2000
ori $3, $3, 0x0012
lui $4, 0xAABB
ori $4, $4, 0xCCDD
ori $5, $0, 0x0705
sw $4, -2($3)
sh $5, 0($3)
lw $2, -2($3)
srl $2, $2, 24
jr $0
nop

#Expected: 170
