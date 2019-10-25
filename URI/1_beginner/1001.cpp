#include <iostream>

int main () {
	std::string line;
	int x = 0;

	std::cin >> line;
	x = x + std::stoi(line);
	
	std::cin >> line;
	x = x + std::stoi(line);
		
	std::cout << "X = " << x << std::endl;

	return 0;
}
