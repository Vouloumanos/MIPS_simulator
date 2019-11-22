.set noreorder

start:
  addiu $2, $0, 5
  addiu $3, $0, 5
  bgtz $2, start + 28
  nop
  add $2, $2, $3
  jr $0
  nop

  bgtz $2, start + 20
  nop

#Check for branching with negative offset. Expected: 5
