#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

std::map<int, std::vector<std::vector<char>>> sequences;

std::string vectorToString(std::vector<char> s){
	std::string str = "";
	bool first = true;

	for(int i=0; i<s.size(); ++i){
		if(!first) str += " ";
		
		first = false;
		str += s[i];
	}

	return str;

}

bool isAnagram(std::string a, std::string b){
	std::string c = a, d = b;
	std::sort(c.begin(), c.end()); std::sort(d.begin(), d.end());
	
	return c.compare(d) == 0;
}

std::vector<std::string> getAnagrams(std::string from, std::string to){
	std::vector<std::string> out; out.clear();

	if(!isAnagram(from, to)) return out;
	std::stack<char> generated;
	std::vector<char> r; r.clear();
	std::string str;
	int index;

	for(int i=0; i<from.size(); ++i){
		r.push_back('i');
	}
	for(int i=0; i<from.size(); ++i){
		r.push_back('o');
	}

	if(sequences.find(from.size()) != sequences.end()){
		for(int i=0; i<sequences[from.size()].size(); i++){
			str = "";
			index = 0;
			std::stack<char> empty;
			generated.swap(empty);
			for(int j=0; j<sequences[from.size()][i].size(); j++){
				if(sequences[from.size()][i][j]=='i'){
					generated.push(from[index++]);
				}else if(sequences[from.size()][i][j]=='o' && generated.size() > 0){
					str += generated.top();
					generated.pop();
				}else{
					break;
				}
			}

			if(str.compare(to) == 0) out.push_back(vectorToString(sequences[from.size()][i]));
		}

	}else{
		sequences[from.size()] = std::vector<std::vector<char>>();

		do{
			if(r[0] == 'o') break;

			str = "";
			index = 0;
			std::stack<char> empty;
			generated.swap(empty);

			for(int i=0; i<r.size(); i++){
				if(i == r.size()-1){
					sequences[from.size()].push_back(r);
				}
				
				if(r[i]=='i'){
					generated.push(from[index++]);
				}else if(r[i]=='o' && generated.size() > 0){
					str += generated.top();
					generated.pop();
				}else{
					break;
				}
			}
			if(str.compare(to) == 0) out.push_back(vectorToString(r));
		}while(std::next_permutation(r.begin(), r.end()));
	}

	return out;
}

int main(){
	std::string from, to;
	std::vector<std::string> answer;
	sequences.clear();

	while(std::cin >> from){
		if(from.length() == 0) continue;
		answer.clear();

		do{
			std::cin >> to;
		}while(to.length() == 0);
		
		answer = getAnagrams(from, to);
		printf("[\n");
		for(int i=0; i<answer.size(); ++i){
			std::cout << answer[i] << std::endl;
		}
		printf("]\n");
	}

	return 0;
}
