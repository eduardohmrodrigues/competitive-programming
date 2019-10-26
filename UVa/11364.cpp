#include <cstdio>

int main(){
	int t, n, l, r, s;

	scanf("%d", &t);

	while(t > 0){
		scanf("%d", &n);
		l = 100; r = -1;
		for(int i=0; i<n; i++){
			scanf("%d", &s);
			if(s < l) l = s;
			if(s > r) r = s;
		}
		
		printf("%d\n", (r-l)*2);
		--t;
	}

	return 0;
}
