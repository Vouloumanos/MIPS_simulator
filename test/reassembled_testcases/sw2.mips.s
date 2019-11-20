
./test/temp/sw2.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c032000 	lui	v1,0x2000
10000004:	34630010 	ori	v1,v1,0x10
10000008:	3c04aabb 	lui	a0,0xaabb
1000000c:	3484ccdd 	ori	a0,a0,0xccdd
10000010:	ac640000 	sw	a0,0(v1)
10000014:	8c620000 	lw	v0,0(v1)
10000018:	00000000 	nop
1000001c:	00000008 	jr	zero
10000020:	00021202 	srl	v0,v0,0x8
	...
