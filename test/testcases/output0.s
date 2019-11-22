lui $3, 0x3000
ori $3, $3, 0x0004
ori $4, $4, 0x61
sw $4, 0($3)
ori $2, $2, 5
jr $0
nop

#Output character a. Expected: 5
