lui $3, 0x3000
lb $4, 0($3)
lw $2, 0($3)
jr $0
nop

#Check that the character is consumed using lb even if the load address is not 0x30000003.
#Expected: 97
