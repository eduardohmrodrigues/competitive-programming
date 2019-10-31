#include <cstdio>

int main(){
	int pass;

	while(scanf("%d", &pass) && pass != 2002) printf("Senha Invalida\n");

	printf("Acesso Permitido\n");
	return 0;
}
