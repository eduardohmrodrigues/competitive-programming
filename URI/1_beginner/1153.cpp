#include <cstdio>

int main(){
	int n, fat = 1;
	scanf("%d", &n);

	for(int i=1; i<=n; i++){
		fat *= i;
	}

	printf("%d\n", fat);
	return 0;
}
