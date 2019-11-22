

fibonacci_pre:
lui	$sp,0x23ff
ori	$sp,$sp,0xfffc

main:
j	fibonacci
li	$a0,10

fibonacci:
addiu	$sp,$sp,-136
sw	$ra,132($sp)
sw	$s8,128($sp)
sw	$s7,124($sp)
sw	$s6,120($sp)
sw	$s5,116($sp)
sw	$s4,112($sp)
sw	$s3,108($sp)
sw	$s2,104($sp)
sw	$s1,100($sp)
beqz	$a0,fibonacci+0x4e8
sw	$s0,96($sp)
li	$v0,1
beq	$a0,$v0,fibonacci+0x4e8
addiu	$v0,$a0,-2
sw	$v0,72($sp)
addiu	$v0,$a0,-1
move	$v1,$v0
sw	$v0,88($sp)
sw	$zero,68($sp)
li	$s0,1
beqz	$v1,fibonacci+0x338
move	$v0,$v1
beq	$v1,$s0,fibonacci+0x338
nop
lw	$v1,72($sp)
sw	$zero,56($sp)
sw	$v1,76($sp)
beqz	$v1,fibonacci+0x498
move	$a0,$v1
beq	$v1,$s0,fibonacci+0x488
nop
addiu	$v0,$v0,-2
sw	$v0,92($sp)
sw	$v0,80($sp)
sw	$zero,60($sp)
lw	$v0,80($sp)
nop
beqz	$v0,fibonacci+0x47c
move	$v1,$v0
beq	$v0,$s0,fibonacci+0x46c
nop
addiu	$v0,$a0,-2
sw	$v0,84($sp)
sw	$v0,48($sp)
sw	$zero,64($sp)
lw	$a0,48($sp)
nop
beqz	$a0,fibonacci+0x460
move	$v0,$a0
beq	$a0,$s0,fibonacci+0x450
nop
addiu	$v1,$v1,-2
sw	$v1,52($sp)
sw	$v1,36($sp)
sw	$zero,44($sp)
lw	$a0,36($sp)
nop
beqz	$a0,fibonacci+0x440
move	$v1,$a0
beq	$a0,$s0,fibonacci+0x430
nop
addiu	$v0,$v0,-2
sw	$v0,40($sp)
sw	$v0,24($sp)
sw	$zero,32($sp)
lw	$a0,24($sp)
nop
beqz	$a0,fibonacci+0x424
move	$v0,$a0
beq	$a0,$s0,fibonacci+0x414
move	$s6,$zero
addiu	$v1,$v1,-2
sw	$v1,28($sp)
move	$s4,$v1
beqz	$s4,fibonacci+0x40c
move	$s5,$s4
beq	$s4,$s0,fibonacci+0x408
move	$s7,$zero
addiu	$s8,$v0,-2
move	$s3,$s8
beqz	$s3,fibonacci+0x178
move	$s1,$s3
beq	$s3,$s0,fibonacci+0x400
move	$s2,$zero
bltzal $zero,fibonacci
j	fibonacci
addiu	$a0,$s1,-1
addiu	$s1,$s1,-2
beqz	$s1,fibonacci+0x340
addu	$s2,$s2,$v0
bne	$s1,$s0,fibonacci+0x154
nop
addiu	$s2,$s2,1
addu	$s7,$s7,$s2
addiu	$s5,$s5,-2
beqz	$s5,fibonacci+0x34c
nop
bne	$s5,$s0,fibonacci+0x144
addiu	$s3,$s3,-2
addiu	$s7,$s7,1
addu	$s6,$s6,$s7
beqz	$s8,fibonacci+0x358
move	$v0,$s8
bne	$s8,$s0,fibonacci+0x12c
addiu	$s4,$s4,-2
lw	$v0,32($sp)
addiu	$s6,$s6,1
addu	$v0,$v0,$s6
sw	$v0,32($sp)
lw	$v0,28($sp)
nop
beqz	$v0,fibonacci+0x378
move	$v1,$v0
lw	$v0,24($sp)
nop
addiu	$v0,$v0,-2
sw	$v0,24($sp)
lw	$v0,28($sp)
nop
bne	$v0,$s0,fibonacci+0x108
nop
lw	$v0,32($sp)
lw	$v1,44($sp)
addiu	$v0,$v0,1
addu	$v0,$v1,$v0
lw	$v1,40($sp)
sw	$v0,44($sp)
beqz	$v1,fibonacci+0x398
move	$v0,$v1
lw	$v1,36($sp)
nop
addiu	$v1,$v1,-2
sw	$v1,36($sp)
lw	$v1,40($sp)
nop
bne	$v1,$s0,fibonacci+0xe0
nop
lw	$v0,44($sp)
lw	$v1,64($sp)
addiu	$v0,$v0,1
addu	$v0,$v1,$v0
sw	$v0,64($sp)
lw	$v0,52($sp)
nop
beqz	$v0,fibonacci+0x3bc
move	$v1,$v0
lw	$v0,48($sp)
nop
addiu	$v0,$v0,-2
sw	$v0,48($sp)
lw	$v0,52($sp)
nop
bne	$v0,$s0,fibonacci+0xb8
nop
lw	$v0,64($sp)
lw	$v1,60($sp)
addiu	$v0,$v0,1
addu	$v0,$v1,$v0
sw	$v0,60($sp)
lw	$v0,84($sp)
nop
beqz	$v0,fibonacci+0x3e0
move	$a0,$v0
lw	$v0,80($sp)
nop
addiu	$v0,$v0,-2
sw	$v0,80($sp)
lw	$v0,84($sp)
nop
bne	$v0,$s0,fibonacci+0x90
nop
lw	$v0,60($sp)
lw	$v1,56($sp)
addiu	$v0,$v0,1
addu	$v0,$v1,$v0
sw	$v0,56($sp)
lw	$v0,92($sp)
nop
beqz	$v0,fibonacci+0x2e4
nop
lw	$v1,76($sp)
nop
addiu	$v1,$v1,-2
bne	$v0,$s0,fibonacci+0x70
sw	$v1,76($sp)
lw	$v1,56($sp)
nop
addu	$v0,$v0,$v1
lw	$v1,68($sp)
nop
addu	$v0,$v1,$v0
sw	$v0,68($sp)
lw	$v0,72($sp)
nop
beqz	$v0,fibonacci+0x4e0
move	$v1,$v0
lw	$a0,88($sp)
nop
addiu	$a0,$a0,-2
addiu	$v0,$v0,-2
beq	$v1,$s0,fibonacci+0x4a4
sw	$a0,88($sp)
move	$v1,$a0
sw	$v0,72($sp)
bnez	$v1,fibonacci+0x5c
move	$v0,$v1
b	fibonacci+0x2e4
sw	$zero,56($sp)
addiu	$s5,$s5,-2
bnez	$s5,fibonacci+0x184
addu	$s7,$s7,$s2
addu	$s6,$s6,$s7
bnez	$s8,fibonacci+0x19c
move	$v0,$s8
lw	$v0,32($sp)
nop
addu	$v0,$v0,$s6
sw	$v0,32($sp)
lw	$v0,28($sp)
nop
bnez	$v0,fibonacci+0x1c4
move	$v1,$v0
lw	$v0,44($sp)
lw	$v1,32($sp)
nop
addu	$v0,$v0,$v1
lw	$v1,40($sp)
sw	$v0,44($sp)
bnez	$v1,fibonacci+0x204
move	$v0,$v1
lw	$v0,64($sp)
lw	$v1,44($sp)
nop
addu	$v0,$v0,$v1
sw	$v0,64($sp)
lw	$v0,52($sp)
nop
bnez	$v0,fibonacci+0x248
move	$v1,$v0
lw	$v0,60($sp)
lw	$v1,64($sp)
nop
addu	$v0,$v0,$v1
sw	$v0,60($sp)
lw	$v0,84($sp)
nop
bnez	$v0,fibonacci+0x28c
move	$a0,$v0
lw	$v0,56($sp)
lw	$v1,60($sp)
nop
addu	$v0,$v0,$v1
sw	$v0,56($sp)
lw	$v0,92($sp)
b	fibonacci+0x2c8
nop
b	fibonacci+0x178
addiu	$s7,$s7,1
addiu	$s6,$s6,1
b	fibonacci+0x194
addiu	$s8,$v0,-2
lw	$v0,32($sp)
nop
addiu	$v0,$v0,1
sw	$v0,32($sp)
addiu	$v0,$v1,-2
b	fibonacci+0x1bc
sw	$v0,28($sp)
lw	$v1,44($sp)
nop
addiu	$v1,$v1,1
sw	$v1,44($sp)
addiu	$v0,$v0,-2
sw	$v0,40($sp)
b	fibonacci+0x1fc
move	$v1,$v0
lw	$v0,64($sp)
nop
addiu	$v0,$v0,1
sw	$v0,64($sp)
addiu	$v0,$v1,-2
b	fibonacci+0x240
sw	$v0,52($sp)
lw	$v0,60($sp)
nop
addiu	$v0,$v0,1
sw	$v0,60($sp)
addiu	$v0,$a0,-2
b	fibonacci+0x284
sw	$v0,84($sp)
lw	$v1,56($sp)
nop
addiu	$v1,$v1,1
sw	$v1,56($sp)
addiu	$v0,$v0,-2
b	fibonacci+0x2c8
sw	$v0,92($sp)
li	$a0,1
lw	$v0,68($sp)
lw	$ra,132($sp)
lw	$s8,128($sp)
lw	$s7,124($sp)
lw	$s6,120($sp)
lw	$s5,116($sp)
lw	$s4,112($sp)
lw	$s3,108($sp)
lw	$s2,104($sp)
lw	$s1,100($sp)
lw	$s0,96($sp)
addu	$v0,$v0,$a0
jr	$ra
addiu	$sp,$sp,136
b	fibonacci+0x4a8
move	$a0,$zero
b	fibonacci+0x4a8
sw	$zero,68($sp)
