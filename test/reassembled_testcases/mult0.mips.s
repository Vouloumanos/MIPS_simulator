
./test/temp/mult0.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	20630003 	addi	v1,v1,3
10000004:	20840004 	addi	a0,a0,4
10000008:	00640018 	mult	v1,a0
1000000c:	00001012 	mflo	v0
10000010:	00000008 	jr	zero
10000014:	00000000 	nop
	...
