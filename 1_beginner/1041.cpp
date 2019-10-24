#include <iostream>
#include <cstdio>

int main(){
	float x, y;
	scanf("%f %f", &x, &y);

	if(x == 0 && y == 0){
		printf("Origem\n");
	}else if(x == 0){
		printf("Eixo Y\n");
	}else if(y == 0){
		printf("Eixo X\n");
	}else if(x > 0){
		printf(y > 0 ? "Q1\n" : "Q4\n");
	}else{
		printf(y > 0 ? "Q2\n" : "Q3\n");
	}

	return 0;
}
