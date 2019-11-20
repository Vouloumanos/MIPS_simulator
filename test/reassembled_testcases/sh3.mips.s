
./test/temp/sh3.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c032000 	lui	v1,0x2000
10000004:	34630012 	ori	v1,v1,0x12
10000008:	3c04aabb 	lui	a0,0xaabb
1000000c:	3484ccdd 	ori	a0,a0,0xccdd
10000010:	34050705 	li	a1,0x705
10000014:	ac64fffe 	sw	a0,-2(v1)
10000018:	a4650000 	sh	a1,0(v1)
1000001c:	8c62fffe 	lw	v0,-2(v1)
10000020:	00000008 	jr	zero
10000024:	00000000 	nop
	...
