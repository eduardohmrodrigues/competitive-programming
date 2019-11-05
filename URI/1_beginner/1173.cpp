#include <cstdio>

int main(){
	int n[10];
	int x;
	scanf("%d", &x);

	n[0] = x;
	printf("N[%d] = %d\n", 0, x);
	for(int i=1; i<10; i++){
		n[i] = 2*n[i-1];
		printf("N[%d] = %d\n", i, n[i]);
	}

	return 0;
}
