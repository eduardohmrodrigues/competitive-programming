#include <cstdio>
#include <iostream>
#include <list>

int main(){
	std::list<char> text;
	std::list<char>::iterator it;
	std::string str;

	while(std::getline(std::cin, str)){
		text.clear();
		it = text.begin();
		
		for(int i=0; i<str.length(); i++){
			if(str[i] == '['){
				it = text.begin();
			}else if(str[i] == ']'){
				if(text.size() > 0){
					it = text.end();
				}
			}else{
				text.insert(it, str[i]);
			}
		}

		for(it = text.begin(); it!=text.end(); ++it){
			std::cout << (*it);
		}
		std::cout << std::endl;
	}

	return 0;
}
