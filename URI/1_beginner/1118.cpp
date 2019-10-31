#include <cstdio>

int main(){
	int r = 1;
	float x, y;

	while(r == 1){
		while(scanf("%f", &x) && (x < 0 || x > 10)){
			printf("nota invalida\n");	
		}
		while(scanf("%f", &y) && (y < 0 || y > 10)){
			printf("nota invalida\n");
		}

		printf("media = %.2f\n", (x+y)/2.0);
		printf("novo calculo (1-sim 2-nao)\n");

		while(scanf("%d", &r) && r != 1 && r != 2){
			printf("novo calculo (1-sim 2-nao)\n");
		}
	}

	return 0;
}
