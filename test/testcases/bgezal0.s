.set noreorder

start:
  addi $2, $0, 10
  addi $3, $0, 10
  bgezal $2, function
  nop
  jr $0
  nop

function:
  jr $31
  add $2, $2, $3

#Check for branching at positive. Expected: 20
