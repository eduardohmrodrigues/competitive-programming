#include <iostream>
#include <cstdio>

int main(){
	int x, y, z, w, d;

	while(scanf("%d %d %d %d", &x, &y, &z, &w) && (x != 0 || y != 0 || z != 0 || w != 0)){
		d = 1080 + ((40 + (x - y))%40)*9 + ((40 + (z - y))%40)*9 + ((40 + (z - w))%40)*9;
		printf("%d\n", d);
	}

	return 0;
}
