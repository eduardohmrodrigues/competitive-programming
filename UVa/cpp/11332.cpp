#include <cstdio>

int main(){
	int n, g;
	scanf("%d", &n);

	while(n){
		g = 0;
		if(n%10 == n){
			g = n;
		}

		while(n%10 != n){
			g += n%10;
			n /= 10;
			
			if(n%10 == n){
				g += n%10;
				
				if(g/10 > 0){
					n = g;
					g = 0;
				}
			}
		}
		
		printf("%d\n", g);
		scanf("%d", &n);		
	}

	return 0;
}
