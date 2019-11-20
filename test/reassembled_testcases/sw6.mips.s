
./test/temp/sw6.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c032000 	lui	v1,0x2000
10000004:	24630010 	addiu	v1,v1,16
10000008:	3c04aabb 	lui	a0,0xaabb
1000000c:	2484ccdd 	addiu	a0,a0,-13091
10000010:	00000008 	jr	zero
10000014:	ac640003 	sw	a0,3(v1)
	...
