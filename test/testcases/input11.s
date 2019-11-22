lui $3, 0x3000
lw $4, 0($3)
lw $5, 0($3)
lw $2, 0($3)
srl $2, $2, 24
jr $0
nop

#EOF. Expected: 255
