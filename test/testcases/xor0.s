
addiu $2, $2, 0b10101100
addiu $3, $3, 0b10100010

xor $2, $2, $3

jr $0
nop

#expect 0b00001110 (14)
