#include <cstdio>

int main(){
	int k, n, m, x, y;

	while(scanf("%d", &k) && k != 0){
		scanf("%d %d", &n, &m);

		while(k > 0){
			scanf("%d %d", &x, &y);
			if(x == n || y == m){
				printf("divisa\n");
			}else if(x > n){
				printf(y > m ? "NE\n" : "SE\n");
			}else{
				printf(y > m ? "NO\n" : "SO\n");
			}

			--k;
		}

	}

	return 0;
}
