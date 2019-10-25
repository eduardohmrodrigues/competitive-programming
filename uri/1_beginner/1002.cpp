#include <iostream>
#include <cstdio>

int main(){
	double n = 3.14159;
	double r = 0;

	std::cin >> r;

	double area = n*r*r;

	printf("A=%.4f\n", area);
	return 0;
}
