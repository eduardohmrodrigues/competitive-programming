#include <cstdio>

int main(){

	for(int i=1; i<=9; i+=2){
		int offset = i-1;
		int start = 7+offset;
		for(int j=start; j>=start-2; j--){
			printf("I=%d J=%d\n", i, j);
		}
	}

	return 0;
}
