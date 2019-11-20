.set noreorder

lui $2, 0x1100
addiu $2, $2, 8

jr $2
nop

addiu $2, $2, 7
jr $0
nop

#expect memory (245)
