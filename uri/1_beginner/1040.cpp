#include <iostream>
#include <cstdio>

int main(){
	float n1, n2, n3, n4, m, e, mf;
	scanf("%f %f %f %f", &n1, &n2, &n3, &n4);

	m = 2*n1 + 3*n2 + 4*n3 + n4;
	m /= 10;
	
	printf("Media: %.1f\n", m);

	if(m >= 7){
		printf("Aluno aprovado.\n");	
	}else if(m < 5){
		printf("Aluno reprovado.\n");	
	}else{
		printf("Aluno em exame.\n");
		scanf("%f", &e);
		printf("Nota do exame: %.1f\n", e);
		mf = m + e;
		mf /= 2;

		if(mf < 5){
			printf("Aluno reprovado.\n");	
		}else{
			printf("Aluno aprovado.\n");	
		}

		printf("Media final: %.1f\n", mf);
	}

	return 0;
}
