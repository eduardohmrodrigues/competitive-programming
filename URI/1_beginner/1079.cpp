#include<cstdio>

int main(){
	int n;
	double x, y, z;
	scanf("%d", &n);

	while(n>0){
		scanf("%lf %lf %lf", &x, &y, &z);
		printf("%.1lf\n", (x*2+y*3+z*5)/10.0);
		--n;
	}

	return 0;
}
