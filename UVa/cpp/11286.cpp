#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>

int main(){
	std::map<std::string, int> map;
	int n, counter;
	std::string courses[5], key;
	

	while(scanf("%d", &n) != EOF && n > 0){
		map.clear();

		for(int i=0; i<n; ++i){
			std::cin >> courses[0] >> courses[1] >> courses[2] >> courses[3] >> courses[4];
			std::sort(courses, courses+5);
			key = courses[0] + " " + courses[1] + " " + courses[2] + " " + courses[3] + " " + courses[4];
			if(map.find(key) == map.end()) map[key] = 0;
			map[key]++;
		}
		
		key = map.begin()->first;
		counter = 0;
		for(std::map<std::string, int>::iterator it=map.begin(); it!=map.end(); ++it){
			if(it->second > map[key]) {
				key = it->first;
				counter = it->second;
			}else if(it->second == map[key]){
				counter += it->second;
			}
		}

		printf("%d\n", counter);
	}

	return 0;
}
