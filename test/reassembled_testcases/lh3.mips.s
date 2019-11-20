
./test/temp/lh3.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c032200 	lui	v1,0x2200
10000004:	34630006 	ori	v1,v1,0x6
10000008:	3c04a0bb 	lui	a0,0xa0bb
1000000c:	348470dd 	ori	a0,a0,0x70dd
10000010:	ac64fffe 	sw	a0,-2(v1)
10000014:	84620000 	lh	v0,0(v1)
10000018:	00000008 	jr	zero
1000001c:	00000000 	nop
	...
