start:
  addi $3, $3, 0x4000
  beq $0, $0, start

#Check that no arithmetic overflow is produced. Expect memory exception: 245
