
./test/temp/divu3.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	2463ffff 	addiu	v1,v1,-1
10000004:	2484ffff 	addiu	a0,a0,-1
10000008:	14800002 	bnez	a0,0x10000014
1000000c:	0064001b 	divu	zero,v1,a0
10000010:	0007000d 	break	0x7
10000014:	00001812 	mflo	v1
10000018:	00001012 	mflo	v0
1000001c:	00000008 	jr	zero
10000020:	00000000 	nop
	...
