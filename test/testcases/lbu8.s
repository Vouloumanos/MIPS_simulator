lui $3, 0x1000
ori $3, $3, 0x000C
lui $4, 0xAABB
ori $4, $4, 0xCCDD
lbu $2, 3($3)
jr $zero
nop


#Check for read from instruction memory.
#Expected: 221
