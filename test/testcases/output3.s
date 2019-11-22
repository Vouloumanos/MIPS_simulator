lui $3, 0x3000
ori $3, $3, 0x0004
ori $4, $4, 0x61
sw $4, 2($3)
ori $2, $0, 5
jr $0
nop

#Check for store to unalinged memory location(memory exception).
#Expected: 245
