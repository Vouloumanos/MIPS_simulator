
./test/temp/divu7.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c03c000 	lui	v1,0xc000
10000004:	24420001 	addiu	v0,v0,1
10000008:	14600002 	bnez	v1,0x10000014
1000000c:	0043001b 	divu	zero,v0,v1
10000010:	0007000d 	break	0x7
10000014:	00001012 	mflo	v0
10000018:	00001010 	mfhi	v0
1000001c:	00000008 	jr	zero
10000020:	00021602 	srl	v0,v0,0x18
	...
