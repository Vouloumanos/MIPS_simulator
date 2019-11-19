
./test/temp/mult8.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c038000 	lui	v1,0x8000
10000004:	20420002 	addi	v0,v0,2
10000008:	00620018 	mult	v1,v0
1000000c:	00001010 	mfhi	v0
10000010:	00000008 	jr	zero
10000014:	00000000 	nop
	...
