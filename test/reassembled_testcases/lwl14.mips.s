
./test/temp/lwl14.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c032100 	lui	v1,0x2100
10000004:	34630004 	ori	v1,v1,0x4
10000008:	3c04aabb 	lui	a0,0xaabb
1000000c:	3484ccdd 	ori	a0,a0,0xccdd
10000010:	3c05eeee 	lui	a1,0xeeee
10000014:	34a5eeee 	ori	a1,a1,0xeeee
10000018:	ac640000 	sw	a0,0(v1)
1000001c:	88650003 	lwl	a1,3(v1)
10000020:	00000000 	nop
10000024:	00000008 	jr	zero
10000028:	00051202 	srl	v0,a1,0x8
1000002c:	00000000 	nop
