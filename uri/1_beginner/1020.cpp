#include <iostream>

int main(){
	int days;
	std::cin >> days;

	int years = days/365;
	days = days - 365*years;

	int months = days/30;
	days = days - 30*months;

	std::cout << years << " ano(s)" << std::endl;
	std::cout << months << " mes(es)" << std::endl;
	std::cout << days << " dia(s)" << std::endl;

	return 0;
}
