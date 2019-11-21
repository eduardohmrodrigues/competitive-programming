#include <cstdio>
#include <iostream>
#include <map>

int main(){
	std::map<std::string, double> map;
	int c;
	double totalTrees;
	std::string str;
	scanf("%d\n", &c);
	
	while(c--){
		map.clear();
		totalTrees = 0.0;

		while(std::getline(std::cin, str) && str.length() > 0){
			if(map.find(str) == map.end()) map[str] = 0.0;
			map[str]++;
			totalTrees++;
		}

		for(std::map<std::string, double>::iterator it=map.begin(); it != map.end(); ++it){
			std::cout << it->first << " ";
			printf("%.4lf\n", (100*it->second/totalTrees));
		}

		if(c > 0) printf("\n");
	}
	
	return 0;
}
