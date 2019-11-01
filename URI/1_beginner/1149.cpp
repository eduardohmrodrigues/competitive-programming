#include <cstdio>

int main(){
	int n, a, sum = 0;

	scanf("%d", &a);
	while(scanf("%d", &n) && n < 1);
	
	for(int i=a; i<a+n; i++) sum+=i;
	printf("%d\n", sum);

	return 0;
}
