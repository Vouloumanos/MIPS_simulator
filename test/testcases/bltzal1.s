.set noreorder

start:
  addi $2, $0, 10
  addi $3, $0, 10
  bltzal $2, function
  nop
  jr $0
  nop

function:
  jr $31
  add $2, $2, $3

#Check for not branching at positive. Expected: 10
