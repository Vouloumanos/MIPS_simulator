
./test/temp/bne1.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <start>:
10000000:	2002000a 	addi	v0,zero,10
10000004:	2003000a 	addi	v1,zero,10
10000008:	14430002 	bne	v0,v1,10000014 <start+0x14>
1000000c:	00000000 	nop
10000010:	00431020 	add	v0,v0,v1
10000014:	00000008 	jr	zero
10000018:	00000000 	nop
1000001c:	00000000 	nop
