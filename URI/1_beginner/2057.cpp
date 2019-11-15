#include <cstdio>

int main(){
	int n, s, t;
	scanf("%d %d %d", &n, &s, &t);
	n = n + s + t;
	while(n < 0){
		n = 24 + n;
	}

	n = n%24;
	printf("%d\n", n);

	return 0;
}
