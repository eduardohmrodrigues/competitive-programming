#include <cstdio>

int main(){
	int x, y, i, j;
	scanf("%d", &x);
	scanf("%d", &y);
	
	if(x==0 || y==0) printf("0\n0\n");
	else printf("%d\n%d\n", (x*y + (x-1)*(y-1)), (x-1)*2 + (y-1)*2);

	return 0;
}
