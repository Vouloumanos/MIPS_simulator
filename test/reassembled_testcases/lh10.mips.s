
./test/temp/lh10.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c031000 	lui	v1,0x1000
10000004:	3463000c 	ori	v1,v1,0xc
10000008:	3c04aabb 	lui	a0,0xaabb
1000000c:	3484ccdd 	ori	a0,a0,0xccdd
10000010:	84620000 	lh	v0,0(v1)
10000014:	00000000 	nop
10000018:	00000008 	jr	zero
1000001c:	00021202 	srl	v0,v0,0x8
	...
