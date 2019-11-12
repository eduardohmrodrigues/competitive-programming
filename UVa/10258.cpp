#include <cstdio>
#include <iostream>
#include <numeric>
#include <map>
#include <vector>
#include <algorithm>

struct contestant{
	int id;
	int solved;
	int time;

	std::vector<int> problems;
	std::map<int, int> pending;
};

bool compare (const contestant &a, const contestant &b){
	if(a.solved > b.solved) return true;
	else if(a.solved < b.solved) return false;
	else if(a.time < b.time) return true;
	else if(a.time > b.time) return false;

	return a.id < b.id;
}


std::vector<std::string> split(std::string str, std::string delimiter){
	std::string s = str;
	std::vector<std::string> out;
	out.clear();

	size_t pos = 0;
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos) {
	    token = s.substr(0, pos);
	    out.push_back(token);
	    s.erase(0, pos + delimiter.length());
	}

	out.push_back(s);
	return out;
}

int main(){
	int t, id, problem, time;
	std::string str, stats;
	std::map<int, contestant> map;
	std::vector<contestant> vec;
	std::vector<std::string> splited;
	scanf("%d", &t);
	getchar();getchar();
	
	while(t--){
		map.clear();
		vec.clear();
		
		while(std::getline(std::cin, str) && str.compare("") != 0){
			splited.clear();
			splited = split(str, " ");
			
			id = std::stoi(splited[0]);
			problem = std::stoi(splited[1]);
			if(map.find(id) == map.end()) map[id] = contestant{.id = id, .solved = 0, .time = 0, .problems = std::vector<int>(0), .pending = std::map<int, int>()};
			if(std::find(map[id].problems.begin(), map[id].problems.end(), problem) != map[id].problems.end()) continue;
			
			if(splited[3].compare("C") == 0){
				time = std::stoi(splited[2]);
				map[id].time += time;
				if(map[id].pending.find(problem) != map[id].pending.end()) map[id].time += map[id].pending[problem];
				map[id].problems.push_back(problem);
				map[id].solved++;
			}else if(splited[3].compare("I") == 0){
				if(map[id].pending.find(problem) == map[id].pending.end()) map[id].pending[problem] = 0;
				map[id].pending[problem] += 20;
			}
		}
		
		for(std::map<int, contestant>::iterator it=map.begin(); it!=map.end(); ++it){
			vec.push_back(it->second);
		}
		
		std::sort(vec.begin(), vec.end(), compare);
		for(int i=0; i<vec.size(); i++){
			std::cout << vec[i].id << " " << vec[i].solved << " " << vec[i].time << std::endl;
		}

		if(t > 0) std::cout << std::endl;
	}

	return 0;
}
