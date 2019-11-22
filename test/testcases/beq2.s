.set noreorder

start:
  addiu $2, $0, 5
  addiu $3, $0, 5
  beq $2, $3, start + 28
  nop
  add $2, $2, $3
  jr $0
  nop

  beq $2, $3, start + 20

#Check for not branching. Expected: 5
