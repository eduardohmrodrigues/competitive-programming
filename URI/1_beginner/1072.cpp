#include <iostream>
#include <cstdio>

int main(){
	int x, y, in = 0, out = 0;
	std::cin >> x;

	for(int i=0; i<x; i++){
		std::cin >> y;

		if(y >= 10 && y <= 20){
			in++;
		}else{
			out++;
		}
	}

	std::cout << in << " in" << std::endl;
	std::cout << out << " out" << std::endl;
	return 0;
}
