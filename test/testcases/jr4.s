.set noreorder

lui $2, 0x1000
ori $2, $2, 0x0018

jr $2
nop

jr $0
nop

addiu $2, $2, 7

jr $0
nop

#expect 31
