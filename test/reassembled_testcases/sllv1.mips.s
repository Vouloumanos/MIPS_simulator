
./test/temp/sllv1.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	2442ffff 	addiu	v0,v0,-1
10000004:	2463001f 	addiu	v1,v1,31
10000008:	00621004 	sllv	v0,v0,v1
1000000c:	00000008 	jr	zero
10000010:	00621006 	srlv	v0,v0,v1
	...
