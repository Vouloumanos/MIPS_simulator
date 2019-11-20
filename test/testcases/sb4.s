lui $3, 0x1000
ori $3, $3, 0x0012
ori $5, $5, 0xFFFF
sb $5, 0($3)
jr $0
nop

#Check for store in memory location out of range. Expected: 245
