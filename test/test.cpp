#include <stdio.h>
#include <iostream>
int main(){

	char c = getchar();
	if(std::cin.eof()){
		c = 0xff;;
	}
	
	uint32_t p = 0xFFFF0061;
	putchar(c);
	std::cout << std::endl;
	putchar(p);
	std::cout << std::endl;

	return 0;

}
