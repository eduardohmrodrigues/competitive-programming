#include <iostream>
#include <cstdio>

int main(){
	int x;
	std::cin >> x;

	for(int i=2; i<=x; i+=2){
		std::cout << i << "^2 = " << i*i << std::endl;
	}

	return 0;
}
