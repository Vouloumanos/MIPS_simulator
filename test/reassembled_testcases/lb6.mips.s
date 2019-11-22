
./test/temp/lb6.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c032400 	lui	v1,0x2400
10000004:	34630006 	ori	v1,v1,0x6
10000008:	8062fffe 	lb	v0,-2(v1)
1000000c:	00000008 	jr	zero
10000010:	00000000 	nop
	...
