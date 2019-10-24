#include <iostream>
#include <cstdio>

int main(){
	float p[] = { 0.15, 0.12, 0.10, 0.07, 0.04 };
	float salary, bonus, increment;
	scanf("%f", &salary);

	if(salary <= 400){
		bonus = p[0];
	}else if(salary <= 800){
		bonus = p[1];
	}else if(salary <= 1200){
		bonus = p[2];
	}else if(salary <= 2000){
		bonus = p[3];
	}else{	
		bonus = p[4];
	}
	
	increment = salary*bonus;

	printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: %.0f %%\n", salary+increment, increment, bonus*100);
	return 0;
}
