lui $3, 0x2100
ori $3, $3, 0x0004
lui $4, 0xAABB
ori $4, $4, 0xCCDD
lui $5, 0xEEEE
ori $5, $5, 0xEEEE
sw $4, 0($3)
lwr $5, 1($3)
srl $2, $5, 0
jr $zero
nop


#Expected: 187
