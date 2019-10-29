#include <cstdio>

int main(){
	int n, f, size, population, friendliness, sum;
	scanf("%d", &n);

	while(n > 0){
		scanf("%d", &f);
		sum = 0;
		for(int i=0; i<f; i++){
			scanf("%d %d %d", &size, &population, &friendliness);
			sum += size*friendliness;
		}

		printf("%d\n", sum);
		--n;
	}

	return 0;
}
