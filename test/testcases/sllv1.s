
addi $2, $2, -1
addi $3, $3, 31

sllv $2, $2, $3
srlv $2, $2, $3

jr $0
nop

#expect 1
