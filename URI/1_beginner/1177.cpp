#include <cstdio>

int main(){
	int x, n = 0;
	scanf("%d", &x);

	for(int i=0; i<1000; ++i){
		printf("N[%d] = %d\n", i, n++);
		n%=x;
	}

	return 0;
}
