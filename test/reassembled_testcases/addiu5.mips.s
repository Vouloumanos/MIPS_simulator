
./test/temp/addiu5.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c038000 	lui	v1,0x8000
10000004:	24628000 	addiu	v0,v1,-32768
10000008:	00000008 	jr	zero
1000000c:	00021602 	srl	v0,v0,0x18
