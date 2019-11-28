#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

bool impossible(std::vector<std::vector<int>> conn){
	bool impossible = false;
	for(int i=3; i<conn.size() && !impossible; ++i){
		impossible = conn[i].size() < 3;
	}

	return impossible;
}

bool can_activate(int ind, std::vector<std::vector<int>> connections, std::vector<bool> awake){
	if(connections[ind].size() < 2) return false;

	int activeCounter = 0;
	for(int i=0; i<connections[ind].size() && activeCounter < 3; i++){
		if(awake[connections[ind][i]]) activeCounter++;
	}

	return activeCounter >= 3;
}

int main(){
	int n, m, years, aux;
	bool finished;
	std::string line;
	std::map<char, int> map;
	std::vector<bool> awake;
	std::vector<int> swap;
	std::vector<std::vector<int>> connections;

	while(scanf("%d", &n) != EOF){
		map.clear();
		swap.clear();
		awake.assign(n, false);
		connections.assign(n, std::vector<int>(0));
		years = 0; finished = false;

		scanf("%d", &m);
		aux = m;
		std::cin >> line;
		
		map[line[0]] = 0; map[line[1]] = 1; map[line[2]] = 2;
		awake[0] = true; awake[1] = true; awake[2] = true;
		connections[0].push_back(1); connections[0].push_back(2);
		connections[1].push_back(0); connections[1].push_back(2);
		connections[2].push_back(0); connections[2].push_back(1);

		while(aux--){
			std::cin >> line;

			if(map.find(line[0]) == map.end()) map[line[0]] = map.size();
			if(map.find(line[1]) == map.end()) map[line[1]] = map.size();

			connections[map[line[0]]].push_back(map[line[1]]);			
			connections[map[line[1]]].push_back(map[line[0]]);
		}
		
		if(impossible(connections) && (m > 0 || m == 0 && n > 3)){
			printf("THIS BRAIN NEVER WAKES UP\n");
			std::getline(std::cin, line);
			continue;
		}

		while(!finished && m > 0){
			swap.clear();
			finished = true;
			for(int i=3; i<awake.size(); ++i){
				finished &= awake[i];
				if(!awake[i] && can_activate(i, connections, awake)) swap.push_back(i);
			}

			if(finished){
				continue;
			}else if(swap.size() == 0){
				years = -1;
				finished = true;
			}else{
				++years;
			}

			while(swap.size() > 0){
				awake[swap[0]] = true;
				swap.erase(swap.begin());
			}
		}


		if(years >= 0) printf("WAKE UP IN, %d, YEARS\n", years);
		else printf("THIS BRAIN NEVER WAKES UP\n");
		std::getline(std::cin, line);
	}

	return 0;
}
