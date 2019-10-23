#include <iostream>
#include <cstdio>
#include <math.h>

int main(){
	double a, b, c;

	scanf("%lf %lf %lf", &a, &b, &c);
	
	double d = b * b - 4 * a * c;
	if(d < 0 || a == 0){
		printf("Impossivel calcular\n");
	}else{
		double aa = 2 * a;
		double r1 = (-b + sqrt(d))/aa;
		double r2 = (-b - sqrt(d))/aa;

		printf("R1 = %.5f\nR2 = %.5f\n", r1, r2);
	}

	return 0;
}

