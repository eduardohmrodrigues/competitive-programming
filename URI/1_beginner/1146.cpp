#include <cstdio>

int main(){

	int n;
	while(scanf("%d", &n) && n != 0){
		for(int i=1; i<=n; i++){
			printf("%d", i);
			if(i+1 <= n) printf(" ");
		}
		printf("\n");
	}

	return 0;
}
