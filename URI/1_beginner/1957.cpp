#include <iostream>
#include <sstream>

int main(){
	int i;
	std::stringstream ss;
	std::string str;

	scanf("%d", &i);
	ss << std::hex << i;
	str = ss.str();

	for(int i=0; i<str.length(); ++i){
		std::cout << ((char)std::toupper(str[i]));
	}
	std::cout << std::endl;

	return 0;
}
