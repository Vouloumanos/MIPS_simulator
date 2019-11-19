
./test/temp/divu2.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	2063000a 	addi	v1,v1,10
10000004:	14000002 	bnez	zero,0x10000010
10000008:	0060001b 	divu	zero,v1,zero
1000000c:	0007000d 	break	0x7
10000010:	00001812 	mflo	v1
10000014:	00001012 	mflo	v0
10000018:	00000008 	jr	zero
1000001c:	00000000 	nop
	...
