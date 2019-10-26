#include <cstdio>

int main(){
	int n, x, y, sum;
	scanf("%d", &n);

	while(n>0){
		sum = 0;
		scanf("%d %d", &x, &y);
		if(x%2 == 0){
			x++;
		}

		for(int i=0; i<y; i++){
			sum += x;
			x += 2;
		}
		
		printf("%d\n", sum);
		--n;
	}

	return 0;
}
