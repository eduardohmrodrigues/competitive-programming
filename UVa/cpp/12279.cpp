#include <cstdio>

int main(){
	int n, k, balance, c=1;

	while(scanf("%d", &n) && n != 0){
		balance = 0;
		for(int i=0; i<n; i++){
			scanf("%d", &k);
			balance += k > 0 ? 1 : -1;
		}
		
		printf("Case %d: %d\n", c++, balance);
	}

	return 0;
}
