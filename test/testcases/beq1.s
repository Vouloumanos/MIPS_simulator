.set noreorder

start:
  addiu $2, $0, 5
  addiu $3, $0, 6
  beq $2, $3, start + 20
  nop
  add $2, $2, $3
  jr $0
  nop

#Check for not branching. Expected: 11
