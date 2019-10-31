#include <cstdio>

int main(){
	int n, x, y, min, max, sum;
	scanf("%d", &n);

	while(n--){
		scanf("%d %d", &x, &y);
		min = x < y ? x : y;
		max = x > y ? x : y;
		sum = 0;

		for(int i=min+1; i<max; i++){
			if(i%2 != 0) sum+=i;
		}		
		
		printf("%d\n", sum);
	}

	return 0;
}
