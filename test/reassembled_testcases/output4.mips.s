
./test/temp/output4.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c033000 	lui	v1,0x3000
10000004:	34630004 	ori	v1,v1,0x4
10000008:	34840061 	ori	a0,a0,0x61
1000000c:	ac640003 	sw	a0,3(v1)
10000010:	00000008 	jr	zero
10000014:	34020005 	li	v0,0x5
	...
