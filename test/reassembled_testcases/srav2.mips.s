
./test/temp/srav2.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c028000 	lui	v0,0x8000
10000004:	34420007 	ori	v0,v0,0x7
10000008:	24630020 	addiu	v1,v1,32
1000000c:	00000008 	jr	zero
10000010:	00621007 	srav	v0,v0,v1
	...
