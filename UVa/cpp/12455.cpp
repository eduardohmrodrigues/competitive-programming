#include <cstdio>

int main(){
	int t, n, p, sum, bars[25];
	bool possible;
	scanf("%d", &t);

	while(t--){
		possible = false;
		scanf("%d %d", &n, &p);

		for(int i=0; i<p; ++i){
			scanf("%d", &bars[i]);
		}

		for(int i=0; i<(1 << p) && !possible; ++i){
			sum = 0;
			for(int j=0; j<p; ++j){
				if(i & (1 << j)) sum += bars[j];
			}

			possible = sum == n;
		}

		if(possible) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}
