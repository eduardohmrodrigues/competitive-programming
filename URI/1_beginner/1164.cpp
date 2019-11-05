#include <cstdio>

int main(){
	int n, x, sum;
	scanf("%d", &n);
	while(n--){
		scanf("%d", &x);
		sum = 0;

		for(int i=1; i<x; i++){
			if(x%i==0) sum += i;
		}
		
		if(sum == x) printf("%d eh perfeito\n", x);
		else printf("%d nao eh perfeito\n", x);
	}

	return 0;
}
