#include <cstdio>

int main(){

	for(int j=60, i=1; j>=0; j-=5, i+=3){
		printf("I=%d J=%d\n", i, j);
	}

	return 0;
}
