#include <iostream>
#include <cstdio>

int main(){
	int x;
	std::cin >> x;

	for(int i=1; i<=x; i+=2){
		std::cout << i << std::endl;
	}

	return 0;
}

