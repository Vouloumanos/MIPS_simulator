
./test/temp/sh7.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c033000 	lui	v1,0x3000
10000004:	24630002 	addiu	v1,v1,2
10000008:	3c04aabb 	lui	a0,0xaabb
1000000c:	2484ccdd 	addiu	a0,a0,-13091
10000010:	2405ff05 	li	a1,-251
10000014:	a4650000 	sh	a1,0(v1)
10000018:	00000008 	jr	zero
1000001c:	00021602 	srl	v0,v0,0x18
	...
