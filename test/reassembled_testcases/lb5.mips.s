
./test/temp/lb5.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c032300 	lui	v1,0x2300
10000004:	34630006 	ori	v1,v1,0x6
10000008:	3c04a070 	lui	a0,0xa070
1000000c:	3484ccdd 	ori	a0,a0,0xccdd
10000010:	ac64fffe 	sw	a0,-2(v1)
10000014:	8062ffff 	lb	v0,-1(v1)
10000018:	00000000 	nop
1000001c:	00000008 	jr	zero
10000020:	00021102 	srl	v0,v0,0x4
	...
