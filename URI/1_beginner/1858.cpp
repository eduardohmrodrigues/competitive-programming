#include <cstdio>

int main(){
	int n, r, min=999, index = 0;
	scanf("%d", &n);

	for(int i=0; i<n; i++){
		scanf("%d", &r);
		if(r<min){
			min = r;
			index = i+1;
		}
	}

	printf("%d\n", index);

	return 0;
};
