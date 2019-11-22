
./test/temp/lh8.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c030000 	lui	v1,0x0
10000004:	34630006 	ori	v1,v1,0x6
10000008:	8462fffe 	lh	v0,-2(v1)
1000000c:	00000000 	nop
10000010:	00000008 	jr	zero
10000014:	00021302 	srl	v0,v0,0xc
	...
