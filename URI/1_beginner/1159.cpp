#include <cstdio>

int main(){
	int n, sum;
	while(scanf("%d", &n) && n != 0){
		sum = 0;
		n = n%2 == 0 ? n : n+1;
		
		for(int i=0; i<5; i++){
			sum += n;
			n+=2;
		}

		printf("%d\n", sum);
	}

	return 0;
}
