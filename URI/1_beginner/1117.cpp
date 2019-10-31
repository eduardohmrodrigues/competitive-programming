#include <cstdio>

int main(){
	float x, y, n=2;

	while(scanf("%f", &x) && (x < 0 || x > 10)){
		printf("nota invalida\n");	
	}
	while(scanf("%f", &y) && (y < 0 || y > 10)){
		printf("nota invalida\n");
	}

	printf("media = %.2f\n", (x+y)/2.0);
	return 0;
}
