
./test/temp/divu5.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c038000 	lui	v1,0x8000
10000004:	24420002 	addiu	v0,v0,2
10000008:	14400002 	bnez	v0,0x10000014
1000000c:	0062001b 	divu	zero,v1,v0
10000010:	0007000d 	break	0x7
10000014:	00001812 	mflo	v1
10000018:	00001012 	mflo	v0
1000001c:	00000008 	jr	zero
10000020:	00021602 	srl	v0,v0,0x18
	...
