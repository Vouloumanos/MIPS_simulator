
./test/temp/sw8.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c033000 	lui	v1,0x3000
10000004:	34630000 	ori	v1,v1,0x0
10000008:	3c04aabb 	lui	a0,0xaabb
1000000c:	3484ccdd 	ori	a0,a0,0xccdd
10000010:	00000008 	jr	zero
10000014:	ac640000 	sw	a0,0(v1)
	...
