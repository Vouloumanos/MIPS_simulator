.set noreorder

start:
  addiu $2, $0, 5
  addiu $3, $0, 5
  beq $2, $3, start + 20
  nop
  add $2, $2, $3
  jr $0
  nop

#Check for branching. Expected 5
