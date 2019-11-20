
./test/temp/sw5.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c032000 	lui	v1,0x2000
10000004:	34630010 	ori	v1,v1,0x10
10000008:	3c04aabb 	lui	a0,0xaabb
1000000c:	3484ccdd 	ori	a0,a0,0xccdd
10000010:	00000008 	jr	zero
10000014:	ac640002 	sw	a0,2(v1)
	...
