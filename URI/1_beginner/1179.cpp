#include <cstdio>

int main(){
	int x=0, y=0, n;
	int odd[5], even[5];
	for(int i=0; i<15; i++){
		scanf("%d", &n);

		if(n%2==0){
			even[x] = n;
			x++;

			if(x == 5){
				for(int i=0; i<5; i++) printf("par[%d] = %d\n", i, even[i]);
				x = 0;
			}
		}else{
			odd[y] = n;
			y++;
			
			if(y == 5){
				for(int i=0; i<5; i++) printf("impar[%d] = %d\n", i, odd[i]);
				y = 0;
			}
		}
	}

	for(int i=0; i<y; i++) printf("impar[%d] = %d\n", i, odd[i]);
	for(int i=0; i<x; i++) printf("par[%d] = %d\n", i, even[i]);

	return 0;
}
