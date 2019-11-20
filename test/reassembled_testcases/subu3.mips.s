
./test/temp/subu3.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c027fff 	lui	v0,0x7fff
10000004:	2042ffff 	addi	v0,v0,-1
10000008:	3c038000 	lui	v1,0x8000
1000000c:	00000008 	jr	zero
10000010:	00431023 	subu	v0,v0,v1
	...
