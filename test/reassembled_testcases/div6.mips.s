
./test/temp/div6.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c038000 	lui	v1,0x8000
10000004:	24420002 	addiu	v0,v0,2
10000008:	14400002 	bnez	v0,0x10000014
1000000c:	0062001a 	div	zero,v1,v0
10000010:	0007000d 	break	0x7
10000014:	2401ffff 	li	at,-1
10000018:	14410004 	bne	v0,at,0x1000002c
1000001c:	3c018000 	lui	at,0x8000
10000020:	14610002 	bne	v1,at,0x1000002c
10000024:	00000000 	nop
10000028:	0006000d 	break	0x6
1000002c:	00001812 	mflo	v1
10000030:	00001012 	mflo	v0
10000034:	00000008 	jr	zero
10000038:	00021602 	srl	v0,v0,0x18
1000003c:	00000000 	nop
