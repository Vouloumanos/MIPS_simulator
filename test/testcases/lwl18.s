lui $3, 0x1000
addiu $3, $3, 0x000C
lui $4, 0xAABB
addiu $4, $4, 0xCCDD
lui $5, 0xEEEE
addiu $5, $5, 0xEEEE
lwl $5, 1($3)
srl $2, $5, 8
jr $zero
nop


#Check for load from instruction memory. Expected: 221
