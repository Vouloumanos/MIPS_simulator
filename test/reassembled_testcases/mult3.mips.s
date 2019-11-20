
./test/temp/mult3.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	2463fffd 	addiu	v1,v1,-3
10000004:	24420005 	addiu	v0,v0,5
10000008:	00620018 	mult	v1,v0
1000000c:	00001012 	mflo	v0
10000010:	00000008 	jr	zero
10000014:	00000000 	nop
	...
