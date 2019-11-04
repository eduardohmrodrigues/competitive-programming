#include <cstdio>

int main(){
	double s = 1;
	for(float i=2; i<101; i++){
		s += 1.0/i;
	}

	printf("%.2f\n", s);

	return 0;
}
