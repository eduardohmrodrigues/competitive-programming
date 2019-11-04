#include <cstdio>

int main(){
	int n;
	double sum = 0, amount = 0;

	while(scanf("%d", &n) && n >= 0){
		sum += n;
		++amount;
	}

	amount += amount > 0 ? 0 : 1;
	printf("%.2f\n", sum/amount);

	return 0;
}
