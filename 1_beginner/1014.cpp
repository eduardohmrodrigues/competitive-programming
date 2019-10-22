#include <iostream>
#include <cstdio>

int main(){
	int distance;
	float fuel;

	std::cin >> distance;
	std::cin >> fuel;

	printf("%.3f km/l\n", (((float)distance)/fuel));

	return 0;
}
