start:
  addiu $2, $0, 0
  addiu $3, $0, 6
  bgez $2, start + 20
  nop
  add $2, $2, $3
  jr $0
  nop

#Check for branching when equal 0. Expected: 0
