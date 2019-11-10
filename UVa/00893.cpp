#include <cstdio>
#include <ctime>
#include <string>
#include <iostream>

int main(){
	int skip, day, month, year;
	std::string datestr;
	time_t time_input, time_skipped;
	struct tm timeinfo;

	while(scanf("%d %d %d %d", &skip, &day, &month, &year) != EOF && (skip > 0 || day > 0 || month > 0 || year > 0)){
		timeinfo = {0};
		datestr = std::to_string(year) + "-" + std::to_string(month) + "-" + std::to_string(day) + " 00:00";
		strptime(datestr.c_str(), "%Y-%m-%d %H:%M", &timeinfo);
		timeinfo.tm_mday += skip;

		time_input = mktime(&timeinfo);
		timeinfo = (*std::localtime(&time_input));
		std::cout << timeinfo.tm_mday << " " << timeinfo.tm_mon+1 << " " << timeinfo.tm_year + 1900 << std::endl;
//		std::cout << time_input << std::endl;
//		std::cout << ctime(&time_input) << std::endl;
	}
	

	return 0;
}
