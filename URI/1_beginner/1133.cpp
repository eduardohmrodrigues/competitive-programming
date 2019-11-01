#include <cstdio>

int main(){
	long long x, y, a;
	scanf("%lld %lld", &x, &y);

	if(x > y){
		a = x;
		x = y;
		y = a;
	}

	for(long long i=x+1; i<y; i++){
		a = i%5;
		if(a == 2 || a == 3){
			printf("%lld\n", i);
		}
	}

	return 0;
}
