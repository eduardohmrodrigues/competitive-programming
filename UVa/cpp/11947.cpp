#include <cstdio>
#include <iostream>
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

//	ez_time(int year, int month, int day){
//		timeinfo = {0};
//		timevar = std::time(0);
//		this->setTime(year, month, day, 0, 0, 0);
//	}

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
	int Hours(){ return timeinfo.tm_hour; }
	int Minutes(){ return timeinfo.tm_min; }
	int Seconds(){ return timeinfo.tm_sec; }
	int WeekDay(){ return timeinfo.tm_wday; }
	int YearDay(){ return timeinfo.tm_yday; }

	std::string to_string(){
		std::string str = std::to_string(this->Year()) + "/" + std::to_string(this->Month()) + "/" + std::to_string(this->Day()) + " " + std::to_string(this->Hours()) + ":" + std::to_string(this->Minutes()) + ":" + std::to_string(this->Seconds());
		return str;
	}

	void CopyTo(ez_time *a){
		(*a).setTime(this->Year(), this->Month(), this->Day(), this->Hours(), this->Minutes(), this->Seconds());
	}

	bool isBefore(ez_time a){
		if(this->Year() > a.Year()) return false;
		if(this->Year() < a.Year()) return true;
		if(this->Month() > a.Month()) return false;
		if(this->Month() < a.Month()) return true;
		if(this->Day() > a.Day()) return false;
		if(this->Day() < a.Day()) return true;
		if(this->Hours() > a.Hours()) return false;
		if(this->Hours() < a.Hours()) return true;
		if(this->Minutes() > a.Minutes()) return false;
		if(this->Minutes() < a.Minutes()) return true;
		if(this->Seconds() > a.Seconds()) return false;
		if(this->Seconds() < a.Seconds()) return true;
		return false;
	}

	bool isAfter(ez_time a){
		if(this->Year() < a.Year()) return false;
		if(this->Year() > a.Year()) return true;
		if(this->Month() < a.Month()) return false;
		if(this->Month() > a.Month()) return true;
		if(this->Day() < a.Day()) return false;
		if(this->Day() > a.Day()) return true;
		if(this->Hours() < a.Hours()) return false;
		if(this->Hours() > a.Hours()) return true;
		if(this->Minutes() < a.Minutes()) return false;
		if(this->Minutes() > a.Minutes()) return true;
		if(this->Seconds() < a.Seconds()) return false;
		if(this->Seconds() > a.Seconds()) return true;
		return false;
	}

	bool isBetween(ez_time a, ez_time b){
		if(a.isAfter(b)) return this->isAfter(b) && this->isBefore(a);
		return this->isAfter(a) && this->isBefore(b);
	}
};

std::string getZodiac(ez_time a){
	ez_time aquarius, pisces, aries, taurus, gemini, cancer, leo, virgo, libra, scorpio, sagittarius, capricorn;
	aquarius.setTime(a.Year(), 1, 21, 0, 0, 0);
	pisces.setTime(a.Year(), 2, 20, 0, 0, 0);
	aries.setTime(a.Year(), 3, 21, 0, 0, 0);
	taurus.setTime(a.Year(), 4, 21, 0, 0, 0);
	gemini.setTime(a.Year(), 5, 22, 0, 0, 0);
	cancer.setTime(a.Year(), 6, 22, 0, 0, 0);
	leo.setTime(a.Year(), 7, 23, 0, 0, 0);
	virgo.setTime(a.Year(), 8, 22, 0, 0, 0);
	libra.setTime(a.Year(), 9, 24, 0, 0, 0);
	scorpio.setTime(a.Year(), 10, 24, 0, 0, 0);
	sagittarius.setTime(a.Year(), 11, 23, 0, 0, 0);
	capricorn.setTime(a.Year(), 12, 23, 0, 0, 0);

	if(a.isBetween(aquarius, pisces)){
		return "aquarius";
	}
	if(a.isBetween(pisces, aries)){
		return "pisces";
	}
	if(a.isBetween(aries, taurus)){
		return "aries";
	}
	if(a.isBetween(taurus, gemini)){
		return "taurus";
	}
	if(a.isBetween(gemini, cancer)){
		return "gemini";
	}
	if(a.isBetween(cancer, leo)){
		return "cancer";
	}
	if(a.isBetween(leo, virgo)){
		return "leo";
	}
	if(a.isBetween(virgo, libra)){
		return "virgo";
	}
	if(a.isBetween(libra, scorpio)){
		return "libra";
	}
	if(a.isBetween(scorpio, sagittarius)){
		return "scorpio";
	}
	if(a.isBetween(sagittarius, capricorn)){
		return "sagittarius";
	}
//	if(a.isBetween(capricorn, aquarius)){
	return "capricorn";
//	}
	
//	return "null";
}

int main(){
	int t, year, month, day, c=1;
	std::string dataset, y, m, d;
	ez_time eztime;
	std::cin >> t;

	while(t--){
		std::cin >> dataset;
		month = std::stoi(dataset.substr(0, 2)); day = std::stoi(dataset.substr(2, 2)); year = std::stoi(dataset.substr(4, 4));
		
		eztime.setTime(year, month, day, 1, 1, 1);
		eztime.addDays(280);
		
		m = eztime.Month() < 10 ? "0" : "";
		m += std::to_string(eztime.Month());
		y = eztime.Year() < 10 ? "0" : "";
		y += eztime.Year() < 100 ? "0" : "";
		y += eztime.Year() < 1000 ? "0" : "";
		y += std::to_string(eztime.Year());
		d = eztime.Day() < 10 ? "0" : "";
		d += std::to_string(eztime.Day());

		std::cout << c++ << " " << m << "/" << d << "/" << y << " " <<  getZodiac(eztime) <<  std::endl;
	}
}
