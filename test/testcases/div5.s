
addi $3, $3, -1
addi $4, $4, -2

div $3, $4

mfhi $2

jr $0
nop

#expect -1 (255)
