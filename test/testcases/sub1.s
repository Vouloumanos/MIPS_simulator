
addiu $2, $2, -1
addiu $3, $3, 1

sub $2, $2, $3

jr $0
nop

#expect -2 (254)
