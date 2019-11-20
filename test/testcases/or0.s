
addiu $3, $3, 0b10101100
addiu $2, $2, 0b00000011

or $2, $2, $3

jr $0
nop

#expect 0b10101111 (175)
