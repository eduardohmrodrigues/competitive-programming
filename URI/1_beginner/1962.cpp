#include <cstdio>

int main(){
	
	int n, y;
	scanf("%d", &n);

	while(n>0){
		scanf("%d", &y);
		y = 2015-y;
		if(y > 0){
			printf("%d D.C.\n", y);
		}else{
			y -= 1;
			printf("%d A.C.\n", -y);
		}

		--n;
	}

	return 0;
}
