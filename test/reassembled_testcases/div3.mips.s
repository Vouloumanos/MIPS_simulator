
./test/temp/div3.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c03ffff 	lui	v1,0xffff
10000004:	2063ffff 	addi	v1,v1,-1
10000008:	2084ffff 	addi	a0,a0,-1
1000000c:	14800002 	bnez	a0,0x10000018
10000010:	0064001a 	div	zero,v1,a0
10000014:	0007000d 	break	0x7
10000018:	2401ffff 	li	at,-1
1000001c:	14810004 	bne	a0,at,0x10000030
10000020:	3c018000 	lui	at,0x8000
10000024:	14610002 	bne	v1,at,0x10000030
10000028:	00000000 	nop
1000002c:	0006000d 	break	0x6
10000030:	00001812 	mflo	v1
10000034:	00001012 	mflo	v0
10000038:	00000008 	jr	zero
1000003c:	00000000 	nop
	...
