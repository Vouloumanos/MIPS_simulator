
./test/temp/srlv2.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c028000 	lui	v0,0x8000
10000004:	20420007 	addi	v0,v0,7
10000008:	20630020 	addi	v1,v1,32
1000000c:	00000008 	jr	zero
10000010:	00621006 	srlv	v0,v0,v1
	...
