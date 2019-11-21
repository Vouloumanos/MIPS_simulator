
./test/temp/addi6.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c02c000 	lui	v0,0xc000
10000004:	20428000 	addi	v0,v0,-32768
10000008:	00000008 	jr	zero
1000000c:	00021702 	srl	v0,v0,0x1c
	...
