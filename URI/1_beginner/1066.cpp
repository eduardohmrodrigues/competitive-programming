#include <iostream>
#include <cstdio>

int main(){
	int arr[5];
	int e = 0, o = 0, p = 0, n = 0;
	std::cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];

	for(int i=0; i<5; i++){
		if(arr[i]%2 == 0){
			e += 1;
		}else{
			o += 1;
		}

		if(arr[i] > 0){
			p += 1;
		}else if(arr[i] < 0){
			n += 1;
		}
	}
	
	std::cout << e << " valor(es) par(es)" << std::endl;
	std::cout << o << " valor(es) impar(es)" << std::endl;
	std::cout << p << " valor(es) positivo(s)" << std::endl;
	std::cout << n << " valor(es) negativo(s)" << std::endl;
	return 0;
}
