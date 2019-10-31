#include <cstdio>

int main(){
	int  x, y, min, max, sum;

	while(scanf("%d %d", &x, &y) && x > 0 && y > 0){ 
		min = x < y ? x : y;
		max = x > y ? x : y;
		sum = 0;

		for(int i=min; i<=max; i++){
			printf("%d ", i);
			sum+=i;
		}		
		
		printf("Sum=%d\n", sum);
	}

	return 0;
}
