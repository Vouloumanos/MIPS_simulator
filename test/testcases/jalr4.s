.set noreorder

lui $3, 0x1000
ori $3, $3, 0x0018

jalr $2, $3
nop

jr $0
nop

addiu $2, $2, 7

jr $0
nop

#expect 23
