#include <cstdio>

int main(){
	int n, counter=1;
	scanf("%d", &n);

	for(int i=0; i<n; i++){
		for(int j=counter; j<counter+3; j++){
			printf("%d ", j);
		}

		printf("PUM\n");
		counter += 4;
	}

	return 0;
}
