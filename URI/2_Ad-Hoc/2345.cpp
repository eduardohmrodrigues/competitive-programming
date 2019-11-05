#include<cstdio>

int main(){
	int a,b,c,d,e;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	
	e = (a+d)-(b+c);
	printf("%d\n", e>0?e:-e);
	
	return 0;
}