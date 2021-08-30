#include <iostream>
#include <cstdio>

int main(){
	int t, x, y, cx, cy;

	scanf("%d", &t);

	while(t > 0){
		scanf("%d %d", &x, &y);
		cx = x/3;
		cy = y/3;

		printf("%d\n", cx*cy);

		--t;
	}

}
