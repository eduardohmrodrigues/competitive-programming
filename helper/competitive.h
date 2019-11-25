#ifndef COMPETITIVE_H
#define COMPETITIVE_H
#include <cstdio>
#include <ctime>
#include <string>
#include <vector>
#include <utility>

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

// Graphs
class adjacency_matrix{
private:
	std::vector<std::vector<int>> mat;
	int vertexCount;
	
	void clear_container(){
		for(int i=0; i<vertexCount; ++i){
			mat[i].clear();
		}

		mat.clear();
	}

public:
	adjacency_matrix(int v){
		vertexCount = v;
		mat = std::vector<std::vector<int>>(v, std::vector<int>(v, 0));
	}

	~adjacency_matrix(){
		clear_container();
	}

	void insert_edge(int src, int dest, int weight){
		mat[src][dest] = weight;
	}
	
	void clear(){
		for(int i=0; i<vertexCount; ++i){
			for(int j=0; j<vertexCount; ++j){
				mat[i][j] = 0;
			}
		}
	}

	void print(){
		for(int i=0; i<vertexCount; ++i){
			printf("|");
			for(int j=0; j<vertexCount; ++j){
				for(int k=100000; k>1; k/=10) if(mat[i][j] < k) printf(" ");
				printf("%d|", mat[i][j]);
			}
			printf("\n");
		}
	}
};

class adjacency_list{
private:
	std::vector<std::vector<std::pair<int, int>>> adlist;
	int vertexCount;

	void clear_container(){
		for(int i=0; i<vertexCount; ++i){
			adlist[i].clear();
		}

		adlist.clear();
	}

public:
	adjacency_list(int v){
		vertexCount = v;
		adlist = std::vector<std::vector<std::pair<int, int>>>(v);
	}

	~adjacency_list(){
		clear_container();
	}

	void insert_edge(int src, int dest, int weight){
//		if(src >= vertexCount || dest >= vertexCount) return;
		adlist[src].push_back(std::pair<int, int>(dest, weight));
	}

	void clear(){
		for(int i=0; i<vertexCount; ++i){
			adlist[i].clear();
		}
	}

	void print(){
		for(int i=0; i<vertexCount; ++i){
			if(adlist[i].size()>0){
				printf("%d: ", i);
				for(int j=0; j<adlist[i].size(); ++j){
					printf("(%d, %d) ", adlist[i][j].first, adlist[i][j].second);
				}
				printf("\n");
			}
		}
	}
};

class edge_list{
private:
	std::vector<std::pair<int, std::pair<int, int>>> elist;

public:
	edge_list(){
		elist = std::vector<std::pair<int, std::pair<int, int>>>();
		elist.clear();
	}

	~edge_list(){
		elist.clear();
	}

	void insert_edge(int src, int dest, int weight){
		elist.push_back(std::pair<int, std::pair<int, int>>(src, std::pair<int, int>(dest, weight)));
	}

	void print(){
		for(int i=0; i<elist.size(); ++i){
			printf("%d: v1: %d v2: %d w: %d\n", i, elist[i].first, elist[i].second.first, elist[i].second.second);
		}
	}
};

#endif
