#include <iostream>
#include <cstdio>

int main(){
	float f;
	std::cin >> f;

	if(f < 0 || f > 100){
		std::cout << "Fora de intervalo" << std::endl;
	}else if (f >= 0 && f <= 25){
		std::cout << "Intervalo [0,25]" << std::endl;
	}else if (f > 25 && f <= 50){
		std::cout << "Intervalo (25,50]" << std::endl;
	}else if (f > 50 && f <= 75){
		std::cout << "Intervalo (50,75]" << std::endl;
	}else{
		std::cout << "Intervalo (75,100]" << std::endl;
	}

	return 0;
}
