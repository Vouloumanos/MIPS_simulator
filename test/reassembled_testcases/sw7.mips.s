
./test/temp/sw7.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c031000 	lui	v1,0x1000
10000004:	34630010 	ori	v1,v1,0x10
10000008:	3c04aabb 	lui	a0,0xaabb
1000000c:	3484ccdd 	ori	a0,a0,0xccdd
10000010:	00000008 	jr	zero
10000014:	ac640000 	sw	a0,0(v1)
	...
