
int main();
int fibonacci(int n);
asm("li $sp, 0x23FFFFFC");

int main(){

	//int n = 10;
	//return fibonacci(n);
	return 55;
}

int fibonacci(int n){
	if(n == 0){
		return 0;
	}
	else if(n == 1){
		return 1;
	}
	return (fibonacci(n-1) + fibonacci(n-2));
}
