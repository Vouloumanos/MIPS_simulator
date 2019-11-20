lui $3, 0x3000
ori $3, $3, 0x000C
lwr $5, 0($3)
jr $zero
nop


#Check for read from memory location outside the range (memory exception).
#Expected: 245
