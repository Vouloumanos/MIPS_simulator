lui $3, 0x7FFF
ori $3, $3, 0xFFFF
addiu $2, $3, 0x4000
srl $2, $2, 24
jr $0

#Check for no positive overflow. Expected: 8
