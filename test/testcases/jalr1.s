.set noreorder

addiu $2, $2, 7
addiu $3, $3, 7

jalr $2, $3
nop

addiu $2, $2, 7
jr $0
nop

#expect memory (245)
