#include <iostream>
#include <cstdio>

int main(){
	int p1id = 0;
	int p1amount = 0;
	float p1price = 0;

	int p2id = 0;
	int p2amount = 0;
	float p2price = 0;
	
	scanf("%d %d %f", &p1id, &p1amount, &p1price);
	scanf("%d %d %f", &p2id, &p2amount, &p2price);

	printf("VALOR A PAGAR: R$ %.2f\n", p1amount*p1price + p2amount*p2price);
	return 0;
}
