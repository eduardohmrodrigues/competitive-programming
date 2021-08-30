#include <cstdio>

int main(){
	int n, w, y1, y2, dist;
	scanf("%d", &n);

	while(n>0){
		scanf("%d", &w);
		bool fixable = true;

		scanf("%d %d", &y1, &y2);
		dist = y1 - y2;

		for(int i=0; i<w-1; i++){
			scanf("%d %d", &y1, &y2);
			fixable &= dist == y1 - y2;
		}

		printf(fixable ? "yes\n" : "no\n");
		if(n-1>0){
			printf("\n");
		}

		--n;
	}

	return 0;
}
