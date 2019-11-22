asm("li $sp, 0x23FFFFFC");

int fibonacci(int n);

//int main();
//int add();

int main(){

	int n = 10;
	// int result = fibonacci(n);
	// asm("")
	//return 55;
	return fibonacci(n);
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


// int add(){
// return 7;
// }
