
./test/temp/sb4.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c031000 	lui	v1,0x1000
10000004:	24630012 	addiu	v1,v1,18
10000008:	24a5ffff 	addiu	a1,a1,-1
1000000c:	00000008 	jr	zero
10000010:	a0650000 	sb	a1,0(v1)
	...
