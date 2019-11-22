lui $3, 0x3000
lh $2, 2($3)
srl $2, $2, 4
jr $0
nop

#Check for character g and that the rest of the memory location is zero using lh.
#Expected: 8
