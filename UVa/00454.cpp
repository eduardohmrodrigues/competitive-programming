#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#define msvs std::map<std::string, std::vector<std::string>>
#define vvs std::vector<std::vector<std::string>>

void clear(msvs *map){
	for(msvs::iterator it = map->begin(); it != map->end(); ++it){
		it->second.clear();
	}

	map->clear();
}

void clear(vvs *vec){
	for(int i=0; i<vec->size(); ++i){
		(*vec)[i].clear();
	}

	vec->clear();
}

std::string removeSpaces(std::string str){
	std::string out = "";
	
	for(int i=0; i<str.length(); ++i){
		if(str[i] != ' ') out += str[i];
	}

	return out;
}

bool compare(std::vector<std::string> &a, std::vector<std::string> &b){
	std::vector<std::string> temp({a[0], b[0]});
	std::sort(temp.begin(), temp.end());
	
	if(temp[0].compare(a[0]) == 0){
		return true;
	}

	return false;
}

std::vector<std::string> processMap(msvs map){
	vvs vec;
	vec.clear();
	std::vector<std::string> vecstr;
	vecstr.clear();
		
	for(msvs::iterator it = map.begin(); it != map.end(); ++it){
		if(it->second.size()>1) {
			vec.push_back(it->second);
			std::sort(vec[vec.size()-1].begin(), vec[vec.size()-1].end());
		}
	}
//	std::sort(vec.begin(), vec.end(), compare);
		
	for(int i=0; i<vec.size(); i++){
		for(int j=0; j<vec[i].size(); ++j){
			for(int k=j+1; k<vec[i].size(); k++){
				vecstr.push_back(vec[i][j] + " = " + vec[i][k]);
			}
		}
	}
	//std::sort(vec.begin(), vec.end(), compare);
	std::sort(vecstr.begin(), vecstr.end());
	return vecstr;
}

int main(){
	int n;
	bool gotSomething;
	std::string line, aux;
	msvs map;
	std::vector<std::string> strings;
	scanf("%d%*c", &n);

	while(n--){
		clear(&map);
		strings.clear();
		gotSomething = false;
		while(std::getline(std::cin, line) && line.length() >= 1){
			gotSomething = true;
			aux = removeSpaces(line);
			std::sort(aux.begin(), aux.end());
			
			if(map.find(aux) == map.end()) map[aux] = std::vector<std::string>();
			map[aux].push_back(line);
		}
		
		if(gotSomething){
			strings = processMap(map);

			for(int i=0; i<strings.size(); i++){
				//for(int j=0; j<strings[i].size(); ++j){
				//	for(int k=j+1; k<strings[i].size(); k++){
				//		std::cout << strings[i][j] << " = " << strings[i][k] << std::endl;
				//	}
				//}
				std::cout << strings[i] << std::endl;
			}

			if(n-1>=0) std::cout << std::endl;
		}else{
			n++;
		}
	}

	return 0;
}
