#include <iostream>
#include <cstdio>

int main(){
	int x, y, s = 0;
	std::cin >> x >> y;
	if(x > y){
		int temp = x;
		x = y;
		y = temp;
	}

	for(int i=x+1; i<y; i+=1){
		if(i%2 != 0){
			s+= i;
		}
	}

	std::cout << s << std::endl;
	return 0;
}

