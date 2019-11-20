
./test/temp/jalr3.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c031100 	lui	v1,0x1100
10000004:	20420008 	addi	v0,v0,8
10000008:	20630008 	addi	v1,v1,8
1000000c:	00601009 	jalr	v0,v1
10000010:	00000000 	nop
10000014:	20420007 	addi	v0,v0,7
10000018:	00000008 	jr	zero
1000001c:	00000000 	nop
