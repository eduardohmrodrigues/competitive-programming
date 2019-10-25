#include <iostream>
#include <cstdio>

int main(){
	float s;
	scanf("%f", &s);

	if(s <= 2000){
		printf("Isento\n");
	}else if(s <= 3000){
		printf("R$ %.2f\n",(s-2000)*0.08);
	}else if(s <= 4500){
		float a = 1000*0.08;
		float b = (s - 3000)*0.18;
		printf("R$ %.2f\n",a+b);
	}else{
		float a = 1000*0.08;
		float b = 1500*0.18;
		float c = (s - 4500)*0.28;
		printf("R$ %.2f\n",a+b+c);
	}

	return 0;
}
