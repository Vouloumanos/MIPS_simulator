lui $3, 0x1000
ori $3, $3, 0x000C
lui $4, 0xAABB
ori $4, $4, 0xCCDD
lh $2, 0($3)
srl $2, $2, 8
jr $zero
nop


#Check for read from instruction address.
#Expected: 204
