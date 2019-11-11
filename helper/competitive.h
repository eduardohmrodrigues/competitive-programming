#ifndef COMPETITIVE_H
#define COMPETITIVE_H
#include <ctime>
#include <string>

class ez_time
{
private:
	struct tm timeinfo;
	time_t timevar;
	std::string datestr;

public:
	ez_time(){
		timeinfo = {0};
		timevar = std::time(0);
	}

	~ez_time(){}
	
	void setTime(int year, int month, int day, int hours, int minutes, int seconds){
		datestr = std::to_string(year) + "-" + std::to_string(month) + "-" + std::to_string(day) + " " + std::to_string(hours) + ":" + std::to_string(minutes) + ":" + std::to_string(seconds);
		strptime(datestr.c_str(), "%Y-%m-%d %H:%M:%S", &timeinfo);
	}

	void addYears(int amount){
		timeinfo.tm_year += amount;

		timevar = mktime(&timeinfo);
		timeinfo = (*std::localtime(&timevar));
	}

	void addMonths(int amount){
		timeinfo.tm_mon += amount;

		timevar = mktime(&timeinfo);
		timeinfo = (*std::localtime(&timevar));
	}
	
	void addDays(int amount){
		timeinfo.tm_mday += amount;

		timevar = mktime(&timeinfo);
		timeinfo = (*std::localtime(&timevar));
	}

	void addHours(int amount){
		timeinfo.tm_hour += amount;

		timevar = mktime(&timeinfo);
		timeinfo = (*std::localtime(&timevar));

	}

	void addMinutes(int amount){
		timeinfo.tm_min += amount;

		timevar = mktime(&timeinfo);
		timeinfo = (*std::localtime(&timevar));
	}

	void addSeconds(int amount){
		timeinfo.tm_sec += amount;

		timevar = mktime(&timeinfo);
		timeinfo = (*std::localtime(&timevar));
	}

	int Year(){ return timeinfo.tm_year + 1900; }
	int Month(){ return timeinfo.tm_mon + 1; }
	int Day(){ return timeinfo.tm_mday; }
	int Hour(){ return timeinfo.tm_hour; }
	int Min(){ return timeinfo.tm_min; }
	int Sec(){ return timeinfo.tm_sec; }
	int WeekDay(){ return timeinfo.tm_wday; }
	int YearDay(){ return timeinfo.tm_yday; }
};

#endif
