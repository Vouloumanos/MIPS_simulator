
./test/temp/lbu6.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c031000 	lui	v1,0x1000
10000004:	34630006 	ori	v1,v1,0x6
10000008:	3c04a070 	lui	a0,0xa070
1000000c:	3484ccdd 	ori	a0,a0,0xccdd
10000010:	ac64fffe 	sw	a0,-2(v1)
10000014:	9062fffe 	lbu	v0,-2(v1)
10000018:	00000008 	jr	zero
1000001c:	00000000 	nop
	...
