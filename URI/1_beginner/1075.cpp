#include <cstdio>

int main(){
	int n, d=0;
	scanf("%d", &n);
	
	while(d%n != 2){
		++d;
	}

	for(int i=d; i<10000; i+=n){
		printf("%d\n", i);
	}

	return 0;
}
