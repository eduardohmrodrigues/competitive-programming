#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

class Compare{
public:
	bool operator() (const std::pair<int, std::pair<int, int>> &a, const std::pair<int, std::pair<int, int>> &b){
		if(a.first == b.first) return a.second.first > b.second.first;
		return a.first > b.first;
	}
};

int main(){
	std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>, Compare> queue;
	int id, period, rep, aux;
	std::pair<int, std::pair<int, int>> temp;
	std::string str;
	
	while(std::cin >> str && str[0] != '#'){
		std::cin >> id >> period;
		queue.push(std::pair<int, std::pair<int, int>>(period, std::pair<int, int>(id, period)));
	}

	std::cin >> rep;
	
	aux = 0;
	while(aux<rep){
		temp = queue.top();
		queue.pop();

		printf("%d\n", temp.second.first);
		queue.push(std::pair<int, std::pair<int, int>>(temp.first+temp.second.second, temp.second));
		aux++;
	}

	return 0;
}
