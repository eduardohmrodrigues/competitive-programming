#include <cstdio>

int main(){
	int c = 2;
	double s = 1;
	for(float i=3; i<40; i+=2){
		s += i/c;
		c *= 2;
	}

	printf("%.2f\n", s);

	return 0;
}
