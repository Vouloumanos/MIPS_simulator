
./test/temp/output1.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c033000 	lui	v1,0x3000
10000004:	34630004 	ori	v1,v1,0x4
10000008:	3c04aabb 	lui	a0,0xaabb
1000000c:	3484ff61 	ori	a0,a0,0xff61
10000010:	ac640000 	sw	a0,0(v1)
10000014:	00000008 	jr	zero
10000018:	34420005 	ori	v0,v0,0x5
1000001c:	00000000 	nop
