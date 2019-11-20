
./test/temp/bgezal1.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <start>:
10000000:	20020000 	addi	v0,zero,0
10000004:	2003000a 	addi	v1,zero,10
10000008:	04510003 	bgezal	v0,10000018 <function>
1000000c:	00000000 	nop
10000010:	00000008 	jr	zero
10000014:	00000000 	nop

10000018 <function>:
10000018:	03e00008 	jr	ra
1000001c:	00431020 	add	v0,v0,v1
