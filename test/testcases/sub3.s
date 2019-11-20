
lui $2, 0x7FFF
ori $2, $2, 0xFFFF
lui $3, 0x8000

sub $2, $2, $3

jr $0
nop

#expect arithmetic (246)
