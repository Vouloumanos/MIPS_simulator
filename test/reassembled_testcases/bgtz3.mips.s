
./test/temp/bgtz3.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <start>:
10000000:	24020005 	li	v0,5
10000004:	24030005 	li	v1,5
10000008:	1c400004 	bgtz	v0,1000001c <start+0x1c>
1000000c:	00000000 	nop
10000010:	00431020 	add	v0,v0,v1
10000014:	00000008 	jr	zero
10000018:	00000000 	nop
1000001c:	1c40fffd 	bgtz	v0,10000014 <start+0x14>
10000020:	00000000 	nop
	...
