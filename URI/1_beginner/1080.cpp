#include <cstdio>

int main(){
	int n, h = -1, ind=-1;
	for(int i=0; i<100; i++){
		scanf("%d", &n);

		if(n > h){
			h = n;
			ind = i+1;
		}
	}

	printf("%d\n%d\n", h, ind);

	return 0;
}
