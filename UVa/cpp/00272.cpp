#include <iostream>
#include <cstdio>

int main(){
	char c;
	int index = 1;

	while(scanf("%c", &c) != EOF){
		if(c == '\"'){
			if(index == 1){
				printf("``");
				++index;	
			}else{
				printf("''");
				--index;
			}
		}else{
			printf("%c", c);
		}
	}

	return 0;
}
