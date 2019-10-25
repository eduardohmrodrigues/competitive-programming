#include <iostream>
#include <cstdio>

int main(){
	int x, y;
	std::cin >> x;

	for(int i=0; i<x; i++){
		std::cin >> y;
		if(y == 0){
			std::cout << "NULL" << std::endl;
		}else{
			if(y%2 == 0){
				std::cout << "EVEN ";
			}else{
				std::cout << "ODD ";
			}

			if(y > 0){
				std::cout << "POSITIVE" << std::endl;
			}else{
				std::cout << "NEGATIVE" << std::endl;
			}
		}
	}

	return 0;
}
