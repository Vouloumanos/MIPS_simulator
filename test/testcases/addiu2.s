addiu $2 , $0 , 0xA000
srl $2, $2, 12
jr $0
nop

#Check for no sign extension. Expected: 250
