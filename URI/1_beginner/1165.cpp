#include <cstdio>

int main(){
	int n, x;
	bool prime;
	scanf("%d", &n);

	while(n--){
		scanf("%d", &x);
		
		prime = true;
		for(int i=2; i<=x/2 && prime; i++){
			prime &= x%i != 0;
		}
		
		if(prime) printf("%d eh primo\n", x);
		else printf("%d nao eh primo\n", x);
	}

	return 0;
}
