#include <iostream>
#include <cstdio>

int main(){
	float table[5] = {4, 4.5, 5, 2, 1.5};
	int x, y;

	scanf("%d %d", &x, &y);
	printf("Total: R$ %.2f\n", table[x-1]*y);

	return 0;
}
