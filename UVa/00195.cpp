#include <cstdio>
#include <iostream>
#include <algorithm>

bool comparator(char a, char b){
	if(tolower(a) == tolower(b)){
		return a<b;
	}
	return tolower(a) < tolower(b);
}

int main(){
	int n;
	std::string line;

	scanf("%d%*c", &n);
	while(n--){
		std::getline(std::cin, line);
		std::sort(line.begin(), line.end(), comparator);

		do{
			std::cout << line << std::endl;
		}while(std::next_permutation(line.begin(), line.end(), comparator));
	}

	return 0;
}
