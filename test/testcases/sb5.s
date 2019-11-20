lui $3, 0x3000
ori $3, $3, 0x0003
ori $5, $5, 0xFFFF
sb $5, 0($3)
jr $0
nop

#Check for store in read-only location. Expected: 245
