#include <cstdio>

int main(){
	int a[5005], t, n, sum;
	scanf("%d", &t);

	while(t--){
		sum = 0;
		scanf("%d", &n);
		for(int i=0; i<n; ++i){
			scanf("%d", &a[i]);
			for(int j=0; j<i; ++j){
				if(a[j] <= a[i]) ++sum;
			}
		}

		printf("%d\n", sum);
	}

	return 0;
}
