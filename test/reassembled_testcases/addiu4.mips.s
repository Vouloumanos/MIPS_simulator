
./test/temp/addiu4.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c037fff 	lui	v1,0x7fff
10000004:	3463ffff 	ori	v1,v1,0xffff
10000008:	24624000 	addiu	v0,v1,16384
1000000c:	00000008 	jr	zero
10000010:	00021702 	srl	v0,v0,0x1c
	...
