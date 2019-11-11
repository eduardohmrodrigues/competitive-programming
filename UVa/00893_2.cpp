#include <cstdio>
#include "./../helper/competitive.h"
#include <string>
#include <iostream>

int main(){
	int skip, day, month, year;
	std::string datestr;
	ez_time timez;

	while(scanf("%d %d %d %d", &skip, &day, &month, &year) != EOF && (skip > 0 || day > 0 || month > 0 || year > 0)){
		timez.setTime(year, month, day, 0, 0, 0);
		timez.addDays(skip);
		std::cout << timez.Day() << " " << timez.Month() << " " << timez.Year() << std::endl;
	}
	

	return 0;
}

