#include <cstdio>

int main(){
	int a = 97;

	for(int i=0; i<26; i++){
		printf("%d e %c\n", a+i, a+i);
	}

	return 0;
}
