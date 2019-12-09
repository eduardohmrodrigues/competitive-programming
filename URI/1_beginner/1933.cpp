#include <cstdio>
#include <algorithm>

int main(){
	int a, b, c;
	scanf("%d %d", &a, &b);

	c = std::max(a, b);
	printf("%d\n", c);
	
	return 0;
}
