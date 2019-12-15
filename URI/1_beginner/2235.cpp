#include <cstdio>



int main()
{
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);
   
	
	if(a == 0 || b == 0 || c == 0) printf("S\n");

	else if(a == b || a == c || b == c) printf("S\n");

	else if(a == (b+c) || a == (b-c) || a == (c-b)) printf("S\n");

	else printf("N\n");

	
	return 0;

}