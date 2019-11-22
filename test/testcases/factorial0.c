asm("li $sp, 0x23FFFFFC");
asm("j main");

int factorial(int n){
	if(n <= 1){
		return 1;
	}
	else{
		return n*factorial(n-1);
	}
}

int main(){
	int n = 5;
	return factorial(n);
}
