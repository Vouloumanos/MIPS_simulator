
./test/temp/input20.mips.elf:     file format elf32-tradbigmips


Disassembly of section .text:

10000000 <.text>:
10000000:	3c033000 	lui	v1,0x3000
10000004:	80650003 	lb	a1,3(v1)
10000008:	80660001 	lb	a2,1(v1)
1000000c:	80640000 	lb	a0,0(v1)
10000010:	00000000 	nop
10000014:	00000008 	jr	zero
10000018:	00641020 	add	v0,v1,a0
1000001c:	00000000 	nop
