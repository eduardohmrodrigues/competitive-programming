#include <cstdio>
#include <iostream>
#include <cmath>

int main(){
	int x, y;
	std::string s1, s2;
	std::cin >> s1 >> s2;
	
	x = std::abs(s1[0] - s2[0]);
	y = std::abs((s1[1]-'0') - (s2[1]-'0'));
	
	if(x == 1 && y == 2 || x == 2 && y == 1) printf("VALIDO\n");
	else printf("INVALIDO\n");

	return 0;
}
