#include <iostream>

int main(){
	int seconds;
	std::cin >> seconds;

	int minutes = seconds/60;
	seconds = seconds - minutes*60;

	int hours = minutes/60;
	minutes = minutes - hours*60;

	std::cout << hours << ":" << minutes << ":" << seconds << std::endl;

	return 0;
}
