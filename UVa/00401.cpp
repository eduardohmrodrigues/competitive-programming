#include <cstdio>
#include <iostream>
#include <map>

int main(){
	std::map<char, char> reverses = {{'A', 'A'}, {'E', '3'}, {'3', 'E'}, {'H', 'H'}, {'I', 'I'}, {'J', 'L'}, {'L', 'J'},
						       {'M', 'M'}, {'O', 'O'}, {'S', '2'}, {'2', 'S'}, {'T', 'T'}, {'U', 'U'}, {'V', 'V'},
						       {'W', 'W'}, {'X', 'X'}, {'Y', 'Y'}, {'Z', '5'}, {'5', 'Z'}, {'1', '1'}, {'8', '8'}};

	std::string str, reverse, mirror;
	bool palindrome, mirrored;

	while(std::getline(std::cin, str)){
		reverse = ""; mirror = "";

		for(int i=str.length()-1; i>=0; --i){
			//int curr = str.length()-(i+1);
			reverse += str[i];
			if(reverses.find(str[i]) != reverses.end()){
				mirror += reverses[str[i]];
			}
		}

		palindrome = str.compare(reverse) == 0;
		mirrored = str.compare(mirror) == 0;
//		std::cout << str << " | pal: " << reverse << " | mir: " << mirror << std::endl;
		if(palindrome && mirrored){
			std::cout << str << " -- is a mirrored palindrome." << std::endl;
		}else if(palindrome){
			std::cout << str << " -- is a regular palindrome." << std::endl;
		}else if(mirrored){
			std::cout << str << " -- is a mirrored string." << std::endl;
		}else{
			std::cout << str << " -- is not a palindrome." << std::endl;
		}
		std::cout << std::endl;
	}

	return 0;
}
