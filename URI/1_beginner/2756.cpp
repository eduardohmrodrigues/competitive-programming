#include <iostream>

void printer(int x, char p){
	int spaces = 7;

	for(int i=0; i<x; ++i) std::cout << " ";
	std::cout << p;

	if(x != spaces){
		int diff = spaces-x;
		diff = (diff - 1)*2 + 1;
		for(int i=0; i<diff; ++i) std::cout << " ";
		std::cout << p;
	}

	std::cout << std::endl;
}

int main(){
	printer(7, 'A');
	printer(6, 'B');
	printer(5, 'C');
	printer(4, 'D');
	printer(3, 'E');
	printer(4, 'D');
	printer(5, 'C');
	printer(6, 'B');
	printer(7, 'A');
	
	return 0;
}
