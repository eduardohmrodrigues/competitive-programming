#include <cstdio>

int main(){
	double a, b;
	scanf("%lf %lf", &a, &b);
	printf("%.2lf%%\n", (b*100.0/a)-100);
	return 0;
}
