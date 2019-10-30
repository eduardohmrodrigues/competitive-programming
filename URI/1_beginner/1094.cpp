#include <cstdio>

int main(){
	int n, a, total, r = 0, c = 0, s = 0;
	char t;

	scanf("%d", &n);

	while(n--){
		scanf("%d %c", &a, &t);
		
		if(t == 'C') c+=a;
		else if(t == 'R') r+=a;
		else s+=a;
	}
	
	total = r+c+s;
	printf("Total: %d cobaias\n", total);
	printf("Total de coelhos: %d\n", c);
	printf("Total de ratos: %d\n", r);
	printf("Total de sapos: %d\n", s);
	printf("Percentual de coelhos: %.2lf %%\n", 100.0*(double)c/(double)total);
	printf("Percentual de ratos: %.2lf %%\n", 100.0*(double)r/(double)total);
	printf("Percentual de sapos: %.2lf %%\n", 100.0*(double)s/(double)total);

	return 0;
}
