lui $3, 0x8000
addiu $2, $3, 0x8000
srl $2, $2, 28
jr $0

#Check for no negative overflow. Expected: 7
