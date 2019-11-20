.set noreorder

start:
  addi $2, $0, 10
  addi $3, $0, 10
  bne $2, $3, start + 20
  nop
  add $2, $2, $3
  jr $0
  nop

#Check for not branching. Expected: 20
