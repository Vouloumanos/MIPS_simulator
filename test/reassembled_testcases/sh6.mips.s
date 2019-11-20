
./test/temp/sh6.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c031000 	lui	v1,0x1000
10000004:	34630012 	ori	v1,v1,0x12
10000008:	3c04aabb 	lui	a0,0xaabb
1000000c:	3484ccdd 	ori	a0,a0,0xccdd
10000010:	3405ff05 	li	a1,0xff05
10000014:	a4650000 	sh	a1,0(v1)
10000018:	00000008 	jr	zero
1000001c:	00021602 	srl	v0,v0,0x18
	...
