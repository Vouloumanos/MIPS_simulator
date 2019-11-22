.set noreorder

start:
  addiu $2, $0, 6
  addiu $3, $0, 5
  bne $2, start + 28
  nop
  add $2, $2, $3
  jr $0
  nop

  bne $2, start + 20
  nop

#Check for branching with negative offset. Expected: 6
