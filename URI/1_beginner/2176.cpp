#include <iostream>

int main(){
	std::string s;
	int sum = 0, n;

	std::cin >> s;
	for(int i=0; i<s.length(); ++i){
		n = s[i]-'0';
		sum += (n > 0) ? 1 : 0;
	}

	if(sum%2 == 0) std::cout << s << "0" << std::endl;
	else std::cout << s << "1" << std::endl;

	return 0;
}
