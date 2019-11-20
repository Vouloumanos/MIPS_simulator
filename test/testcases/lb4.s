lui $3, 0x2300
ori $3, $3, 0x0006
lui $4, 0xA070
ori $4, $4, 0xCCDD
sw $4, -2($3)
lb $2, -2($3)
srl $2, $2, 4
jr $zero
nop


#Check for sign extension. Expected: 250
