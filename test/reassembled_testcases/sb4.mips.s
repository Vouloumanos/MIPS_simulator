
./test/temp/sb4.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c031000 	lui	v1,0x1000
10000004:	34630012 	ori	v1,v1,0x12
10000008:	34a5ffff 	ori	a1,a1,0xffff
1000000c:	00000008 	jr	zero
10000010:	a0650000 	sb	a1,0(v1)
	...
