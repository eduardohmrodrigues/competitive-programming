#include <cstdio>

int main(){
	int t, n, max, s, c = 1;
	scanf("%d", &t);

	while(t > 0){
		max = 0;
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%d", &s);
			max = max > s ? max : s;
		}
		
		printf("Case %d: %d\n", c, max);
		++c;
		--t;
	}

	return 0;
}
