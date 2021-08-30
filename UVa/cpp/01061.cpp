#include <cstdio>
#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::map<std::string, std::string> donations = {{"O", "O"}, {"AB", "AB"}, {"B", "BO"},  {"A", "AO"}};
std::map<std::string, std::string> type = {{"AA", "A"}, {"AB", "AB"}, {"BA", "AB"}, {"AO", "A"}, {"OA", "A"},  {"BB", "B"}, {"BO", "B"}, {"OB", "B"}, {"OO", "O"}};

std::vector<std::string> getPossibleBloods(std::string blood1, std::string blood2){
	std::string d1 = donations[blood1.substr(0, blood1.length()-1)];
	std::string d2 = donations[blood2.substr(0, blood2.length()-1)];
	std::string aux;
	std::vector<std::string> possibilities, out;
	possibilities.clear(); out.clear();

	for(int i=0; i<d1.length(); i++){
		for(int j=0; j<d2.length(); j++){
			aux = std::string(1, d1[i]);
			aux.push_back(d2[j]);
			aux = type[aux];
			
			if(std::find(possibilities.begin(), possibilities.end(), aux) == possibilities.end()) possibilities.push_back(aux);
		}
	}

	return possibilities;
}

std::vector<std::string> mixBlood(std::string blood1, std::string blood2){
	std::vector<std::string> possibleBloods = getPossibleBloods(blood1, blood2);
	bool rh1 = blood1[blood1.length()-1] == '+';
	bool rh2 = blood2[blood2.length()-1] == '+';
	
	std::vector<std::string> out; out.clear();
	for(int i=0; i<possibleBloods.size(); i++){
		if(!rh1 && !rh2){
			out.push_back(possibleBloods[i] + "-");
		}else{
			out.push_back(possibleBloods[i] + "-");
			out.push_back(possibleBloods[i] + "+");
		}
	}

	return out;
}

std::vector<std::string> findParent(std::string parentBlood, std::string child){
	std::vector<std::string> generated; generated.clear();
	std::vector<std::string> possibleParents; possibleParents.clear();

	for(std::map<std::string, std::string>::iterator it=donations.begin(); it != donations.end(); ++it){
		generated = mixBlood(parentBlood, it->first+"-");
		if(std::find(generated.begin(), generated.end(), child) != generated.end()) possibleParents.push_back(it->first+"-");

		generated = mixBlood(parentBlood, it->first+"+");
		if(std::find(generated.begin(), generated.end(), child) != generated.end()) possibleParents.push_back(it->first+"+");
	}

	return possibleParents;
}

std::string toString(std::vector<std::string> bloods){
	if(bloods.size() == 0) return "IMPOSSIBLE";

	std::string out = bloods.size() > 1 ? "{" : "";
	for(int i=0; i<bloods.size(); i++){
		if(i>0) out += ", ";
		out += bloods[i];
	}

	if(bloods.size() > 1) out += "}";
	return out;
}

int main(){
	std::string b1, b2, b3;
	int c = 1;

	while(std::cin >> b1 >> b2 >> b3 && b1.compare("E") != 0){
		if(b3.compare("?") == 0){
			b3 = toString(mixBlood(b1, b2));
		}else if(b1.compare("?") == 0){
			b1 = toString(findParent(b2, b3));
		}else{
			b2 = toString(findParent(b1, b3));
		}

		std::cout << "Case " << c++ << ": " << b1 << " " << b2 << " " << b3 << std::endl;
	}

	return 0;
}
