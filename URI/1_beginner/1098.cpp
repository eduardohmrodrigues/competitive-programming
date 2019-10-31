#include <cstdio>

int main(){

	int k = 0;
	for(float i=0; i<=2.1; i+=0.2, k++){
		for(float j=1; j<4; j++){
			if(k%5 == 0){
				printf("I=%.0f J=%.0f\n", i, j+k*0.2);
			}else{
				printf("I=%.1f J=%.1f\n", i, j+k*0.2);
			}
		}
	}

	return 0;
}
