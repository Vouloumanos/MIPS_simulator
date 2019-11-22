lui $3, 0x0000
ori $3, $3, 0x0006
lh $2, -2($3)
srl $2, $2, 12
jr $zero
nop


#Check for read from memory location outside the range (memory exception).
#Expected: 245
