#include <cstdio>
#include <iostream>

int main(){
	std::string op;
	float sum = 0, t = 0, x;

	std::cin >> op;

	for(int i=0; i<12; ++i){
		for(int j=0; j<12; ++j){
			std::cin >> x;

			if(j > (11 - i)){
				sum += x;
				++t;
			}
		}
	}

	if(op[0] == 'S') printf("%.1f\n", sum);
	else printf("%.1f\n", sum/t);

	return 0;
}
