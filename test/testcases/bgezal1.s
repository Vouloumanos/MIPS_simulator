.set noreorder

start:
  addi $2, $0, 0
  addi $3, $0, 10
  bgezal $2, function
  nop
  jr $0
  nop

function:
  jr $31
  add $2, $2, $3

#Check for branching at zero. Expected: 10
