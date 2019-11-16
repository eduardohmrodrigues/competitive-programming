#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>

void insertContainer(char c, std::vector<std::stack<char>> *vec){
	bool found = false;
	std::vector<int> diffs; diffs.clear();
	
	for(int i=0; i<vec->size() && !found; ++i){
		if((*vec)[i].top() == c){
			(*vec)[i].push(c);
			found = true;
		}else if((*vec)[i].top() > c){
			diffs.push_back(i);
		}
	}
	
	int index = -1, min = 9999;
	for(int i=0; i<diffs.size() && !found; ++i){
		if((*vec)[diffs[i]].top() - c < min){
			min = (*vec)[diffs[i]].top() - c;
			index = diffs[i];
		}
	}

	if(index != -1){
		(*vec)[index].push(c);
		found = true;
	}

	if(!found){
		vec->push_back(std::stack<char>());
		(*vec)[vec->size()-1].push(c);
	}
}

int main(){
	int c = 1;
	std::string str;
	std::vector<std::stack<char>> vec;
	char aux;
	bool found;

	while(std::getline(std::cin, str) && str.compare("end") != 0){
		vec.clear();

		for(int i=0; i<str.length(); ++i){
			aux = str[i];
			insertContainer(aux, &vec);
		}

		std::cout << "Case " << c++ << ": " << vec.size() << std::endl;
	}

	return 0;
}
