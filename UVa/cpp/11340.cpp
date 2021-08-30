#include <cstdio>
#include <iostream>

void clear(double price[256]){
	for(int i=0; i<256; i++){
		price[i] = 0;
	}
}

int main(){
	double price[256], value;
	int n, k, m;
	char c;
	std::string str;

	std::cin >> n;
	while(n--){
		clear(price);
		std::cin >> k;
		while(k--){
			std::cin >> c >> value;
			price[c] = value;
		}
		
		scanf("%d%*c", &m);
		value = 0;
		while(m--){
			std::getline(std::cin, str);
			for(int i=0; i<str.length(); i++){
				value += price[str[i]];	
			}
		}

		printf("%.2lf$\n", value/100.0);
	}

	return 0;
}
