.set noreorder

start:
  addi $2, $0, -15
  addi $3, $0, 10
  bgezal $2, function
  nop
  add $2, $2, $31
  jr $0
  nop

function:
  jr $31
  add $2, $2, $3

#Check for linking even if not branching. Expected: 1
