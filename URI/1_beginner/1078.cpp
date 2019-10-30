#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);

	for(int i=1; i<11; i++){
		printf("%d x %d = %d\n", i, n, i*n);
	}

	return 0;
}
