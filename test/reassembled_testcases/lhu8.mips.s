
./test/temp/lhu8.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c030000 	lui	v1,0x0
10000004:	24630006 	addiu	v1,v1,6
10000008:	3c04a0bb 	lui	a0,0xa0bb
1000000c:	248470dd 	addiu	a0,a0,28893
10000010:	ac64fffe 	sw	a0,-2(v1)
10000014:	9462fffe 	lhu	v0,-2(v1)
10000018:	00000000 	nop
1000001c:	00000008 	jr	zero
10000020:	00021302 	srl	v0,v0,0xc
	...
