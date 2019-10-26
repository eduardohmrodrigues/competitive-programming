#include <cstdio>

int main(){
	int t, n;

	scanf("%d", &t);

	while(t > 0){
		scanf("%d", &n);
		
		int x = (((n*567/9)+7492)*235/47)-498;
		x *= (x < 0 ? -1 : 1);

		printf("%d\n", (x/10)%10);

		--t;
	}
	return 0;
}
