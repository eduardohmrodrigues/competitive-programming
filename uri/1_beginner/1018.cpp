#include <iostream>

int main(){
	int money[7] = {100, 50, 20, 10, 5, 2, 1};
	int x;

	std::cin >> x;
	
	std::cout << x << std::endl;
	for(int i=0; i<7; i++){
		int amount = x/money[i];
		x -= money[i]*amount;

		std::cout << amount << " nota(s) de R$ " << money[i] << ",00" << std::endl;
	}

	return 0;
}
