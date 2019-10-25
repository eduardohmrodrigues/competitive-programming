#include <iostream>
#include <cstdio>

int main(){
	float arr[6];
	int c = 0;
	std::cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4] >> arr[5];

	for(int i=0; i<6; i++){
		c += arr[i] > 0 ? 1 : 0;
	}
	
	std::cout << c << " valores positivos" << std::endl;
	return 0;
}
