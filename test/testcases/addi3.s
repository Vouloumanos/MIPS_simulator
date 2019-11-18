start:
  addi $3, $3, 0x4000
  beq $0, $0, start

#Infinite loop to check for arithmetic overflow, Expected: 246
