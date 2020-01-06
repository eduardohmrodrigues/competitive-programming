#include <cstdio>

int main(){
	int c, x, y;
	bool found = false;
	scanf("%d", &c);
	scanf("%d", &y);
	
	for(int i=2; i<=c; ++i){
		scanf("%d", &x);
		if(x < y){
			printf("%d\n", i);
			found = true;
			break;
		}

		y = x;
	}

	if(!found) printf("0\n");

	return 0;
}
