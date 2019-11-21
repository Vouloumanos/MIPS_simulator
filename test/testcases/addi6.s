lui $2, 0xC0000
addi $2, $2, 0x8000
srl $2, $2, 28
jr r0
nop

#Check that no overflow occurs. Expected: 11
