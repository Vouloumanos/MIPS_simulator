.set noreorder

start:
  addi $2, $0, -25
  addi $3, $0, 10
  bltz $2, start + 20
  nop
  add $2, $2, $3
  jr $0
  nop

#Check for branching. Expected: 231
