#include <cstdio>

int main(){
	int arr[100000], n, c, s;
	scanf("%d", &n);
	s = n+1;

	for(int i=0; i<=n; ++i){
		for(int j=0; j<=n; ++j){
			scanf("%d", &arr[i*s+j]);
		}
	}


	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			c = 0;
			c += arr[i*s+j];
			c += arr[i*s+j+1];
			c += arr[(i+1)*s+j];
			c += arr[(i+1)*s+j+1];
			
			if(c > 1) printf("S");
			else printf("U");
		}

		printf("\n");
	}

	return 0;
}
