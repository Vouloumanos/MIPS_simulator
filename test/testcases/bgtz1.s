.set noreorder

start:
  addi $2, $0, -25
  addi $3, $0, 10
  bgtz $2, start + 20
  nop
  add $2, $2, $3
  jr $0
  nop

#Check for not branching at negative. Expected: 241
