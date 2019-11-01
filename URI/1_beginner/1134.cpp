#include <cstdio>

int main(){
	int code, a = 0, g = 0, d = 0;

	while(scanf("%d", &code) && code != 4){
		a += code == 1;
		g += code == 2;
		d += code == 3;
	}

	printf("MUITO OBRIGADO\n");
	printf("Alcool: %d\n", a);
	printf("Gasolina: %d\n", g);
	printf("Diesel: %d\n", d);

	return 0;
}
