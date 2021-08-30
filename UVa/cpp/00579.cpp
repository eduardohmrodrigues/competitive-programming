#include <cstdio>

int main(){
	int h, m;
	double partialWalk, minutes;
	while(scanf("%d:%d", &h, &m) != EOF && (h != 0 || m != 0)){
		partialWalk = m/60.0;
		minutes = h*5 + partialWalk*5;
		minutes = m-minutes;
		minutes = minutes<0?-minutes:minutes;
		minutes *= 6;
		
		if(minutes > 180) minutes = 360 - minutes;
		printf("%.3lf\n", minutes);
	}

	return 0;
}
