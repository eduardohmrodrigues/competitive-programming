#include <iostream>
#include <cstdio>

int main(){
	int time, distance;
	
	std::cin >> time;
	std::cin >> distance;

	printf("%.3f\n", time*distance/12.0);	
	return 0;
}
