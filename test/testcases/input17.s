lui $3, 0x3000
lb $2, 3($3)
srl $2, $2, 4
jr $0
nop

#Check for character a and that the rest of the memory location is zero.
#Expected: 6
