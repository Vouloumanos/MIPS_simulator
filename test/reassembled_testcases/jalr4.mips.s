
./test/temp/jalr4.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c031000 	lui	v1,0x1000
10000004:	34630018 	ori	v1,v1,0x18
10000008:	00601009 	jalr	v0,v1
1000000c:	00000000 	nop
10000010:	00000008 	jr	zero
10000014:	00000000 	nop
10000018:	24420007 	addiu	v0,v0,7
1000001c:	00000008 	jr	zero
10000020:	00000000 	nop
	...
