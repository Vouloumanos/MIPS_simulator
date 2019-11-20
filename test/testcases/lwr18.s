lui $3, 0x1000
ori $3, $3, 0x000C
lui $4, 0xAABB
ori $4, $4, 0xCCDD
lui $2, 0xEEEE
ori $2, $2, 0xEEEE
lwr $2, 2($3)
jr $zero
nop


#Check for load from instruction memory. Expected: 204
