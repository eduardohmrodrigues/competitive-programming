#include <cstdio>

int main(){
	double h, u, d, f;
	int day;
	double slowDownFactor,  hac, has;

	while(scanf("%lf %lf %lf %lf", &h, &u, &d, &f) && h != 0){
//		printf("H = %.0lf U = %.0lf D = %.0lf F = %.0lf\n", h, u, d, f);
		slowDownFactor = u*f/100;
		has = 0;
		day = 0;
		hac = 0;

//		printf("SlowDown = %.2f\n", slowDownFactor);
		while(hac <= h && has >= 0){
//			printf("Day: %d InitialHeight: %.0lf DistanceClimbed: %.2lf ", day+1, has, u);
			hac = has + u;
			has = hac - d;
			
			u -= slowDownFactor;
			u = u < 0 ? 0 : u;
//			printf("HeightAfterClimb: %.2lf HeightAfterSliding: %.2lf UTomorrow = %.2lf\n", hac, has, u);
			++day;
		}

		if(hac > h){
			printf("success on day %d\n", day);
		}else{
			printf("failure on day %d\n", day);
		}
	}

	return 0;
}
