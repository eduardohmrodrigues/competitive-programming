#include <cstdio>

int main(){
	int notes[] = {10000, 5000, 2000, 1000, 500, 200};
	int coins[] = {100, 50, 25, 10, 5, 1};

	double m;
	scanf("%lf", &m);
	int n = m*100;

	printf("NOTAS:\n");
	for(int i=0; i<6; i++){
		printf("%d nota(s) de R$ %d.00\n", n/notes[i], notes[i]/100);
		n = n%notes[i];
	}

	printf("MOEDAS:\n");
	for(int i=0; i<6; i++){
		printf("%d moeda(s) de R$ %.2f\n", n/coins[i], coins[i]/100.0);
		n = n%coins[i];
	}

	return 0;
}
