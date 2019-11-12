#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

int main(){
	std::string str;

	while(std::cin >> str && str.compare("#") != 0){
		if(std::next_permutation(str.begin(), str.end())){
			std::cout << str << std::endl;
		}else{
			std::cout << "No Successor" << std::endl;
		}
	}

	return 0;
}
