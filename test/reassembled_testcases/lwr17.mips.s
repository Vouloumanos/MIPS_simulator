
./test/temp/lwr17.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c033000 	lui	v1,0x3000
10000004:	24630004 	addiu	v1,v1,4
10000008:	98650000 	lwr	a1,0(v1)
1000000c:	00000008 	jr	zero
10000010:	00000000 	nop
	...
