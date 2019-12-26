#include <cstdio>

int main(){
	int c = 0, t, g;
	scanf("%d", &t);

	for(int i=0; i<5; ++i){
		scanf("%d", &g);
		c += g == t;
	}

	printf("%d\n", c);
	return 0;
}
