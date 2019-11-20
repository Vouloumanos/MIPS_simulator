
./test/temp/sb0.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c032000 	lui	v1,0x2000
10000004:	24630012 	addiu	v1,v1,18
10000008:	3c04aabb 	lui	a0,0xaabb
1000000c:	2484ccdd 	addiu	a0,a0,-13091
10000010:	2405ff05 	li	a1,-251
10000014:	ac64fffe 	sw	a0,-2(v1)
10000018:	a0650000 	sb	a1,0(v1)
1000001c:	8c62fffe 	lw	v0,-2(v1)
10000020:	00000000 	nop
10000024:	00000008 	jr	zero
10000028:	00021602 	srl	v0,v0,0x18
1000002c:	00000000 	nop
