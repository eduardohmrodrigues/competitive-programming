#include <cstdio>

int main(){
	long long t, n, fib, a, b;
	scanf("%lld", &n);

	while(n--){
		fib = 0; a = 0; b = 1; 
		scanf("%lld", &t);

		for(int i=2; i<=t; i++){
			fib = a + b;
			a = b;
			b = fib;
		}

		if(t==0) printf("Fib(0) = 0\n");
		else if(t==1) printf("Fib(1) = 1\n");
		else printf("Fib(%lld) = %lld\n", t, fib);
	}

	return 0;
}
