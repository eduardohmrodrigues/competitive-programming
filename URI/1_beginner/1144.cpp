#include <cstdio>

int main(){
	int n, sq, cb;
	scanf("%d", &n);

	for(int i=1; i<=n; i++){
		sq = i*i; cb = i*i*i;
		printf("%d %d %d\n", i, sq, cb);
		printf("%d %d %d\n", i, sq+1, cb+1);
	}

	return 0;
}

