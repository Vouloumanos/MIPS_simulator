lui $3, 0x3000
ori $3, $3, 0x0004
ori $2, $2, 0x61
sb $2, 3($3)
jr $0
nop

#Check for output character a using lb. Expected: 97
