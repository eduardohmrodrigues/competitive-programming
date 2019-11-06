#include <cstdio>

int main(){
	int n, c, s=9999, i=0, si=-1;
	scanf("%d", &n);

	while(n--){
		scanf("%d", &c);
		if(c < s){
			si = i;
			s = c;
		}

		i++;
	}

	printf("Menor valor: %d\nPosicao: %d\n", s, si);
	return 0;
}
