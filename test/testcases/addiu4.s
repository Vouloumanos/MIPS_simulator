lui $3, 0x7FFF
ori $3, $3, 0xFFFF
addi $3, $3, 0x4000
jr $0

#Check for positive overflow (arithmetic exception). Expected: 246
