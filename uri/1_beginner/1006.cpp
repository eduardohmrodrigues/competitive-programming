#include <iostream>
#include <cstdio>

int main(){
	double a = 0;
	double b = 0;
	double c = 0;

	std::cin >> a;
	std::cin >> b;
	std::cin >> c;

	double w1 = 2;
	double w2 = 3;
	double w3 = 5;

	printf("MEDIA = %.1f\n", (a*w1 + b*w2 + c*w3)/(w1 + w2 + w3));
	
	return 0;
}
