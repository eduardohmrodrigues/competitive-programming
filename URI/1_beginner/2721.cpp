#include <cstdio>
#include <iostream>

int main(){
	int x, sum = 0;
	std::string d[] = {"Rudolph", "Dasher", "Dancer", "Prancer", "Vixen", "Comet", "Cupid", "Donner", "Blitzen"};
	
	for(int i=0; i<9; ++i){
		scanf("%d", &x);
		sum += x;
	}

	std::cout << d[sum%9] << std::endl;
	return 0;
}
