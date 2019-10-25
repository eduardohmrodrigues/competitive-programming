#include <iostream>
#include <cstdio>

int main(){
	float arr[6];
	int c = 0;
	float m = 0;
	std::cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4] >> arr[5];

	for(int i=0; i<6; i++){
		if(arr[i] > 0){
			c += 1;
			m += arr[i];
		}
	}
	
	std::cout << c << " valores positivos" << std::endl;
	printf("%.1f\n", m/c);
	return 0;
}

