#include <cstdio>
#include <cmath>

int main(){
	long long t, d, k, i, n, an, counter;
	long long coefs[25];
	scanf("%lld", &t);
	
	while(t--){
		counter = 0;
		scanf("%lld", &i);
		for(int x=0; x<=i; ++x){
			scanf("%lld", &coefs[x]);
		}
		
		scanf("%lld", &d);
		scanf("%lld", &k);
		
		n = 1;
		while(true){
			an = coefs[0];
			for(int x=1; x<=i; ++x){
				an += coefs[x]*std::pow(n, x);
			}
			
			counter += n*d;
			if(counter >= k) break;
			++n;
		}
		
		printf("%lld\n", an);
	}

	return 0;
}
