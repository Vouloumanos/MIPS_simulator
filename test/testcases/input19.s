lui $3, 0x3000
lh $4, 0($3)
lw $2, 0($3)
jr $0
nop

#Check that the character is consumed using lh even if the load address is not 0x30000002.
#Expected: 97
