#include <cstdio>

double fraction(int deep, int currentLevel){
	double r;
	
	if(deep == 0) return 0;

	if(currentLevel == deep){
		return 1.0/6.0;
	}

	return 1.0/(6.0 + fraction(deep, currentLevel+1));

}

int main(){
	int r;
	scanf("%d", &r);

	printf("%.10lf\n", 3+fraction(r, 1));
	return r;
}
