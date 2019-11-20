
./test/temp/divu1.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	2463000a 	addiu	v1,v1,10
10000004:	24840003 	addiu	a0,a0,3
10000008:	14800002 	bnez	a0,0x10000014
1000000c:	0064001b 	divu	zero,v1,a0
10000010:	0007000d 	break	0x7
10000014:	00001812 	mflo	v1
10000018:	00001010 	mfhi	v0
1000001c:	00000008 	jr	zero
10000020:	00000000 	nop
	...
