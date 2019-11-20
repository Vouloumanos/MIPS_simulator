
./test/temp/lwr18.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c031000 	lui	v1,0x1000
10000004:	2463000c 	addiu	v1,v1,12
10000008:	3c04aabb 	lui	a0,0xaabb
1000000c:	2484ccdd 	addiu	a0,a0,-13091
10000010:	3c05eeee 	lui	a1,0xeeee
10000014:	24a5eeee 	addiu	a1,a1,-4370
10000018:	98650002 	lwr	a1,2(v1)
1000001c:	00000008 	jr	zero
10000020:	00000000 	nop
	...
