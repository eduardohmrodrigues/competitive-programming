#include <iostream>
#include <cstdio>
#include <map>

int main(){
	std::map<std::string, std::string> lang;
	lang["HELLO"] = "ENGLISH";
	lang["HOLA"] = "SPANISH";
	lang["HALLO"] = "GERMAN";
	lang["BONJOUR"] = "FRENCH";
	lang["CIAO"] = "ITALIAN";
	lang["ZDRAVSTVUJTE"] = "RUSSIAN";

	std::string g;
	int c = 1;

	while(std::cin >> g && g.compare("#") != 0){
		if(lang.find(g) != lang.end()){
			std::cout << "Case " << c << ": " << lang[g] << std::endl;
		}else{
			std::cout << "Case " << c << ": " << "UNKNOWN" << std::endl;
		}

		c++;
	}

	return 0;
}
