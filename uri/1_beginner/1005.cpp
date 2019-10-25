#include <iostream>
#include <cstdio>

int main(){
	double x = 0;
	double y = 0;

	double w1 = 3.5;
	double w2 = 7.5;

	std::cin >> x;
	std::cin >> y;

	printf("MEDIA = %.5f\n", (x*w1 + y*w2)/(w1+w2));
}
