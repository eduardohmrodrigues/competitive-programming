#include <cstdio>

int main(){
	int x, z, sum, c = 2;

	scanf("%d", &x);
	sum = x;
	
	while(scanf("%d", &z) && z <= x);

	while(true){
		++x;
		sum += x;

		if(sum > z){
			printf("%d\n", c);
			break;
		}

		++c;
	}

	return 0;
}
