lui $3, 0x3000
ori $3, $3, 0x0004
ori $2, $2, 0x61
sw $2, 0($3)
jr $0
nop

#Output character a. Expected: 97
