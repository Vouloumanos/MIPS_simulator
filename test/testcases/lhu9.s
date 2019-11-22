lui $3, 0x3000
ori $3, $3, 0x0006
lhu $2, -2($3)
srl $2, $2, 12
jr $zero
nop


#Check for read from write-only address(memory exception).
#Expected: 245
