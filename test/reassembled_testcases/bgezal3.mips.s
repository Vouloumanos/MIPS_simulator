
./test/temp/bgezal3.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <start>:
10000000:	2002fff1 	addi	v0,zero,-15
10000004:	2003000a 	addi	v1,zero,10
10000008:	04510004 	bgezal	v0,1000001c <function>
1000000c:	00000000 	nop
10000010:	005f1020 	add	v0,v0,ra
10000014:	00000008 	jr	zero
10000018:	00000000 	nop

1000001c <function>:
1000001c:	03e00008 	jr	ra
10000020:	00431020 	add	v0,v0,v1
	...
