lui $3, 0xC000
addiu $2, $3, 0x8000
srl $2, $2, 28
jr $0
nop

#Check that no overflow occurs. Expected: 11
