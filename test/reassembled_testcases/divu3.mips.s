
./test/temp/divu3.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c03ffff 	lui	v1,0xffff
10000004:	2063ffff 	addi	v1,v1,-1
10000008:	2084ffff 	addi	a0,a0,-1
1000000c:	14800002 	bnez	a0,0x10000018
10000010:	0064001b 	divu	zero,v1,a0
10000014:	0007000d 	break	0x7
10000018:	00001812 	mflo	v1
1000001c:	00001012 	mflo	v0
10000020:	00000008 	jr	zero
10000024:	00000000 	nop
	...
