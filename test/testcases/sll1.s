
addiu $2, $2, -1

sll $2, $2, 31
srl $2, $2, 31

jr $0
nop

#expect 1
