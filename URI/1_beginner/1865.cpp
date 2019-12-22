#include <cstdio>
#include <iostream>

int main(){
	int c, n;
	std::string name;
	std::cin >> c;

	while(c--){
		std::cin >> name >> n;

		if(name.compare("Thor") == 0) printf("Y\n");
		else printf("N\n");
	}

	return 0;
}
