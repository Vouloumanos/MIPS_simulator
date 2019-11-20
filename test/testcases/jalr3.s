.set noreorder

lui $3, 0x1100
ori $3, $3, 8
addiu $2, $2, 8


jalr $2, $3
nop

addiu $2, $2, 7
jr $0
nop

#expect memory (245)
