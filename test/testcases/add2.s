
lui $3, 0x8000
lui $4, 0x8000

add $2, $4, $4

jr $0
nop

#expect overflow (246)
