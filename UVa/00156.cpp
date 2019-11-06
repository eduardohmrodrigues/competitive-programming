#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

std::vector<std::string> split(std::string str, std::string delimiter){
	std::string s = str;
	std::vector<std::string> out;
	out.clear();

	size_t pos = 0;
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos) {
	    token = s.substr(0, pos);
	    //std::cout << token << std::endl;
	    out.push_back(token);
	    s.erase(0, pos + delimiter.length());
	}
	out.push_back(s);
	//std::cout << s << std::endl;
	return out;
}

int main(){
	std::string str, aux;
	std::map<std::string, std::string> map;
	std::vector<std::string> line;

	while(std::getline(std::cin, str) && str.compare("#") != 0){
		line.clear();
		line = split(str, " ");
		
		for(int i=0; i<line.size(); i++){
			aux = line[i];
			std::transform(line[i].begin(), line[i].end(), line[i].begin(),
			    [](unsigned char c){ return std::tolower(c); });
			std::sort(line[i].begin(), line[i].end());
			
			if(map.find(line[i]) != map.end()){
				map[line[i]] = "#";
			}else{
				map[line[i]] = aux;
			}
		}
		
	}
	
	line.clear();
	for(std::map<std::string, std::string>::iterator it = map.begin(); it != map.end(); ++it){
		if(it->second != "#") line.push_back(it->second);
	}

	std::sort(line.begin(), line.end());
	for(int i=0; i<line.size(); i++) std::cout << line[i] << std::endl;

	return 0;
}
