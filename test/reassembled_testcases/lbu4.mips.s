
./test/temp/lbu4.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c032300 	lui	v1,0x2300
10000004:	24630006 	addiu	v1,v1,6
10000008:	3c04a070 	lui	a0,0xa070
1000000c:	2484ccdd 	addiu	a0,a0,-13091
10000010:	ac64fffe 	sw	a0,-2(v1)
10000014:	9062fffe 	lbu	v0,-2(v1)
10000018:	00000000 	nop
1000001c:	00000008 	jr	zero
10000020:	00021102 	srl	v0,v0,0x4
	...
