.set noreorder

start:
  addi $2, $0, -5
  addi $3, $0, 5
  blez $2, start + 28
  nop
  add $2, $2, $3
  jr $0
  nop

  blez $2, start + 20
  nop

#Check for branching with negative offset. Expected: 251
