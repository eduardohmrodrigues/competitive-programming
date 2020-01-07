#include <cstdio>

int main(){
	int a, b, c, x, y, z, s = 0;
	scanf("%d %d %d %d %d %d", &a, &b, &c, &x, &y, &z);
	
	s += x > a ? (x-a) : 0;
	s += y > b ? (y-b) : 0;
	s += z > c ? (z-c) : 0;

	printf("%d\n", s);
	return 0;
}
