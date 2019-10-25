#include <iostream>
#include <cstdio>

void swap(double* a, double* b){
	double temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	double arr[] = {0, 0, 0};
	scanf("%lf %lf %lf", &arr[0], &arr[1], &arr[2]);
	if(arr[0] < arr[1]){
		swap(&arr[0], &arr[1]);
	}
	if(arr[0] < arr[2]){
		swap(&arr[0], &arr[2]);
	}
	if(arr[1] < arr[2]){
		swap(&arr[1], &arr[2]);
	}

	
    	if (arr[0] >= arr[1] + arr[2]){
		//, write the message: 
		printf("NAO FORMA TRIANGULO\n");
		return 0;
	}
    	if (arr[0]*arr[0] == arr[1]*arr[1] + arr[2]*arr[2]){
		//, write the message: 
		printf("TRIANGULO RETANGULO\n");
	}
    	if (arr[0]*arr[0] > arr[1]*arr[1] + arr[2]*arr[2]){
		//, write the message: 
		printf("TRIANGULO OBTUSANGULO\n");
	}
    	if (arr[0]*arr[0] < arr[1]*arr[1] + arr[2]*arr[2]){
		//, write the message: 
		printf("TRIANGULO ACUTANGULO\n");
	}
    	if (arr[0] == arr[1] && arr[1] == arr[2]){
		//, write the message: 
		printf("TRIANGULO EQUILATERO\n");
	}
    	if ((arr[0] == arr[1] || arr[0] == arr[2] || arr[1] == arr[2]) && (arr[0] != arr[1] || arr[0] != arr[2] || arr[1] != arr[2])){
		//, write the message: 
		printf("TRIANGULO ISOSCELES\n");
	}
	

	return 0;
}
