#include <iostream>
#include <cstdio>

int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	int ab = (a + b + abs(a-b))/2;
	int greater = (ab + c + abs(ab-c))/2;

	printf("%d eh o maior\n", greater);
	return 0;
}
