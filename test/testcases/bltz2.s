.set noreorder

start:
  addi $2, $0, 0
  addi $3, $0, 10
  bltz $2, start + 20
  nop
  add $2, $2, $3
  jr $0
  nop

#Check for not branching at 0. Expected: 10
