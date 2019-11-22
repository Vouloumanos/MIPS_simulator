
./test/temp/input12.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c033000 	lui	v1,0x3000
10000004:	8c640000 	lw	a0,0(v1)
10000008:	8c650000 	lw	a1,0(v1)
1000000c:	00000000 	nop
10000010:	00000008 	jr	zero
10000014:	00851020 	add	v0,a0,a1
	...
