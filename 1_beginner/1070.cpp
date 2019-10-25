#include <iostream>
#include <cstdio>

int main(){
	int x, c = 0;
	std::cin >> x;

	for(int i=x; c < 6 && i<=x+12; i+=1){
		if(i%2 != 0){
			std::cout << i << std::endl;
			c++;
		}
	}

	return 0;
}
