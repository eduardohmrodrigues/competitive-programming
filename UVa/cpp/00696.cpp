#include <cstdio>
#include <math.h>

int main(){
	int m, n, div, rest, total;

	while(scanf("%d %d", &m, &n) && (m != 0 || n != 0)){
		if(m <= 1 || n <= 1){
				printf("%d knights may be placed on a %d row %d column board.\n", n*m, m, n);
		}else if(m == 2){
			div = n/4;
			rest = n%4;
			total = div*4 + (rest < 3 ? rest*2 : 4);
			printf("%d knights may be placed on a %d row %d column board.\n", total, m, n);
		}else if(n == 2){
			div = m/4;
			rest = m%4;
			total = div*4 + (rest < 3 ? rest*2 : 4);
			printf("%d knights may be placed on a %d row %d column board.\n", total, m, n);
		}else{
			printf("%d knights may be placed on a %d row %d column board.\n", ((int)ceil(n*m/2.0)), m, n);
		}
	}

	return 0;
}
