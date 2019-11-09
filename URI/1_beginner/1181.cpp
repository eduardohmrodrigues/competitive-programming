#include <cstdio>

int main(){
	int l;
	char c;
	double sum = 0, r;
	scanf("%d %c", &l, &c);

	for(int i=0; i<144; i++){
		scanf("%lf", &r);
		if(i/12 == l) sum += r;
	}

	if(c == 'S') printf("%.1lf\n", sum);
	else printf("%.1lf\n", sum/12.0);

	return 0;
}
