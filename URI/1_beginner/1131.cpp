#include <cstdio>

int main(){
	int x, y, r = 1, interVic = 0, gremVic = 0, total = 0;
	bool first = true;

	while(r == 1){
		scanf("%d %d", &x, &y);
		interVic += x > y ? 1 : 0;
		gremVic += x < y ? 1 : 0;
		total++;

		printf("Novo grenal (1-sim 2-nao)\n");
		while(scanf("%d", &r) && r != 1 && r != 2){
			printf("Novo grenal (1-sim 2-nao)\n");
		}
	}
	
	printf("%d grenais\n", total);
	printf("Inter:%d\n", interVic);
	printf("Gremio:%d\n", gremVic);
	printf("Empates:%d\n", total - (interVic + gremVic));
	
	if(interVic > gremVic) printf("Inter venceu mais\n");
	else if(gremVic > interVic) printf("Gremio venceu mais\n");
	else printf("Nao houve vencedor\n");

	return 0;
}
