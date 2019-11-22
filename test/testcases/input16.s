lui $3, 0x3000
lw $4, 0($3)
lh $2, 2($3)
srl $2, $2, 4
jr $0
nop

#Check for EOF.
#Expected: 255
