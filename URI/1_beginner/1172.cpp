#include <cstdio>

int main(){
	int x;
	for(int i=0; i<10; i++){
		scanf("%d", &x);
		printf("X[%d] = %d\n", i, x>0?x:1);
	}

	return 0;
}
