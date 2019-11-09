#include <cstdio>

int main(){
	int t, years;
	scanf("%d", &t);
	long long pa, pb;
	double g1, g2;
	
	while(t--){
		years = 0;
		scanf("%lld %lld %lf %lf", &pa, &pb, &g1, &g2);
		g1 /= 100;
		g2 /= 100;
		
		while(years<101 && pa <= pb){
			years++;
			pa += g1*pa;
			pb += g2*pb;
		}

		if(years > 100) printf("Mais de 1 seculo.\n");
		else printf("%d anos.\n", years);
	}

	return 0;
}
