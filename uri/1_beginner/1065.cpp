#include <iostream>
#include <cstdio>

int main(){
	int arr[5];
	int c = 0;
	std::cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];

	for(int i=0; i<5; i++){
		if(arr[i]%2 == 0){
			c += 1;
		}
	}
	
	std::cout << c << " valores pares" << std::endl;
	return 0;
}


