#include <iostream>
#include <cstdio>

int main(){
	std::string name;
	double salary = 0;
	double sells = 0;
	double bonus = 0.15;

	std::cin >> name;
	std::cin >> salary;
	std::cin >> sells;

	printf("TOTAL = R$ %.2f\n", salary + sells*bonus);
	return 0;
}
