#include <cstdio>
#include <iostream>

int main(){
	std::string str;
	while(std::getline(std::cin, str) && str.compare("DONE") != 0){
		for(int i=0; i<str.length(); ++i){
			if(str[i] > 64 && str[i] < 91){
				str[i] += 32;
			}else if(str[i] < 97 || str[i] > 122){
				str.erase(i, 1);
				--i;
			}
		}
		
		bool palindrome = true;
		for(int i=0, j=str.length()-1; i<str.length()/2 && palindrome; ++i, --j){
			palindrome &= str[i] == str[j];
		}
		
		if(palindrome) printf("You won't be eaten!\n");
		else printf("Uh oh..\n");
	}

	return 0;
}
