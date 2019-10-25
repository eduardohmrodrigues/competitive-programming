#include <iostream>

int main(){
	std::string s1, s2, s3;
	std::cin >> s1;
	std::cin >> s2;
	std::cin >> s3;

	if(s1.compare("vertebrado") == 0){
		if(s2.compare("ave") == 0){
			if(s3.compare("carnivoro") == 0){
				printf("aguia\n");
			}else{
				printf("pomba\n");
			}
		}else{
			if(s3.compare("onivoro") == 0){
				printf("homem\n");
			}else{
				printf("vaca\n");
			}
		}
	}else{
		if(s2.compare("inseto") == 0){
			if(s3.compare("hematofago") == 0){
				printf("pulga\n");
			}else{
				printf("lagarta\n");
			}
		}else{
			if(s3.compare("hematofago") == 0){
				printf("sanguessuga\n");
			}else{
				printf("minhoca\n");
			}
		}
	}

	return 0;
}
