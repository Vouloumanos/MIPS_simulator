asm("li $sp, 0x23FFFFFC");
asm("j main");

int fibonacci(int n){
	if(n == 0){
		return 0;
	}
	else if(n == 1){
		return 1;
	}
	return (fibonacci(n-1) + fibonacci(n-2));
}

int main(){
	int n = 10;
	return fibonacci(n);
}
