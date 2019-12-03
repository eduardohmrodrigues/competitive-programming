#include <cstdio>

int main(){
	int m, n;

	while(scanf("%d %d", &m, &n) != EOF && (m != 0 || n != 0)){
		printf("%d\n", m*n);
	}

	return 0;
}
