lui $3, 0x3000
ori $3, $3, 0x0004
ori $2, $2, 0x61
sw $2, 1($3)
jr $0
nop

#Check for store to unalinged memory location(memory exception).
#Expected: 245
