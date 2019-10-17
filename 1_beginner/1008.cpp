#include <iostream>
#include <cstdio>

int main(){
	int n = 0;
	int h = 0;
	float a = 0;

	std::cin >> n;
	std::cin >> h;
	std::cin >> a;

	std::cout << "NUMBER = " << n << std::endl;
	printf("SALARY = U$ %.2f\n", h*a);

	return 0;
}
