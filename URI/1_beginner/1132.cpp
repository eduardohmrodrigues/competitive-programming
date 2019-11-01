#include <cstdio>

int main(){
	long long x, y, a, sum = 0;
	scanf("%lld %lld", &x, &y);

	if(x > y){
		a = x;
		x = y;
		y = a;
	}

	for(int i=x; i<=y; i++){
		sum += i%13 != 0 ? i : 0;
	}

	printf("%lld\n", sum);
	return 0;
}
