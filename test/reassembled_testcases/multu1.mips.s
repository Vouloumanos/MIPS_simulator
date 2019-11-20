
./test/temp/multu1.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	24630003 	addiu	v1,v1,3
10000004:	24420004 	addiu	v0,v0,4
10000008:	00620019 	multu	v1,v0
1000000c:	00001010 	mfhi	v0
10000010:	00000008 	jr	zero
10000014:	00000000 	nop
	...
