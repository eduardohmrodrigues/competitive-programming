#include <cstdio>
#include <math.h>

int main(){
	int t, x, y, a, b, c;
	
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &x, &y);
		b = abs(y-x)/2;
		a = x - b;
		if(a < b){c = a; a = b; b = c;}
		if(a-b == y) printf("%d %d\n", a, b);
		else printf("impossible\n");
	}

	return 0;
}
