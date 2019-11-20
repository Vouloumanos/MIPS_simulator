
./test/temp/lw9.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c031000 	lui	v1,0x1000
10000004:	2463000c 	addiu	v1,v1,12
10000008:	3c04aabb 	lui	a0,0xaabb
1000000c:	2484ccdd 	addiu	a0,a0,-13091
10000010:	8c620000 	lw	v0,0(v1)
10000014:	00000008 	jr	zero
10000018:	00000000 	nop
1000001c:	00000000 	nop
