#include <cstdio>

int main(){
	int n;
	double s = 0;
	scanf("%d", &n);

	
	for(int i=0; i<n; i++){
		s = 1.0 / (2 + s);
	}

	printf("%.10lf\n", 1 + s);
	return 0;
}
