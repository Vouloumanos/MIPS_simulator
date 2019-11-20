
./test/temp/lw1.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c032100 	lui	v1,0x2100
10000004:	34630006 	ori	v1,v1,0x6
10000008:	3c04aabb 	lui	a0,0xaabb
1000000c:	3484ccdd 	ori	a0,a0,0xccdd
10000010:	ac64fffe 	sw	a0,-2(v1)
10000014:	8c62fffe 	lw	v0,-2(v1)
10000018:	00000000 	nop
1000001c:	00000008 	jr	zero
10000020:	00021402 	srl	v0,v0,0x10
	...
